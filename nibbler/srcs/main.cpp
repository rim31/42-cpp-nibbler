#include "GraphicsHandler.hpp"
#include "Game.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
	std::cout << "hauteur largeur library(ncurses/sdl/sfml)" << std::endl;
	if (argc == 4)
	{
		std::string str = argv[3];//		std::cout << argv[1] << argv[2] << argv[3] << std::endl;

		if ((std::atoi(argv[1]) > 10 && std::atoi(argv[1]) < 50 && std::atoi(argv[2])
			> 10 && std::atoi(argv[2]) < 100 ) && (str.compare("ncurses") == 0 ||
		str.compare("sdl") == 0 || str.compare("sfml") == 0 ))
		{
			Game *game = new Game(std::atoi(argv[1]), std::atoi(argv[2]));
			std::cout << game->height << " | "<< game->width << " | "<< argv[3] << " | "<< std::endl;

			game->loop();

			delete game;
		}
		std::cout << "mauvaise entree : \n10<hauteur<50 10<largeur<100 library(ncurses/sdl/sfml)" << std::endl;
	}
	return 0;
}
