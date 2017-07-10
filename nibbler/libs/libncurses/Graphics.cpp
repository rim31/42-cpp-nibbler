#include "Graphics.hpp"

Graphics::Graphics(void)
{
	glib_action = NONE;

	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);

	_win = newwin(HEIGHT, WIDTH, 0, 0);
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

void Graphics::handleInput(void)
{
	switch (getch())
	{
		case '1':	// 1
			glib_action = LIB1;
			break;
		case 'w':	// Z : W sur mac
			glib_action = UP;
			break;
		case 'a':	// Q : A sur mac
			glib_action = LEFT;
			break;
		case 's':	// S
			glib_action = DOWN;
			break;
		case 'd':	// D
			glib_action = RIGHT;
			break;
		case 27:	// ESC
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
					c = '*';
					break;
				case HEAD:
					c = 'O';
					break;
				case BODY:
					c = 'x';
					break;
				case FRUIT:
					c = '.';
					break;
			}
			mvwaddch(_win, y, x, c);
		}
	}
}

void Graphics::update(void)
{
	handleInput();
	drawMap();
    wrefresh(_win);
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
