/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:56:00 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/12 15:17:44 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicsHandler.hpp"
#include "Game.hpp"
#include <cstdlib>
#include <time.h>

void	printError(std::string error)
{
	std::cout << error << std::endl;
	exit(0);
}

int main(int argc, char **argv)
{
	srand(time(NULL));

	// std::cout << "hauteur largeur library(ncurses/sdl/sfml)" << std::endl;
	if (argc != 4)
		printError("Wrong number of arguments");
		
	std::string lib = argv[3];//		std::cout << argv[1] << argv[2] << argv[3] << std::endl;

	if (std::atoi(argv[1]) < 10 || std::atoi(argv[1]) > 100 || std::atoi(argv[2])
		< 10 || std::atoi(argv[2]) > 200)
		printError("Bad entry : \n10<height<100 10<width<200 library(ncurses/sdl/sfml)");

	std::string libpath;
	std::string libsfml = "libs/libsfml/libsfml.so";
	std::string libsdl = "libs/libsdl/libsdl.so";

	if (lib == "ncurses")
		libpath = "libs/libncurses/libncurses.so";
	else if (lib == "sdl")
		libpath = libsdl;
	else if (lib == "sfml")
		libpath = libsfml;
	else
	{
		printError("Bad entry : \n10<height<50 10<width<100 library(ncurses/sdl/sfml)");
		return 0;
	}

	Game *game;
	if (libpath != libsfml)
	{
		game = new Game(std::atoi(argv[1]), std::atoi(argv[2]), libsfml);
		game->guiHandler->guiInst->glib_action = (lib == "sdl" ? LIB1 : LIB2);
	}
	else
		game = new Game(std::atoi(argv[1]), std::atoi(argv[2]), libpath);
	game->loop();
	delete game;
	return 0;
}
