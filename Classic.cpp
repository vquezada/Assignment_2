#include "GameStart.h"
#include "Classic.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
//classic mode
Classic::Classic()
{
  cout<<"___CLASSIC MODE___"<<endl;
}
Classic::Classic(int height, int width)
{
  numHeight = height;
  numWidth = width;
}
Classic::~Classic()
{
  cout<<"____DONE____"<<endl; //final statement 
}
//creates class board
int Classic::createBoard(char** board, int height, int width)
{
  //rules for classic mode
  int i;
  int check = 0;
  for (i = height - 1; i <= height + 1; ++i)
  {
    int j;
    for ( j = width - 1; j <= width + 1; ++j)
    {
      if(i >= getHeight())
        continue;
      if(j >= getWidth())
        continue;
      if(i < 0)
        continue;
      if(j < 0)
        continue;
      if((i == height) && (j == width))
        continue;
      else
      {
        if (board[i][j] == 'X')
          check++;
      }
    }
  }
  return check;
}
