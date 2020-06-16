#include "activation.h"
#include "readIris.h"
#include "matrixOps.h"
#include  <iostream>

int main () {
  // std::string file = "./DATA/10-working/iris.csv";

  // std::vector<std::vector<double>> result = readIris(file);
  std::vector<std::vector<double>> A = {{1,2,3,4,5,6}};
  std::vector<std::vector<double>> B = {{1},{2},{3},{4},{5},{6}};
  std::vector<std::vector<double>> C = multiply(A,B);
  displayMat(A);
  displayMat(B);
  displayMat(C);

  return 0;
}
