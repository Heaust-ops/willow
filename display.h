
#pragma once

#include "SDL2/SDL.h"
#include <string>
#include <iostream>


class display  
{
	public:
		void Display(int width, int height, const std::string&title);
		void Update();
		bool IsClosed();
		virtual ~display();
	private:
	Display(const Display& other) {}
	Display& operator=(const Display& other) {}

	SDL_Window* m_window;
	SDL_GLContext m_glContext;

	bool isClosed;




};