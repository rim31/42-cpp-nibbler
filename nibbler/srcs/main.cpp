#include "GraphicsHandler.hpp"
#include "Game.hpp"

int main(void)
{
	// Game constructor
	// ========================
	// GraphicsHandler	*guiHandler = new GraphicsHandler();
	// guiHandler->loadLibrary("libs/libsdl/libsdl.so");
	//
	// std::list<std::list<t_blocks>>	& map = guiHandler->guiInst->map;
	// std::list<std::list<t_blocks>> mapTmp;
	//
	// for (int y = 0; y < HEIGHT; ++y)
	// {
	// 	std::list<t_blocks> line;
	//
	// 	for (int x = 0; x < WIDTH; ++x)
	// 	{
	// 		// if (x == snakeHead.x && y == snakeHead.y)
	// 		// 	line.push_back(HEAD);
	// 		// else
	// 			line.push_back(BLKNONE);
	// 	}
	// 	map.push_back(line);
	// }


	///////////////////////////////////////////////////////////////////////////

	Game *game = new Game();

	game->loop();

	// while (1)
	// {
	// 	snake->Draw();
	// 	// snake->Input();
	// 	snake->Logic();
	// 	inputHandler()
	// 	guiHandler->guiInst->update();
	//
	// 	switch (guiHandler->guiInst->glib_action)
	// 	{
	// 		case LIB1:
	// 			mapTmp = guiHandler->guiInst->map;
	// 			if (guiHandler != NULL)
	// 				delete guiHandler;
	//
	// 			guiHandler = new GraphicsHandler();
	// 			guiHandler->loadLibrary("libs/libsdl/libsdl.so");
	// 			guiHandler->guiInst->glib_action = NONE;
	// 			guiHandler->guiInst->map = mapTmp;
	// 			break;
	// 		case LIB2:
	// 			mapTmp = guiHandler->guiInst->map;
	// 			if (guiHandler != NULL)
	// 				delete guiHandler;
	//
	// 			guiHandler = new GraphicsHandler();
	// 			guiHandler->loadLibrary("libs/libncurses/libncurses.so");
	// 			guiHandler->guiInst->glib_action = NONE;
	// 			guiHandler->guiInst->map = mapTmp;
	// 			break;
	// 			// =====================
	// 		case UP:
	// 		case LEFT:
	// 		case DOWN:
	// 		case RIGHT:
	// 			snake->dir = guiHandler->guiInst->glib_action;
	// 			break;
	// 			// =====================
	// 		case QUIT:
	// 			if (guiHandler != NULL)
	// 				delete guiHandler;
	// 			exit(0);
	// 			break;
	// 		case NONE:
	// 			break;
	// 	}
	// }

	return 0;
}
