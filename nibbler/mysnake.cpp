#include <iostream>
#include <stdio.h>
// #include <conio.h>
// using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
int tailX[100], tailY[100];
int nTail = 0;
eDirection dir;


void Setup()
{
  gameOver = false;
  dir = STOP;
  x = width / 2;
  y = height / 2;
  fruitX = rand() % width;
  fruitY = rand() % height;
  score = 0;
}

void Draw()
{
  system("clear");
  for (int i = 0; i < width + 1; i++)
  {
    std::cout << "#";
  }
  std::cout << std::endl;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (j == 0)
        std::cout << "#";
      if (i == y  && j == x)
        std::cout << "S";//sanke
      else if (i == fruitY  && j == fruitX)
        std::cout << "F";//fruit
      else
      {
        bool print = false;
        for (int k = 0; k < nTail; k++)
        {
          if (i == tailY[k]  && j == tailX[k])
            std::cout << "s";
            print = true;
        }
      }
      if (!print)
        std::cout << " ";//case vide
      if (j == width - 1)
        std::cout << "#";
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < width+1; i++)
  {
    std::cout << "#";
  }
  std::cout << std::endl;
  std::cout << "SCORE :"<< score <<std::endl;

}

void Input()
{
  if (_knhit())
  {
    switch(_getch())
      case 'a':
        dir = LEFT;
        break;
      case 'd':
        dir = RIGHT;
        break;
      case 'w':
        dir = UP;
        break;
      case 's':
        dir = DOWN;
        break;
      case 'x':
        gameOver = true;
        break;
    }
  }
}

void Logic()
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
    tailX = prevX;
    tailY = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }
  switch ( dir ) {
    case LEFT:
      x--;
      break;
    case  RIGHT:
      x++;
      break;
    case UP:
      y--;
      break;
    case DOWN:
      y++;
      break;
    default:
      break;
  }
  if (x < 0 || x > width || y < 0 || y > height)
    gameOver = true;
  for (int i = 0; i < nTail; i++)
  {
    if (tailX[i] == x && tailY == y)
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

int main()
{
  // Setup();
  while (!gameOver)
  {
    Draw();
    Input();
    Logic();

  }
}
