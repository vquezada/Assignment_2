#include <string>
#include <iostream>
#include "GameStart.h"
using namespace std;
//classic header file
class Classic: public GameStart
{
public:
  Classic();
  Classic(int height, int width);
  ~Classic();
  int createBoard(char** board, int height, int width);
private:
  int numHeight;
  int numWidth;
};
