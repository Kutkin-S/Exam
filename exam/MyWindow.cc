/*
 * MyWindow.cc
 *
 *  Created on: 22 окт. 2020 г.
 *      Author: ksa44
 */

#include <conio.h>
#include <stdio.h>
#include <cmath>

static constexpr double Pi = acos(-1.);

#include "MyWindow.h"

MyWindow::MyWindow(int width, int height)
: Window(width, height)
{
	_angle = 0.;
	_eye_level = 0.;
	_houseWidth = 1.;
	_houseLength = 1.;
	_houseHeight = 1.;
}

static const float s_material_walls[4]   { 0.5f, 0.4f, 0.2f, 1.f };
static const float s_material_floor[4]   { 0.2f, 0.2f, 0.2f, 1.f };
static const float s_material_roof[4]    { 0.5f, 0.4f, 0.2f, 1.f };

void MyWindow::setup()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void MyWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(
			5., 5., 5. * _eye_level,
			0., 0., 0.,
			0., 0., 1.);

	glRotated(_angle, 0., 0., 1.);

	glScaled(_houseWidth, _houseLength, _houseHeight);

	glBegin(GL_QUADS);

	glNormal3d(  1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_walls);
	glVertex3d(  1., -1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1.,  1., -1.);
	glVertex3d(  1., -1., -1.);

	glNormal3d( -1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_walls);
	glVertex3d( -1.,  1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d( -1.,  1., -1.);

	glNormal3d(  0.,  1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_walls);
	glVertex3d( -1.,  1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1.,  1., -1.);
	glVertex3d( -1.,  1., -1.);

	glNormal3d(  0., -1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_walls);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d(  1., -1., -1.);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_AMBIENT, GL_AMBIENT, s_material_roof);
	glVertex3d( 0.,  1.,  1.9);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( 0., -1.,  1.9);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_AMBIENT, GL_AMBIENT, s_material_roof);
	glVertex3d( 0.,  1.,  1.9);
	glVertex3d(  -1.,  1.,  1.);
	glVertex3d(  -1., -1.,  1.);
	glVertex3d( 0., -1.,  1.9);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_AMBIENT, GL_DIFFUSE, s_material_roof);
	glVertex3d( 0.,  -1.,  1.9);
	glVertex3d(  -1.,  -1.,  1.);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( 0.,  -1.,  1.9);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_AMBIENT, GL_DIFFUSE, s_material_roof);
	glVertex3d( 0.,  1., 1.9);
	glVertex3d( 1.,  1., 1.);
	glVertex3d( -1., 1., 1.);
	glVertex3d( 0.,  1., 1.9);

	glNormal3d(  0.,  0., -1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_floor);
	glVertex3d(  1.,  1., -1.);
	glVertex3d( -1.,  1., -1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d(  1., -1., -1.);

	glEnd();
}


void MyWindow::handle_logic()
{

}
void MyWindow::handle_keys(const Uint8 * keys)
{
	if (keys[SDL_SCANCODE_LEFT]) {
		_angle -= 1/2.;
			if (_angle >= 360.)
				_angle -= 360.;

			_eye_level = sin(_angle / 180. * Pi);
	}

	if (keys[SDL_SCANCODE_RIGHT]) {
		_angle += 1/2.;
			if (_angle >= 360.)
				_angle -= 360.;

			_eye_level = sin(_angle / 180. * Pi);

	}

	if (keys[SDL_SCANCODE_H]) {
		_houseHeight = _houseHeight + 1. / 400.;
	} else {
		if (_houseHeight > 1.) {
			_houseHeight = _houseHeight - 1. / 400.;
		}
	}

	if (keys[SDL_SCANCODE_W]) {
		_houseWidth = _houseWidth + 1. / 400.;
	} else {
		if (_houseWidth > 1.) {
			_houseWidth = _houseWidth - 1. / 400.;
		}
	}

	if (keys[SDL_SCANCODE_L]) {
		_houseLength = _houseLength + 1. / 400.;
	} else {
		if (_houseLength > 1.) {
			_houseLength = _houseLength - 1. / 400.;
		}
	}
}

