#include "Snake.hpp"

//======================= instanciation =======================
Snake::Snake (void)
{
  width = 20;
  height = 20;
  nTail = 0;
  tailX = std::vector<int>(100);
  tailY = std::vector<int>(100);
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
  x = WIDTH / 2;
  y = HEIGHT / 2;
  fruitX = rand() % WIDTH;
  fruitY = rand() % HEIGHT;
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
  for (int i = 1; i < nTail; i++)
  {
  prev2X = tailX[i];
  prev2Y = tailY[i];
  tailX[i] = prevX;
  tailY[i] = prevY;
  prevX = prev2X;
  prevY = prev2Y;
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
  if (x < 2 || x >= WIDTH - 2 || y < 2 || y >= HEIGHT - 2)
  gameOver = true;
  for (int i = 0; i <= nTail; i++)
  {
  if (tailX[i] == x && tailY[i] == y)
    gameOver = true;
  }
  if (x == fruitX && y == fruitY)
  {
  score++;
  fruitX = rand() % WIDTH;
  fruitY = rand() % HEIGHT;
  nTail++;
  }
}
