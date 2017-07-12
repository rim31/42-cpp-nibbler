/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:54:57 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/12 14:56:38 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics.hpp"
#include <iostream>

Graphics::Graphics(void)
{
	return ;
}

Graphics::Graphics(int w, int h): _w(w * REALWIDTHMULT), _h(h * REALHEIGHTMULT)
{
	glib_action = NONE;

	_win = new sf::RenderWindow(sf::VideoMode(_w, _h), "Nibbler SFML");

	try
	{
		if (_win == NULL)
			throw "Could not create sfml window";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
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
	_win->close();
	return ;
}

void Graphics::handleEvents(void)
{
	sf::Event	ev;

	if (_win->pollEvent(ev))
	{
		switch (ev.type)
		{
			case sf::Event::Closed:
				glib_action = QUIT;
				break;
			case sf::Event::KeyPressed:
				switch (ev.key.code)
				{
					case sf::Keyboard::Escape:
						glib_action = QUIT;
						break;
					case sf::Keyboard::Num1:
						glib_action = LIB1;
						break;
					case sf::Keyboard::Num2:
						glib_action = LIB2;
						break;
					case sf::Keyboard::W:
						glib_action = UP;
						break;
					case sf::Keyboard::A:
						glib_action = LEFT;
						break;
					case sf::Keyboard::S:
						glib_action = DOWN;
						break;
					case sf::Keyboard::D:
						glib_action = RIGHT;
						break;
					case sf::Keyboard::P:
						glib_action = PAUSE;
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
}

void Graphics::drawMap(void)
{
	sf::Texture texture;
	sf::Image img;
	img.create(_w, _h, sf::Color::Black);
	texture.create(_w, _h);
	sf::Sprite	sprite(texture);
	int y = 0;

	_win->clear();

	for (std::list<std::list<t_blocks>>::iterator itr = map.begin(); itr != map.end(); itr++, ++y)
	{
		std::list<t_blocks> tl = *itr;
		int x = 0;

		for (std::list<t_blocks>::iterator it = tl.begin(); it != tl.end(); it++, ++x)
		{
			char r = 0, g = 0, b = 0;
			switch (*it)
			{
				case BLKNONE:
					r = 0; g = 0; b = 0;
					break;
				case WALL:
				case EXPLOSION2:
					r = 255; g = 0; b = 0;
					break;
				case HEAD:
					r = 0; g = 255; b = 0;
					break;
				case BODY:
					r = 0; g = 0; b = 255;
					break;
				case FRUIT:
				case EXPLOSION:
					r = 255; g = 255; b = 255;
					break;
			}
			for (int y1 = y * REALHEIGHTMULT; y1 < (y + 1) * REALHEIGHTMULT; y1++)
			{
				for (int x1 = x * REALWIDTHMULT; x1 < (x + 1) * REALWIDTHMULT; x1++)
				{
					sf::Color color;

					color.r = r;
					color.g = g;
					color.b = b;
					color.a = 255;
					img.setPixel(x1, y1, color);
				}
			}
		}
	}
	texture.update(img);
	_win->draw(sprite);
	_win->display();
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

Graphics	*glibInstantiate(int w, int h)
{
	return new Graphics(w, h);
}

void		glibUninstantiate(IGraphics * g)
{
	delete g;
}
