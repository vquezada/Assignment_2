#include<string>
#include<iostream>
#include<fstream>
#include "GameStart.h"
#include "Doughnut.h"
using namespace std;
//Doughnut mode
Doughnut::Doughnut()
{
  cout<<"___DOUGHNUT MODE___"<<endl;
}
Doughnut::Doughnut(int height, int width)
{
  numHeight = height;
  numWidth = width;
}
Doughnut::~Doughnut()
{
  cout<<"____DONE____"<<endl; //final statement 
}
//creates mode
int Doughnut::createBoard(char** board, int height, int width)
{
  //rules for doughnut mode
  int check = 0;
  if (height == 0)
  {
    if (width == 0)
    {
      if (board[1][0] == 'X')
        check++;
      if (board[1][1] == 'X')
        check++;
      if (board[0][1] == 'X')
        check++;
      if (board[1][getWidth() - 1] == 'X')
        check++;
      if (board[0][getWidth() - 1] == 'X')
        check++;
      if (board[getHeight() -  1][getWidth() - 1] == 'X')
        check++;
      if (board[getHeight() - 1][1] == 'X')
        check++;
      if (board[getHeight() - 1][0] == 'X')
        check++;
    }
    if (width == getWidth() - 1)
    {
      if (board[1][getWidth() - 1] == 'X')
        check++;
      if (board[1][getWidth() - 2] == 'X')
        check++;
      if (board[0][getWidth() - 2] == 'X')
        check++;
      if (board[getHeight() - 1][getWidth() - 2] == 'X')
        check++;
      if (board[getHeight() - 1][getWidth() - 1] == 'X')
        check++;
      if (board[getHeight() - 1][0] == 'X')
        check++;
      if (board[0][0] == 'X')
        check++;
      if (board[1][0] == 'X')
        check++;
    }
    else
    {
      if (board[0][width + 1] == 'X')
        check++;
      if (board[0][width - 1] == 'X')
        check++;
      if (board[getHeight() - 1][width - 1] == 'X')
        check++;
      if (board[getHeight() - 1][width] == 'X')
        check++;
      if (board[getHeight() - 1][width + 1] == 'X')
        check++;
      for (int below = width - 1; below <= width + 1; ++below)
        if (board[1][below] == 'X')
          check++;
    }
  }
  if (height == getHeight() - 1)
  {
    if (width == 0)
    {
      if (board[getHeight() - 2][0] == 'X')
        check++;
      if (board[getHeight() - 2][1] == 'X')
        check++;
      if (board[getHeight() - 1][1] == 'X')
        check++;
      if (board[getHeight() - 2][getWidth() - 1] == 'X')
        check++;
      if (board[getHeight() - 1][getWidth() - 1] == 'X')
        check++;
      if (board[0][getWidth() - 1] == 'X')
        check++;
      if (board[0][0] == 'X')
        check++;
      if (board[0][1] == 'X')
        check++;
    }
    if (width == getWidth() - 1)
    {
      if (board[getHeight() - 2][getWidth() - 1] == 'X')
        check++;
      if (board[getHeight() - 2][getWidth() - 2] == 'X')
        check++;
      if (board[getHeight() - 1][getWidth() - 2] == 'X')
        check++;
      if (board[0][getWidth() - 2] == 'X')
        check++;
      if (board[0][getWidth() - 1] == 'X')
        check++;
      if (board[0][0] == 'X')
        check++;
      if (board[getHeight() - 2][0] == 'X')
        check++;
      if (board[getHeight() - 1][0] == 'X')
        check++;
    }
    else
    {
      if (board[getHeight() - 1][width + 1] == 'X')
        check++;
      if (board[getHeight() - 1][width - 1] == 'X')
        check++;
      if (board[0][width] == 'X')
        check++;
      if (board[0][width - 1] == 'X')
        check++;
      if (board[0][width + 1] == 'X')
        check++;
        int topNum;
      for (topNum = width - 1; topNum <= width + 1; ++topNum)
        if (board[getHeight() - 2][topNum] == 'X')
          check++;
    }
  }
  if ((width == 0) && (height > 0) && (getHeight() < getHeight() - 1))
  {
    if (board[height - 1][0] == 'X')
      check++;
    if (board[height + 1][0] == 'X')
      check++;
    if (board[height][0] == 'X')
      check += 0;
    if (board[height][getWidth() - 1] == 'X')
      check++;
    if (board[height + 1][getWidth() - 1] == 'X')
      check++;
    if (board[height - 1][getWidth() - 1] == 'X')
      check++;
      int right;
    for (right = height - 1; right <= height + 1; ++right)
      if (board[right][1] == 'X')
        check++;
  }
  if ((width == getWidth() - 1) && (height > 0) && (height < getHeight() - 1))
  {
    if (board[height - 1][getWidth() - 1] == 'X')
      check++;
    if (board[height + 1][getWidth() - 1] == 'X')
      check++;
    if (board[height][getWidth()-1] == 'X')
      check += 0;
    if (board[height - 1][0] == 'X')
      check++;
    if (board[height + 1][0] == 'X')
      check++;
    if (board[height][0] == 'X')
      check++;

      int right;
    for (right = height - 1; right <= height + 1; ++right)
      if (board[right][getWidth() - 2] == 'X')
        check++;
  }
  if ((width > 0) && (width < getWidth() - 1) && (height > 0) && (height < getHeight() - 1))
  {
      int i;
      int j;
    for (i = height-1; i <= height + 1; ++i)

      for (j = width-1; j <= width + 1; ++j)
      {
        if ((i == height) && (j == width))
          continue;
        else
          if (board[i][j] == 'X')
            check++;
      }
  }
  return check;
}
