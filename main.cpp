#include "activation.h"
#include "readIris.h"
#include "matrixOps.h"
#include "neuralNet.h"
#include  <iostream>
#include <time.h>

void testFlag (int i){
  std::cout << "Flag " << i << std::endl;
}

int main () {
  using namespace std;

  // string file = "./DATA/10-working/iris.csv";
  // testFlag(1);
  //
  // vector<vector<double>> D = readIris(file);
  // NeuralNetwork NN1;
  //
  // testFlag(2);
  //
  // vector<vector<double>> X = submatrix(D,{0,getSize(D)[0]},{0,4});
  // vector<vector<double>> W = NN1.getWeight(1);
  //
  // testFlag(3);
  //
  // vector<vector<double>> X_prime = transpose(X);
  //
  // testFlag(4);
  //
  // cout << "Size of D: ";
  // displaySize(D);
  // cout << "Size of X: ";
  // displaySize(X);
  // cout << "Size of W: ";
  // displaySize(W);
  // cout << "Size of X': ";
  // displaySize(X_prime);
  //
  // testFlag(5);
  //
  // vector<vector<double>> Z = multiply(W, X_prime);
  // cout << "Size of Z: ";
  // displaySize(Z);
  //
  // testFlag(6);
  testFlag(1);
  vector<vector<double>> A = {{1,2,3},{4,5,6}};
  vector<vector<double>> B = {{1,2,3},{3,4,5},{5,6,7}};
  vector<vector<double>> C = multiply(A,B);
  testFlag(2);
  cout << "Size of A: ";
  displaySize(A);
  cout << "Size of B: ";
  displaySize(B);
  cout << "Size of C: ";
  displaySize(C);
  testFlag(3);
  displayMat(A);
  displayMat(B);
  displayMat(C);
  testFlag(4);

  return 0;

}
