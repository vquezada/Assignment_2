#include "GameStart.h"
#include "Classic.h"
#include "Doughnut.h"
#include "Mirror.h"
#include<string>
#include<iostream>
#include<fstream>
#include <unistd.h>
using namespace std;
int main(int argc, char **argv) {
  cout<<"___GAME OF LIFE___"<<endl;
  GameStart game1;
  char** board;
  string userChoice;
  cout<<"For random board type: RANDOM\n For premade board type: FILE"<<endl;
  cin>>userChoice;
  if(userChoice!= "RANDOM" && userChoice!= "FILE")
  {
    cout<<"INVAILD INPUT"<<endl;
  }
  else
  {
    if(userChoice == "FILE")
    {
      cout<<"Enter name of file: "<<endl;
      string boardFile;
      cin >> boardFile;
      cout<<"Premade board: "<<boardFile;
      board = game1.createPremadeFileBoard(boardFile);
    }
    else
    {
      board = game1.createBoardUserInput();
    }
  }
  int type;
  type = game1.Type();
  string outputChoice = "";
  string time = "";
  outputChoice = game1.gameOutput();
  time = game1.Button();
  int count;
  int check;
  char t;
  char** board2 = new char*[game1.getHeight()];
  int i;
  for (i = 0; i < game1.getHeight(); ++i)
  {
    board2[i] = new char[game1.getWidth()];
  }
  int h;
  for (h = 0; h < game1.getHeight(); ++h)
  {
    int w;
    for (w = 0; w < game1.getWidth(); ++w)
    {
      board2[h][w] = '-';
    }
  }
  int round = 1;
  if(size == 1)//CLASSIC
  {
    Classic classic1;
    classic1.setWidth(game1.getWidth());
    classic1.setHeight(game1.getHeight());
    if(outputChoice == "CONSOLE")
    {
      cout<<endl;
      classic1.print(board);
    }
    else
    {
      ofstream ontoBoard(outputChoice);
      ontoBoard<<endl;
      classic1.print(board, ontoBoard);
      ontoBoard.close();
    }
    ofstream ontoBoard(outputChoice);
    while (true)
    {
      cout<<"___GENERATION___ "<<round<<endl;
      count = 0;
      for (h = 0; h < classic1.getHeight(); ++h)
      {
        int w;
        for (w = 0; w < classic1.getWidth(); ++w)
        {
          check = classic1.createBoard(board, h, w);
          t = classic1.OutCome(check);

          if (t == '+')
            board2[h][w] = board[h][w];
          else
            board2[h][w] = t;
        }
      }
      for (h = 0; h < classic1.getHeight(); ++h)
      {
        int w;
        for (w = 0; w < classic1.getWidth(); ++w)
        {
          if (board2[h][w] != board[h][w])
          {
            count++;
          }
        }
      }
      game1.checkRepeat(count);
      if (count == 0)
      {
        break;
      }
      for (h = 0; h < classic1.getHeight(); ++h)
      {
        int w;
        for (w = 0; w < classic1.getWidth(); ++w)
        {
          board[h][w] = board2[h][w];
        }
      }
      if (outputChoice == "CONSOLE")
      {
        classic1.print(board);
      }
      else
      {
        classic1.print(board, ontoBoard);
      }
      if (time == "PAUSE")
      {
        sleep(1);
      }
      else if (time == "ENTER")
      {
        cin.get();
      }
      ++round;
    }
    ontoBoard.close();
  }
  else if(size == 2)
  {
    cout<<"___DOUGHNUT MODE___"<<endl;
    Doughnut doughnut1;
    doughnut1.setWidth(game1.getWidth());
    doughnut1.setHeight(game1.getHeight());
    if(outputChoice == "CONSOLE")
    {
      cout<<endl;
      doughnut1.print(board);
    }
    else
    {
      ofstream ontoBoard(outputChoice);
      doughnut1.print(board, ontoBoard);
      ontoBoard.close();
    }
    ofstream ontoBoard(outputChoice);

    while (true)
    {
      count = 0;

      for (h = 0; h < doughnut1.getHeight(); ++h)
      {
        int w;
        for (w = 0; w < doughnut1.getWidth(); ++w)
        {
          check = doughnut1.createBoard(board, h, w);
          t = doughnut1.OutCome(check);

          if (t == '+')
            board2[h][w] = board[h][w];
          else
            board2[h][w] = t;
        }
      }
      for (h = 0; h < doughnut1.getHeight(); ++h)
      {
        int w;
        for (w = 0; w < doughnut1.getWidth(); ++w)
        {
          if (board2[h][w] != board[h][w])
          {
            count++;
          }
        }
      }
      game1.checkRepeat(count);
      if (count == 0)
      {
        break;
      }
      for (h = 0; h < doughnut1.getHeight(); ++h)
      {
        int w;
        for (w= 0; w < doughnut1.getWidth(); ++w)
        {
          board[h][w] = board2[h][w];
        }
      }
      if (outputChoice == "CONSOLE")
      {
        doughnut1.print(board);
      }
      else
      {
        doughnut1.print(board, ontoBoard);
      }
      if (time == "PAUSE")
      {
        sleep(1);
      }
      else if (time == "ENTER")
      {
        cin.get();
      }
      ++round;
    }
    ontoBoard.close();
  }
  else
  {
    cout<<"___MIRROR MODE___"<<endl;
    Mirror mirror1;
    mirror1.setHeight(game1.getHeight());
    mirror1.setWidth(game1.getWidth());
    if(outputChoice == "CONSOLE")
    {
      cout<<endl;
      mirror1.print(board);
    }
    else
    {
      ofstream ontoBoard(outputChoice);
      mirror1.print(board, ontoBoard);
      ontoBoard.close();
    }
    ofstream ontoBoard(outputChoice);

    while (true)
    {
      count = 0;
      cout<<"height: "<<mirror1.getHeight();
      cout<<"width: "<<mirror1.getWidth();

      for (h = 0; h < mirror1.getHeight(); ++h)
      {
        int w;
        for (w = 0; w < mirror1.getWidth(); ++w)
        {
          check = mirror1.createBoard(board, h, w);
          t = mirror1.OutCome(check);

          if (t == '+')
            board2[h][w] = board[h][w];
          else
            board2[h][w] = t;
        }
      }
      for (h = 0; h < mirror1.getHeight(); ++h)
      {
        int w;
        for (w = 0; w < mirror1.getWidth(); ++w)
        {
          if (board2[h][w] != board[h][w])
          {
            count++;
          }
        }
      }
      game1.checkRepeat(count);
      if (count == 0)
      {
        break;
      }
      for (h = 0; h < mirror1.getHeight(); ++h)
      {
        int w;
        for (w = 0; w < mirror1.getWidth(); ++w)
        {
          board[h][w] = board2[h][w];
        }
      }
      if (outputChoice == "CONSOLE")
      {
        mirror1.print(board);
      }
      else
      {
        mirror1.print(board, ontoBoard);
      }
      if (time == "PAUSE")
      {
        sleep(1);
      }
      else if (time == "ENTER")
      {
        cin.get();
      }
      ++round;
    }
    ontoBoard.close();
  }
  game1.finish(round);

  for (i = 0; i < game1.getHeight(); i++)
  {
    delete[] board[i];
  }
  delete[] board;

  for (i = 0; i < game1.getHeight(); i++)
  {
    delete[] board2[i];
  }
  delete[] board2;
  return 0;
}
