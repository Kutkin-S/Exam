/*
 * ExampleWindow.h
 *
 *  Created on: 19 РѕРєС‚. 2020 Рі.
 *      Author: unyuu
 */

#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

// Объявление класса ExampleWindow как потомка Window
class ExampleWindow: public Window
{
public:
	static constexpr int DEFAULT_WIDTH = 1920;
	static constexpr int DEFAULT_HEIGHT = 1080;

protected:
	double _angle; // Угол поворота модели
	double _eye_level; // Высота уровня глаз

public:

	// Конструктор класса ExampleWindow
	ExampleWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);

// Деструктор класса ExampleWindow
	virtual ~ExampleWindow() = default;

		// Метод начальной настройки окна
	virtual void setup() override;

	// Метод отрисовки окна
	virtual void render() override;

	// Метод обработки логики
	virtual void handle_logic() override;
};




#endif /* EXAMPLEWINDOW_H_ */
