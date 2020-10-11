#include <string>
#include <iostream>
#ifndef GAMESTART_H
#define GAMESTART_H
using namespace std;
//Game of life header file(all functions and variables)
class GameStart
{
public:
  GameStart();
  ~GameStart();
  void setHeight(int height);
  void setWidth(int width);
  void printGrid(char**board);
  void print(char** board);
  void print(char** board, ofstream & output);
  void checkRepeat(int c);
  void finish(int round);
  void checkRepeat(int c);
  void finish(int round);
  string getBoardFile();
  int getHeight();
  int getWidth();
  char OutCome(int num);
  char** createPremadeFileBoard(string boardFile);
  char** createBoardUserInput();
  int Type();
  string gameOutput();
  string Button();
private:
  string boardFile;
  int numRepeated;
  int currentCount;
  int numHeight;
  int numWidth;
  bool isFromFile;
};
#endif
