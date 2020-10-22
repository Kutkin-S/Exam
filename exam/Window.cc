/*
 * Window.cc
 *
 *  Created on: 14 окт. 2020 г.
 *      Author: unyuu
 */

#include <stdexcept>

#include "Window.h"

Window::Window(int width, int height)
: _width(width), _height(height)
{
	// Создание окна
	_window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
					"OpenGL Window",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					width, height,
					SDL_WINDOW_SHOWN |
					SDL_WINDOW_OPENGL),
			SDL_DestroyWindow);
	if (_window == nullptr) // Если не создалось...
		throw std::runtime_error(
				std::string("Ошибка при создании окна: ") +
				std::string(SDL_GetError()));

	// Выбор версии контекста OpenGL
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	// Создание контекста
	_gl_context = std::shared_ptr<void>(
			SDL_GL_CreateContext(_window.get()),
			SDL_GL_DeleteContext);
	if (_gl_context == nullptr) // Если не создался...
		throw std::runtime_error(
				std::string("Ошибка при создании контекста OpenGL: ") +
				std::string(SDL_GetError()));
}

void Window::main_loop()
{
	setup();

	SDL_Event event;
	auto keys = SDL_GetKeyboardState(nullptr);  // ������ �����?
	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				return;
			handle_event(event);
		}
		handle_keys(keys);



		handle_logic();

		render();
		SDL_GL_SwapWindow(_window.get());
	}

}


