#include "GraphicsHandler.hpp"
#include "Game.hpp"

int main(void)
{
	Game *game = new Game();

	game->loop();

	delete game;

	return 0;
}
