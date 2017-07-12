/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:55:48 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/12 14:38:47 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
# define SNAKE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "IGraphics.hpp"

class Snake
{
public:
	Snake(void);//constructeur
	Snake(int h, int w);//constructeur
	Snake(Snake const & src);//constructeur par copie = avec comme parametre une instance de la clase declaree
	virtual ~Snake( void );//destructeur
	Snake & operator=( Snake const & nb);//operateur egal :  operateur d'assignation = mise a jour de l'instance courante

	//===========methode==========
	void RandomFruit();
	void Setup();
	void Logic();



	//============attribut===============
	bool gameOver, speedX, speedY, explosion, explosion2;
	int width, height, x, y, fruitX, fruitY, score, nTail, timeX, timeY;
	std::vector<int> tailX, tailY;//on limite a 100 fruit max, faut pas deconner, tu vas mourir avant de tester plus que ca dans la correction
	t_action dir;
};

#endif
