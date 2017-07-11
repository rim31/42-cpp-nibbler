/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:55:54 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/11 14:55:55 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <unistd.h>

//======================= instanciation =======================
Game::Game (void)
{
	return;
}

Game::Game (int h, int w, std::string libpath)
{
	snake = new Snake(h, w);

	snake->Setup();
	guiHandler = new GraphicsHandler();
	height = h;
	width = w;
	guiHandler->loadLibrary(libpath, w, h);

	return;
}

Game::Game (Game const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}


Game::~Game (void)
{
	// std::cout << "Destructor called" << std::endl;
	return;
}

Game & Game::operator=( Game const & nb)
{
	(void)nb;
	// std::cout << "Assignation operator called" << std::endl;
	return *this;
}


//================methodes====================

void	Game::loadLibrary(std::string libraryToLoad)
{
	mapTmp = guiHandler->guiInst->map;
	if (guiHandler != NULL)
		delete guiHandler;

	guiHandler = new GraphicsHandler();
	guiHandler->loadLibrary(libraryToLoad, width, height);
	guiHandler->guiInst->glib_action = NONE;
	guiHandler->guiInst->map = mapTmp;
}

void Game::inputHandler(void)
{
	switch (guiHandler->guiInst->glib_action)
	{
		case LIB1:
			loadLibrary("libs/libsdl/libsdl.so");
			break;
		case LIB2:
			loadLibrary("libs/libncurses/libncurses.so");
			break;
		case LIB3:
			loadLibrary("libs/libsfml/libsfml.so");
			break;
			// =====================
		case UP:
		case LEFT:
		case DOWN:
		case RIGHT:
			if (snake->dir != guiHandler->guiInst->glib_action)
				snake->dir = guiHandler->guiInst->glib_action;
			break;
			// =====================
		case QUIT:
			if (guiHandler != NULL)
				delete guiHandler;
			std::cout << "Score : " << snake->score << std::endl;
			delete snake;
			exit(0);
			break;
		case NONE:
			break;
	}
}

void	Game::Draw()
{
	std::list<std::list<t_blocks>>	map;

	map.clear();

	bool printable;	//variable pour savoir si on a deja affiché un truc

	for (int y = 0; y < height; y++)
	{
		std::list<t_blocks> line;
		for (int x = 0; x < width; x++)
		{
			printable = true;
			if (x == snake->x && y == snake->y)
			{
				printable = false;
				line.push_back(HEAD);
			}
			if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
			{
			printable = false;
			line.push_back(WALL);
			}
			if (x == snake->fruitX && y == snake->fruitY)
			{
			printable = false;
			line.push_back(FRUIT);
			}

			for (int k = 0; k < snake->nTail; k++)
			{
				if (y == snake->tailY[k] && x == snake->tailX[k])
				{
					snake->tailX.push_back(x);
					snake->tailY.push_back(y);
					line.push_back(BODY);

					// std::cout << snake->tailX[k] << " | " << snake->tailY[k] << " : " << snake->nTail << std::endl;
					printable = false;
				}
			}
			if (printable)
			line.push_back(BLKNONE);
		}
		map.push_back(line);
	}
	guiHandler->guiInst->map = map;
}

void Game::loop()
{
	while (1)
	{
		if (snake->gameOver)
			guiHandler->guiInst->glib_action = QUIT;
		inputHandler();

		if (!snake->gameOver)
		{
			snake->Logic();
			Draw();
			guiHandler->guiInst->update();
		}
		// =============== vitesse ===========
		if (snake->nTail <= 1)
				usleep(1000 / 10 * 1000);
		else if (snake->nTail <= 4)
				usleep(1000 / 15 * 1000);
		else
				usleep(1000 / 25 * 1000);

	}
}
