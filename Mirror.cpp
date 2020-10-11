#include<string>
#include<iostream>
#include<fstream>
#include "GameStart.h"
#include "Mirror.h"
using namespace std;
//mirror mode
Mirror::Mirror()
{
  cout<<"___MIRROR MODE___"<<endl;
}
Mirror::Mirror(int height, int width)
{
  numHeight = height;
  numWidth = width;
}
Mirror::~Mirror()
{
  cout<<"____DONE____"<<endl;//final statement
}
//mirror board rules
int Mirror::createBoard(char** board, int height, int width)
{
  int check = 0;
  if (height == 0)
  {
    if (width == 0)
    {
      if (board[0][0] == 'X')
        check += 3;
      if (board[1][0] == 'X')
        check += 2;
      if (board[1][1] == 'X')
        check += 1;
      if (board[0][1] == 'X')
        check += 2;
    }
    if (width == getWidth() - 1)
    {
      if (board[0][getWidth() - 1] == 'X')
        check += 3;
      if (board[1][getWidth() - 1] == 'X')
        check += 2;
      if (board[1][getWidth() - 2] == 'X')
        check += 1;
      if (board[0][getWidth() - 2] == 'X')
        check += 2;
    }
    else
    {
      if (board[0][width] == 'X')
        check++;
      if (board[0][width + 1] == 'X')
        check += 2;
      if (board[0][width - 1] == 'X')
        check += 2;
        int bottom;
      for (bottom = width - 1; bottom <= width + 1; ++bottom)
        if (board[1][bottom] == 'X')
          check++;
    }
  }
  if (height == getHeight() - 1)
  {
    if (width == 0)
    {
      if (board[getHeight() - 1][0] == 'X')
        check += 3;
      if (board[getHeight() - 2][0] == 'X')
        check += 2;
      if (board[getHeight() - 2][1] == 'X')
        check += 1;
      if (board[getHeight() - 1][1] == 'X')
        check += 2;
    }
    if (width == getWidth() - 1)
    {
      if (board[getHeight() - 1][getWidth() - 1] == 'X')
        check += 3;
      if (board[getHeight() - 2][getWidth() - 1] == 'X')
        check += 2;
      if (board[getHeight() - 2][getWidth() - 2] == 'X')
        check += 1;
      if (board[getHeight() - 1][getWidth() - 2] == 'X')
        check += 2;
    }
    else
    {
      if (board[getHeight() - 1][width] == 'X')
        check++;
      if (board[getHeight() - 1][width + 1] == 'X')
        check += 2;
      if (board[getHeight() - 1][width - 1] == 'X')
        check += 2;
        int top;
      for (top = width - 1; top <= width + 1; ++top)
        if (board[getHeight() - 2][top] == 'X')
          check++;
    }
  }
  if ((width == 0) && (height> 0) && (height< getHeight() - 1))
  {
    if (board[height - 1][0] == 'X')
      check += 2;
    if (board[height+ 1][0] == 'X')
      check += 2;
    if (board[height][0] == 'X')
      check++;
      int right;
    for (right = height- 1; right <= height+ 1; ++right)
      if (board[right][1] == 'X')
        check++;
  }
  if ((width == getWidth() - 1) && (height> 0) && (height< getHeight() - 1))
  {
    if (board[height- 1][getWidth() - 1] == 'X')
      check += 2;
    if (board[height+ 1][getWidth() - 1] == 'X')
      check += 2;
    if (board[height][getWidth()-1] == 'X')
      check++;
      int right;
    for (right = height- 1; right <= height+ 1; ++right)
      if (board[right][getWidth() - 2] == 'X')
        check++;
  }
  if ((width > 0) && (width < getWidth() - 1) && (height > 0) && (height < getHeight() - 1))
  {
    int i;
    for (i = height-1; i <= height+ 1; ++i)
    {
      int j;
      for (j = width-1; j <= width + 1; ++j)
      {
        if ((i == height) && (j == width))
          continue;
        else
        {
          if (board[i][j] == 'X')
            check++;
        }
      }
    }
  }
  return check;
}
