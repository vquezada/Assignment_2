#include<string>
#include<iostream>
#include<fstream>
#include "GameStart.h"
#include "Classic.h"
#include "Doughnut.h"
using namespace std;
//Game of life
GameStart::GameStart()
{
  numRepeated = 0;
  currentCount = -1;
}
GameStart::~GameStart()
{
  cout<<"____DONE____"<<endl; //final statement
}
//getters and setters for height and width of board
string GameStart::getBoardFile()
{
  return boardFile;
}
int GameStart::getHeight()
{
  return numHeight;
}
int GameStart::getWidth()
{
  return numWidth;
}
void GameStart::setHeight(int height)
{
  numHeight = height;
}
void GameStart::setWidth(int width)
{
  numWidth = width;
}
//fucntion that creates board using file
char** GameStart::createPremadeFileBoard(string fileName)
{

  numWidth;
  numHeight;
  ifstream boardFile;
  boardFile.open(fileName);
  boardFile >> numHeight;
  boardFile >> numWidth;
  cout<<"\n Height: "<<numHeight <<endl;
  cout<<" \n Width: "<<numWidth<<endl;;

  char** board = new char*[numHeight];
  int h;
  for (h = 0; h < numHeight; ++h)
  {
    int w;
    board[h] = new char[numWidth];
    for (w = 0; w < numWidth; ++w)
    {
      board[h][w] = ' ';
    }
  }
  int w;
  for(h = 0; h < numHeight; ++h)
  {
    for(w = 0; w < numWidth; ++w)
    {
      board[h][w] = boardFile.get();
    }
    boardFile.get();
  }
  boardFile.close();
  return board;
}
//function that creates board asking the user for height and width
char** GameStart::createBoardUserInput()
{
  cout << "Enter height: "<<endl;
  cin >> numHeight;
  while(numHeight <= 0)
  {
    cout << "Height: "<<endl;
    cin >> numHeight;
  }
  cout << "Width: "<<endl;
  cin >> numWidth;
  while(numWidth <= 0)
  {
    cout << "Width";
    cin >> numWidth;
  }
  double numX;
  cout << "Enter number between 0 and 1" << endl;
  while(numX >= 1 || numX <= 0)
  {
    cin >> numX;
  }
  int i;
  char **board = new char*[numHeight];
  for (i = 0; i < numHeight; ++i)
  {
    board[i] = new char[numWidth];
  }
  int h;
  for (h = 0; h < numHeight; ++h)
  {
    for (int w = 0; w < numWidth; ++w)
    {
      double randNum = rand();
			randNum = randNum / RAND_MAX;
			if (randNum < numX)
      {
				board[h][w] = 'X';
      }
      else
      {
        board[h][w] = '-';
      }
    }
  }
  return board;
}
//function that asks the user what type of mode
int GameStart::Type()
{

  int type = 0;
  cout<<"Enter mode: "<<endl;
  cout<<"For Classic mode: 1\nFor Mirror mode: 2\n Doughnut mode: 3";
  cin>>type;

  return type;
}
string GameStart::gameOutput()
{
  string boardOutput;
  cout << "For board to output to console type: CONSOLE \n For board to output to file type: FILE";
  cin >> boardOutput;
  return boardOutput;
}
string GameStart::Button()
{
  string userChoice = "";
  cout << "To view board generations .. would you like to press enter, pause, or none.";
  cout << "Type: ENTER, PAUSE, OR NONE";
  cin>>userChoice;
  while (userChoice != "ENTER" && userChoice != "PAUSE" && userChoice != "NONE")
  {
    cout << "Type: ENTER, PAUSE, OR NONE";
    cin >> userChoice;
  }
  return userChoice;
}
void GameStart::print(char** board)
{
  int h;
  for (h = 0; h < numHeight; ++h)
  {
    int w;
    for (w = 0; w < numWidth; ++w)
    {
      cout << board[h][w];
    }
    cout <<endl;
  }
  cout << "" << endl;
}
//fuction that prints out board
void GameStart::print(char** board, ofstream & output)
{
  int h;
  int w;
  for (h = 0; h < numHeight; ++h)
  {
    for (w = 0; w < numWidth; ++w)
    {
      output << board[h][w];
    }
    output <<endl;
  }
  output << "" << endl;
}
//funciton that determies the generations outcome
char GameStart::OutCome(int num)
{
  if(num <= 1)
  {
		return '-';
	}
	else if(num == 2)
  {
		return '+';
	}
	else if(num == 3)
  {
		return 'X';
	}
	else
  {
		return '-';
	}
}
//funcition that checks for loop
void GameStart::checkRepeat(int c)
{
  if(c == currentCount)
  {
    ++numRepeated;
  }
  else
  {
    numRepeated = 0;
  }
  currentCount = c;
  if(numRepeated > 10000)
  {
    cout<<"loop"<<endl;
    exit(EXIT_FAILURE); // this fucntion ends the loop
  }
}
// function that print generations
void GameStart::finish(int round)
{
  cout<<"TOTAL GENERATIONS: " <<round<<endl; ;
}
