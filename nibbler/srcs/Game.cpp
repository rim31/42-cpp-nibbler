#include "Game.hpp"
#include <unistd.h>

//======================= instanciation =======================
Game::Game (void)
{
  snake = new Snake();

  snake->Setup();
  guiHandler = new GraphicsHandler();
  guiHandler->loadLibrary("libs/libsdl/libsdl.so");

  // map = &guiHandler->guiInst->map;

  // bool printable;//varibale pour afficher la queue du serpeut

  // for (int y = 0; y < HEIGHT; y++)
  // {
  // 	std::list<t_blocks> line;
  // 	for (int x = 0; x < WIDTH; x++)
  // 	{
  //     printable = true;
  // 		if (x == snake->x && y == snake->y)
  //     {
  //       printable = false;
  // 			line.push_back(HEAD);
  //     }
  //     if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1)
  //     {
  //       printable = false;
  //       line.push_back(WALL);
  //     }
  //     if (x == snake->fruitX && y == snake->fruitY)
  //     {
  //       printable = false;
  //       line.push_back(FRUIT);
  //     }
  //
  //     for (int k = 0; k < snake->nTail; k++)
  //     {
  //       if (x == snake->tailY[k]  && y == snake->tailX[k])
  //       {
  //         line.push_back(BODY);
  //         printable = false;
  //       }
  //     }
  //     if (printable)
  //     	line.push_back(BLKNONE);
  // 	}
  // 	map->push_back(line);
  // }
  // std::cout << "Default constructor called" << std::endl;
  return;
}


// Game::Game (const char * message) : msg(message)
// {
//   // std::cout << "Default constructor 2 called" << std::endl;
//   return;
// }

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


//================methode====================

void Game::inputHandler(void) {

}

void Game::loop()
{
  while (1)
	{
    if (snake->gameOver)
      guiHandler->guiInst->glib_action = QUIT;
    else
    {
  		//snake->Draw();
  		// snake->Input();
  		this->inputHandler();
      snake->Logic();
      guiHandler->guiInst->map = snake->Draw();
  		guiHandler->guiInst->update();
    }

		switch (guiHandler->guiInst->glib_action)
		{
			case LIB1:
				mapTmp = guiHandler->guiInst->map;
				if (guiHandler != NULL)
					delete guiHandler;

				guiHandler = new GraphicsHandler();
				guiHandler->loadLibrary("libs/libsdl/libsdl.so");
				guiHandler->guiInst->glib_action = NONE;
				guiHandler->guiInst->map = mapTmp;
				break;
			case LIB2:
				mapTmp = guiHandler->guiInst->map;
				if (guiHandler != NULL)
					delete guiHandler;

				guiHandler = new GraphicsHandler();
				guiHandler->loadLibrary("libs/libncurses/libncurses.so");
				guiHandler->guiInst->glib_action = NONE;
				guiHandler->guiInst->map = mapTmp;
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
    usleep(1000 / 25 * 1000);
	}
}
