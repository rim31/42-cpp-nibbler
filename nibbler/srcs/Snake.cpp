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

std::list<std::list<t_blocks>> Snake::Draw()
{
  std::list<std::list<t_blocks>> map;
  bool printable;//variable pour afficher la queue du serpeut

  for (int y = 0; y < HEIGHT; y++)
  {
    std::list<t_blocks> line;
    for (int x = 0; x < WIDTH; x++)
    {
      printable = true;
      if (x == this->x && y == this->y)
      {
        printable = false;
        line.push_back(HEAD);
      }
      if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1)
      {
        printable = false;
        line.push_back(WALL);
      }
      if (x == this->fruitX && y == this->fruitY)
      {
        printable = false;
        line.push_back(FRUIT);
      }

      for (int k = 0; k < this->nTail; k++)
      {
        if (x == this->tailY[k]  && y == this->tailX[k])
        {
          line.push_back(BODY);
          printable = false;
        }
      }
      if (printable)
        line.push_back(BLKNONE);
    }
    map.push_back(line);
  }

  return map;

  // system("clear");
  // bool printable;
  // for (int i = 0; i < width + 1; i++)
  // {
  //   std::cout << "#";
  // }
  // std::cout << std::endl;
  // for (int i = 0; i < height; i++)
  // {
  //   for (int j = 0; j < width; j++)
  //   {
  //     if (j == 0)
  //       std::cout << "#";
  //     if (i == y  && j == x)
  //       std::cout << "S";//sanke
  //     else if (i == fruitY  && j == fruitX)
  //       std::cout << "F";//fruit
  //     else
  //     {
  //       printable = false;
  //       for (int k = 0; k < nTail; k++)
  //       {
  //         if (i == tailY[k]  && j == tailX[k])
  //           std::cout << "s";
  //           printable = true;
  //       }
  //     }
  //     if (!printable)
  //       std::cout << " ";//case vide
  //     if (j == width - 1)
  //       std::cout << "#";
  //   }
  //   std::cout << std::endl;
  // }
  // for (int i = 0; i < width+1; i++)
  // {
  //   std::cout << "#";
  // }
  // std::cout << std::endl;
  // std::cout << "SCORE :"<< score <<std::endl;

}

// void Snake::Input(eDirection direction)
// {
  // if (_knhit())
  // {
  //   switch(_getch())
  //     case 'a':
  //       dir = LEFT;
  //       break;
  //     case 'd':
  //       dir = RIGHT;
  //       break;
  //     case 'w':
  //       dir = UP;
  //       break;
  //     case 's':
  //       dir = DOWN;
  //       break;
  //     case 'x':
  //       gameOver = true;
  //       break;
  //   }
  // }
// }

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
  if (x < 0 || x > width || y < 0 || y > height)
    gameOver = true;
  for (int i = 0; i < nTail; i++)
  {
    if (tailX[i] == x && tailY[i] == y)
      gameOver = true;
  }
  if (x == fruitX && y == fruitY)
  {
    score++;
    fruitX = rand() % width;
    fruitY = rand() % height;
    nTail++;
  }

}
