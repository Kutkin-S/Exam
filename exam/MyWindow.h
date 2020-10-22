/*
 * MyWindow.h
 *
 *  Created on: 22 окт. 2020 г.
 *      Author: ksa44
 */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "Window.h"


class MyWindow: public Window
{
	double _houseWidth;
	double _houseLength;
	double _houseHeight;

public:
	static constexpr int DEFAULT_WIDTH = 800;
	static constexpr int DEFAULT_HEIGHT = 600;

protected:
	double _angle;
	double _eye_level;
	bool _isHeight = false;
	bool _isWidth = false;
	bool _isLength = false;

public:


	MyWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);


	virtual ~MyWindow() = default;


	virtual void setup() override;


	virtual void render() override;


	virtual void handle_logic() override;


	virtual void handle_keys(const Uint8 * keys) override;
};




#endif /* MYWINDOW_H_ */
