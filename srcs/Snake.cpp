/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:56:02 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/12 15:16:29 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

//======================= instanciation =======================
Snake::Snake (void)
{
	return;
}

Snake::Snake (int h, int w)
{
	width = w;
	height = h;
	nTail = 0;
	tailX = std::vector<int>(1);
	tailY = std::vector<int>(1);
	Setup();
	// std::cout << "Default constructor called" << std::endl;
	return;
}

Snake::Snake (Snake const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}


Snake::~Snake (void)
{
	// std::cout << "Destructor called" << std::endl;
	return;
}

Snake & Snake::operator=( Snake const & nb)
{
	(void)nb;
	// std::cout << "Assignation operator called" << std::endl;
	return *this;
}


//================methode====================

void Snake::Setup()
{
	gameOver = false;
	dir = RIGHT;
	x = width / 2;
	y = height / 2;
	RandomFruit();
	score = 0;
	nTail = 0;
}

void Snake::RandomFruit()
{
	bool randomFruit = true;
	while (randomFruit)
	{
		randomFruit = false;
		fruitX = 5 + rand() % ((width - 2) - 6);
		fruitY = 5 + rand() % ((height - 2) - 6);
		for (int i = 1; i <= nTail; i++)
		{
			if (fruitX == tailX[i] && fruitY == tailY[i])
				randomFruit = true;
		}
	}
}

void Snake::Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	// std::cout << tailX[0] << " <- yo" << std::endl;
	for (int i = 1; i <= nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

		// std::cout << tailX[0] << " , " << tailY[0] << " | " << tailX[1] << " , " << tailY[1] << std::endl;
		// std::cout << tailX[i] << " : " << nTail << std::endl;
	}

	switch ( dir )
	{
	case LEFT:
		x--;
		break;
	case  RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x < 1 || x >= width - 1 || y < 1 || y >= height - 1)
		gameOver = true;
	for (int i = 0; i <= nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
		// std::cout << tailX[i] << " | " << tailY[i] << " : " << i << std::endl;
	}
	if (x == fruitX && y == fruitY)
	{
		score++;
		explosion = true;
		RandomFruit();
		tailX.push_back(-1);
		tailY.push_back(-1);
		nTail++;
	}
}