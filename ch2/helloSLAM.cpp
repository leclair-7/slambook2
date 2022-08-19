#include <iostream>

#include "libHelloCalc.h"

using namespace std;

int main(int argc, char **argv) {
  
  double posx(1.2);
  double posy(4.2);
  double soln = calculators::calculateNext(posx, posy);

  cout << "Hello SLAM: " << soln << endl;
  return 0;
}
