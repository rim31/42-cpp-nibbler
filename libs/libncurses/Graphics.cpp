/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:55:31 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/12 14:51:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics.hpp"

Graphics::Graphics(void)
{
	return ;
}

Graphics::Graphics(int w, int h)
{
	glib_action = NONE;

	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);

	_win = newwin(h, w, 0, 0);
	update();
	return ;
}

Graphics::Graphics(Graphics const & src)
{
	*this = src;
	return ;
}

Graphics::~Graphics(void)
{
    endwin();
	return ;
}

void Graphics::handleEvents(void)
{
	switch (getch())
	{
		case '1':
			glib_action = LIB1;
			break;
		case '3':
			glib_action = LIB3;
			break;
		case 'w':
			glib_action = UP;
			break;
		case 'a':
			glib_action = LEFT;
			break;
		case 's':
			glib_action = DOWN;
			break;
		case 'd':
			glib_action = RIGHT;
			break;
		case 'p':
			glib_action = PAUSE;
			break;
		case 27:
			glib_action = QUIT;
			break;
	}
}

void Graphics::drawMap(void)
{
	int y = 0;

	for (std::list<std::list<t_blocks>>::iterator itr = map.begin(); itr != map.end(); itr++, y++)
	{
		std::list<t_blocks> tl = *itr;
		int x = 0;
		for (std::list<t_blocks>::iterator it = tl.begin(); it != tl.end(); it++, x++)
		{
			char c;
			switch (*it)
			{
				case BLKNONE:
					c = ' ';
					break;
				case WALL:
				case EXPLOSION2:
					c = '*';
					break;
				case HEAD:
					c = 'O';
					break;
				case BODY:
					c = 'x';
					break;
				case FRUIT:
				case EXPLOSION:
					c = '.';
					break;
			}
			mvwaddch(_win, y, x, c);
		}
	}
    wrefresh(_win);
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
