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
    Snake(const char * str);        // ??? OSEF, juste pour le style complinent
    Snake(Snake const & src);//constructeur par copie = avec comme parametre une instance de la clase declaree
    virtual ~Snake( void );//destructeur
    Snake & operator=( Snake const & nb);//operateur egal :  operateur d'assignation = mise a jour de l'instance courante

    //===========methode==========
    void Setup();
    std::list<std::list<t_blocks>> Draw();
    // void Input();
    void Logic();



    //============attribut===============
    bool gameOver;
    int width;
    int height;
    int x, y, fruitX, fruitY, score;
    std::vector<int> tailX, tailY;//on limite a 100 fruit max, faut pas deconner, tu vas mourir avant de tester plus que ca dans la correction
    int nTail;
    // enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
    t_action dir;

  private:

};

#endif
