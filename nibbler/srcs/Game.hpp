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
  Snake *snake;
  GraphicsHandler	*guiHandler;
  std::list<std::list<t_blocks>>	*map;
  std::list<std::list<t_blocks>> mapTmp;

  public:
    Game(void);//constructeur
    Game(const char * str);        // ??? OSEF, juste pour le style complinent
    Game(Game const & src);//constructeur par copie = avec comme parametre une instance de la clase declaree
    virtual ~Game( void );//destructeur
    Game & operator=( Game const & nb);//operateur egal :  operateur d'assignation = mise a jour de l'instance courante

    //===========methode==========
    void inputHandler();
    void loop();




    //============attribut===============
    // snake
    // guiHandler
    // map
    // mapTmp
    // inputhandler()
    // loop()

};

#endif
