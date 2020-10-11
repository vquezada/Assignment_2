#include <string>
#include "GameStart.h"
using namespace std;
//doughnut header file
class Doughnut:public GameStart
{
public:
  Doughnut();
  Doughnut(int height, int width);
  ~Doughnut();
  int createBoard(char** board, int height, int width);
private:
  int numHeight;
  int numWidth;
};
