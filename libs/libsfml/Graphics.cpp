#include "Graphics.hpp"

Graphics::Graphics(void)
{
	return ;
}

Graphics::Graphics(int w, int h)
{
	glib_action = NONE;

	(void)w;
	(void)h;

	_win = new sf::RenderWindow(sf::VideoMode(800, 600), "Nibbler");
	return ;
}

Graphics::Graphics(Graphics const & src)
{
	*this = src;
	return ;
}

Graphics::~Graphics(void)
{
	_win->close();
	return ;
}

void Graphics::handleEvents(void)
{
	sf::Event	ev;

	if (_win->pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			glib_action = QUIT;
		else if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::Escape)
				glib_action = QUIT;
			else if (ev.key.code == sf::Keyboard::Num1)
				glib_action = LIB1;
			else if (ev.key.code == sf::Keyboard::Num2)
				glib_action = LIB2;
			else if (ev.key.code == sf::Keyboard::W)
				glib_action = UP;
			else if (ev.key.code == sf::Keyboard::S)
				glib_action = DOWN;
			else if (ev.key.code == sf::Keyboard::A)
				glib_action = LEFT;
			else if (ev.key.code == sf::Keyboard::D)
				glib_action = RIGHT;
		}
	}
}

void Graphics::drawMap(void)
{
	// sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

	// _win->clear();
	// _win->display();
	// _win.draw(shape);
	// _win.display();

	// int y = 0;

	// SDL_RenderClear(_renderer);

	// for (std::list<std::list<t_blocks>>::iterator itr = map.begin(); itr != map.end(); itr++, y++)
	// {
	// 	std::list<t_blocks> tl = *itr;
	// 	int x = 0;

	// 	for (std::list<t_blocks>::iterator it = tl.begin(); it != tl.end(); it++, x++)
	// 	{
	// 		char r = 0, g = 0, b = 0;
	// 		switch (*it)
	// 		{
	// 			case BLKNONE:
	// 				r = 0; g = 0; b = 0;
	// 				break;
	// 			case WALL:
	// 				r = 255; g = 0; b = 0;
	// 				break;
	// 			case HEAD:
	// 				r = 0; g = 255; b = 0;
	// 				break;
	// 			case BODY:
	// 				r = 0; g = 0; b = 255;
	// 				break;
	// 			case FRUIT:
	// 				r = 255; g = 255; b = 255;
	// 				break;
	// 		}
	// 		SDL_SetRenderDrawColor(_renderer, r, g, b, 0);
	// 		for (int y1 = y * REALHEIGHTMULT; y1 < (y + 1) * REALHEIGHTMULT; y1++)
	// 			for (int x1 = x * REALWIDTHMULT; x1 < (x + 1) * REALWIDTHMULT; x1++)
	// 				SDL_RenderDrawPoint(_renderer, x1, y1);
	// 	}
	// }
	// SDL_RenderPresent(_renderer);
}

void Graphics::update(void)
{
	// if (_win->isOpen())
	// {
	 	handleEvents();
		// drawMap();
	// }
}

Graphics & Graphics::operator=(Graphics const & rhs)
{
	glib_action = rhs.glib_action;
	return *this;
}

Graphics	*glibInstantiate(int w, int h)
{
	return new Graphics(w, h);
}

void		glibUninstantiate(IGraphics * g)
{
	delete g;
}
