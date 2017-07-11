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

Snake::Snake (const char * message)
{
  (void)message;
  // std::cout << "Default constructor 2 called" << std::endl;
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
  fruitX = 1 + rand() % (width - 2);
  fruitY = 1 + rand() % (height - 2);
  score = 0;
  nTail = 0;
}

void Snake::Logic()
{
  int prevX = tailX[0];
  int prevY = tailY[0];
  int prev2X, prev2Y;
  tailX[0] = x;
  tailY[0] = y;
  for (int i = 1; i <= nTail; i++)
  {
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;

    // std::cout << tailX[i] << " | " << tailY[i] << " : " << nTail << std::endl;
  }
  switch ( dir ) {
  case LEFT:
    dir = LEFT;
    x--;
    break;
  case  RIGHT:
    dir = RIGHT;
    x++;
    break;
  case UP:
    dir = UP;
    y--;
    break;
  case DOWN:
    dir = DOWN;
    y++;
    break;
  default:
    break;
  }
  if (x < 2 || x >= width - 2 || y < 2 || y >= height - 2)
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
    fruitX = 1 + rand() % (width - 2);
    fruitY = 1 + rand() % (height - 2);
    nTail++;
    tailX[nTail - 1] = -1;
    tailY[nTail - 1] = -1;
  }
}
