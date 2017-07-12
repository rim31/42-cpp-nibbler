/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:55:54 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/12 15:16:55 by svelhinh         ###   ########.fr       */
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
	pause = false;

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
		case DOWN:
			if (snake->dir != guiHandler->guiInst->glib_action/* && snake->speedY*/)
				snake->dir = guiHandler->guiInst->glib_action;
			break;
		case LEFT:
		case RIGHT:
			if (snake->dir != guiHandler->guiInst->glib_action/* && snake->speedX*/)
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
		case PAUSE:
			pause = (pause ? false : true);
			guiHandler->guiInst->glib_action = NONE;
			break;
		case NONE:
			break;
	}
}

#include <cmath>

void	Game::Draw()
{
	std::list<std::list<t_blocks>>	map;

	map.clear();

	bool printed;	//variable pour savoir si on a deja affiché un truc

	for (int y = 0; y < height; y++)
	{
		std::list<t_blocks> line;
		for (int x = 0; x < width; x++)
		{
			printed = false;

			if (x == static_cast<int>(snake->tailX[0]) && y == static_cast<int>(snake->tailY[0]))
			{
				line.push_back(HEAD);
				continue;
			}
			if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
			{
				line.push_back(WALL);
				continue;
			}
			if (x == snake->fruitX && y == snake->fruitY)
			{
				line.push_back(FRUIT);
				continue;
			}

			if (x >= static_cast<int>(snake->tailX[0]) - 2 && x <= static_cast<int>(snake->tailX[0]) + 2
				&& y >= static_cast<int>(snake->tailY[0]) - 2 && y <= static_cast<int>(snake->tailY[0]) + 2 && snake->explosion2)
			{
				printed = true;
				line.push_back(EXPLOSION2);
			}
			if (x == static_cast<int>(snake->tailX[0]) + 2 && y == static_cast<int>(snake->tailY[0]) + 2 && snake->explosion2)
				snake->explosion2 = false;
			if (!printed && x >= static_cast<int>(snake->tailX[0]) - 1 && x <= static_cast<int>(snake->tailX[0]) + 1
				&& y >= static_cast<int>(snake->tailY[0]) - 1 && y <= static_cast<int>(snake->tailY[0]) + 1 && snake->explosion)
			{
				printed = true;
				line.push_back(EXPLOSION);
			}
			if (x == static_cast<int>(snake->tailX[0]) + 1 && y == static_cast<int>(snake->tailY[0]) + 1 && snake->explosion)
			{
				snake->explosion = false;
				snake->explosion2 = true;
			}

			if (!printed)
			{
				for (int k = 1; k <= snake->nTail; k++)
				{
					if (y == static_cast<int>(snake->tailY[k]) && x == static_cast<int>(snake->tailX[k]))
					{
						line.push_back(BODY);

						// std::cout << static_cast<int>(snake->tailX[0]) << " , " << static_cast<int>(snake->tailY[0]) << " | " << snake->tailX[1] << " , " << snake->tailY[1] << std::endl;
						printed = true;
					}
				}
			}
			if (printed)
				continue;

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
			if (!pause)
				snake->Logic();
			Draw();
			guiHandler->guiInst->update();
			if (snake->nTail <= 1)
				usleep(1000 / 10 * 1000);
			else if (snake->nTail <= 5)
				usleep(1000 / 15 * 1000);
			else if (snake->nTail <= 10)
				usleep(1000 / 20 * 1000);
			else if (snake->nTail <= 15)
				usleep(1000 / 25 * 1000);
			else if (snake->nTail <= 20)
				usleep(1000 / 30 * 1000);
			else if (snake->nTail <= 25)
				usleep(1000 / 35 * 1000);
			else if (snake->nTail <= 30)
				usleep(1000 / 40 * 1000);
			else if (snake->nTail <= 35)
				usleep(1000 / 45 * 1000);
			else if (snake->nTail <= 40)
				usleep(1000 / 50 * 1000);
			else if (snake->nTail <= 45)
				usleep(1000 / 55 * 1000);
			else
				usleep(1000 / 60 * 1000);
		}
		// =============== vitesse ===========
	}
}
