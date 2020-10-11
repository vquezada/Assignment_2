#include <string>
#include <iostream>
#include "GameStart.h"
using namespace std;
//mirror header file
class Mirror: public GameStart
{
public:
  Mirror();
  Mirror(int height, int width);
  ~Mirror();
  int createBoard(char** board, int height, int width);
private:
  int numHeight;
  int numWidth;
};
