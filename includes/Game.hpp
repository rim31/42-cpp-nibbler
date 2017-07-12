/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:55:41 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/12 15:06:54 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "IGraphics.hpp"
#include "GraphicsHandler.hpp"
#include "Snake.hpp"

class Game
{
private:
	Game(void);//constructeur
	Snake *snake;
	std::list<std::list<t_blocks>> mapTmp;

public:
	Game (int h, int w, std::string libpath);
	Game(const char * str);        // ??? OSEF, juste pour le style complinent
	Game(Game const & src);//constructeur par copie = avec comme parametre une instance de la clase declaree
	virtual ~Game( void );//destructeur
	Game & operator=( Game const & nb);//operateur egal :  operateur d'assignation = mise a jour de l'instance courante

	int height, width;
    bool pause;
	GraphicsHandler	*guiHandler;

    //===========methodes==========
    void 	Draw();
    void	inputHandler();
    void	loadLibrary(std::string libraryToLoad);
    void	loop();




    //============attribut===============
    // snake
    // guiHandler
    // map
    // mapTmp
    // inputhandler()
    // loop()

};

#endif
