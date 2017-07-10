#include "Graphics.hpp"
#include <iostream>

Graphics::Graphics(void)
{
	glib_action = NONE;

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

	// Create an application win with the following settings:
	_win = SDL_CreateWindow(
	    "Nibbler",							// _win title
	    SDL_WINDOWPOS_UNDEFINED,			// initial x position
	    SDL_WINDOWPOS_UNDEFINED,			// initial y position
	    WIDTH * REALWIDTHMULT,				// width, in pixels
	    HEIGHT * REALHEIGHTMULT,			// height, in pixels
	    SDL_WINDOW_OPENGL					// flags
	);

	_renderer = SDL_CreateRenderer(_win, -1, SDL_RENDERER_SOFTWARE);

	// Check that the _win was successfully created
	if (_win == NULL) {
	    // In the case that the _win could not be made...
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
	    return ;
	}
	return ;
}

Graphics::Graphics(Graphics const & src)
{
	*this = src;
	return ;
}

Graphics::~Graphics(void)
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_win);
    SDL_Quit();
	return ;
}

void Graphics::handleEvents(void)
{
	SDL_PollEvent(&_event);
	switch (_event.type)
	{
		case SDL_KEYDOWN:
			switch (_event.key.keysym.sym)
			{
				case SDLK_2:
					glib_action = LIB2;
					break;
				case SDLK_3:
					glib_action = LIB3;
					break;
				case SDLK_w:
					glib_action = UP;
					break;
				case SDLK_a:
					glib_action = LEFT;
					break;
				case SDLK_s:
					glib_action = DOWN;
					break;
				case SDLK_d:
					glib_action = RIGHT;
					break;
				case SDLK_ESCAPE:
					glib_action = QUIT;
					break;
			}
			break;
	}
}

void Graphics::drawMap(void)
{
	int y = 0;

	SDL_RenderClear(_renderer);

	for (std::list<std::list<t_blocks>>::iterator itr = map.begin(); itr != map.end(); itr++, y++)
	{
		std::list<t_blocks> tl = *itr;
		int x = 0;

		for (std::list<t_blocks>::iterator it = tl.begin(); it != tl.end(); it++, x++)
		{
			char r = 0, g = 0, b = 0;
			switch (*it)
			{
				case BLKNONE:
					r = 0; g = 0; b = 0;
					break;
				case WALL:
					r = 255; g = 0; b = 0;
					break;
				case HEAD:
					r = 0; g = 255; b = 0;
					break;
				case BODY:
					r = 0; g = 0; b = 255;
					break;
				case FRUIT:
					r = 255; g = 255; b = 255;
					break;
			}
			SDL_SetRenderDrawColor(_renderer, r, g, b, 0);
			for (int y1 = y * REALHEIGHTMULT; y1 < (y + 1) * REALHEIGHTMULT; y1++)
				for (int x1 = x * REALWIDTHMULT; x1 < (x + 1) * REALWIDTHMULT; x1++)
					SDL_RenderDrawPoint(_renderer, x1, y1);
		}
	}
	SDL_RenderPresent(_renderer);
}

void Graphics::update(void)
{
	handleEvents();
	drawMap();
}

Graphics & Graphics::operator=(Graphics const & rhs)
{
	glib_action = rhs.glib_action;
	return *this;
}

Graphics	*glibInstantiate()
{
	return new Graphics();
}

void		glibUninstantiate(IGraphics * g)
{
	delete g;
}
