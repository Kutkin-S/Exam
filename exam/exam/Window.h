/*
 * Window.h
 *
 *  Created on: 14 окт. 2020 г.
 *      Author: unyuu
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <memory>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Window
{
public:
	// Размеры окна по-умолчанию
	static constexpr int DEFAULT_WIDTH = 1920;
	static constexpr int DEFAULT_HEIGHT = 1080;
protected:
	// Указатель на окно SDL
	std::shared_ptr<SDL_Window> _window;
	// Указатель на контекст OpenGL
	std::shared_ptr<void> _gl_context;

	// Ширина и высота окна
	int _width, _height;
public:
	// Конструктор класса Window
	Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	// Деструктор класса Window
	virtual ~Window() = default;

	// Геттер для ширины окна
	int width() const { return _width; }
	// Геттер для высоты окна
	int height() const { return _height; }

	// 	Основной цикл
	void main_loop();

	// Метод начальной настройки окна
	virtual void setup() { }

	// Метод отрисовки окна
	virtual void render() { }

	// Метод обработки событий
	virtual void handle_event(SDL_Event &event) { }

	// Метод обработки клавиш
	virtual void handle_keys(const Uint8 * keys) { }

	// Метод обработки логики
	virtual void handle_logic() { }
};


#endif /* WINDOW_H_ */
