/*
 * ExampleWindow.cc
 *
 *  Created on: 19 РѕРєС‚. 2020 Рі.
 *      Author: unyuu
 */
// закоментить


#include <cmath> //включение библиотеки cmath ( Математическая библиотека)

static constexpr double Pi = acos(-1.); //опеределение Пи через арккосинус -1

#include "ExampleWindow.h" //

ExampleWindow::ExampleWindow(int width, int height) // Задает ExampleWindow как член класса ExampleWindow
: Window(width, height)							//	 передает внутрь функции высоту, ширину
{
	_angle = 0.; 	//Угол поворота модели
	_eye_level = 0.; // Высота уровня глаз
}

// Цвета CMYK и RBG
static const float s_material_red[4]     { 1.f, 0.f, 0.f, 1.f };
static const float s_material_green[4]   { 0.f, 1.f, 0.f, 1.f };
static const float s_material_blue[4]    { 0.f, 0.f, 1.f, 1.f };
static const float s_material_cyan[4]    { 0.f, 1.f, 1.f, 1.f };
static const float s_material_magenta[4] { 1.f, 0.f, 1.f, 1.f };
static const float s_material_yellow[4]  { 1.f, 1.f, 0.f, 1.f };


void ExampleWindow::setup() //использование метода начальной настройки окна класса ExampleWindow
{
	glEnable(GL_DEPTH_TEST); // Включаем тест глубины
	glEnable(GL_LIGHTING); // Разрешение текущей освещенности
	glEnable(GL_LIGHT0); // Включение GL_LIGHT0 источник света
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f); //задаеться цветовой параметр фона изображения
	glMatrixMode(GL_PROJECTION);  // Выбор матрицы проекции
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0); // установка перспективы
	glMatrixMode(GL_MODELVIEW); // Выбор матрицы просмотра модели
}

void ExampleWindow::render() //отрисовка окна
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очистка Экрана и буфера глубины

	glLoadIdentity();   // Сброс матрицы проекции
	gluLookAt(
			5., 5., 5. * _eye_level, // отдаление кубика
			0., 0., 0.,
			0., 0., 1.);


	glRotated(_angle, 0, 0., 1.);

	//glRotated(j,x0,y0,z0)
	//поворачивает на угол j против часовой стрелки вокруг вектора (x0,y0,z0).



	glBegin(GL_QUADS); //определяет границы, внутри которых заданы вершины примитива или группы примитивов, рисовка примитива куба
	//GL_QUADS Каждые четыре вершины определяют четырёхугольник. Вершины 4n−3, 4n−2, 4n−1 и 4n определяют n-й четырёхугольник. Всего нарисуется N/4 четырёхугольника.

		glNormal3d(  1.,  0.,  0.); //задается нормаль с координатами 1,0,0
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_red); //задается материал: всей плоскости, цвет диффузного света, цвет
		glVertex3d(  1., -1.,  1.); //устанавливает точки на плоскости расположения на плоскости
		glVertex3d(  1.,  1.,  1.);
		glVertex3d(  1.,  1., -1.);
		glVertex3d(  1., -1., -1.);

		glNormal3d( -1.,  0.,  0.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_cyan);
		glVertex3d( -1.,  1.,  1.);
		glVertex3d( -1., -1.,  1.);
		glVertex3d( -1., -1., -1.);
		glVertex3d( -1.,  1., -1.);

		glNormal3d(  0.,  1.,  0.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
		glVertex3d( -1.,  1.,  1.);
		glVertex3d(  1.,  1.,  1.);
		glVertex3d(  1.,  1., -1.);
		glVertex3d( -1.,  1., -1.);

		glNormal3d(  0., -1.,  0.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_magenta);
		glVertex3d(  1., -1.,  1.);
		glVertex3d( -1., -1.,  1.);
		glVertex3d( -1., -1., -1.);
		glVertex3d(  1., -1., -1.);

		glNormal3d(  0.,  0.,  1.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);
		glVertex3d( -1.,  1.,  1.);
		glVertex3d(  1.,  1.,  1.);
		glVertex3d(  1., -1.,  1.);
		glVertex3d( -1., -1.,  1.);

		glNormal3d(  0.,  0., -1.);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_yellow);
		glVertex3d(  1.,  1., -1.);
		glVertex3d( -1.,  1., -1.);
		glVertex3d( -1., -1., -1.);
		glVertex3d(  1., -1., -1.);

		glEnd();  //конец рисования
}

void ExampleWindow::handle_logic()
{
	_angle += 1.;
	if (_angle >= 360.) // логика поворота
		_angle -= 360.;

	_eye_level = sin(_angle / 180. * Pi); // задание логики вращения/ раскачивания
}
