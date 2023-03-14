#include "Board.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
  srand(time(NULL));
  Board board('m',"Fido", true);
  return 0;
}
