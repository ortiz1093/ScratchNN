#include "activation.h"
#include "readIris.h"
#include "matrixOps.h"
#include "neuralNet.h"
#include  <iostream>
#include <time.h>

void check (std::vector<int> v){
  if (v.size()==1) {
    std::cout << "Got one" << std::endl;
  } else if (v.size()==2) {
    std::cout << "Got two" << std::endl;
  } else {
    std::cout << "Wrong number" << std::endl;
  }
}

int main () {
  // std::string file = "./DATA/10-working/iris.csv";
  //
  // std::vector<std::vector<double>> X = readIris(file);
  // NeuralNetwork NN1;
  //
  // std::vector<std::vector<double>> W = NN1.getWeight(1);
  //
  // std::vector<std::vector<double>> X_prime = transpose(X);
  //
  //
  // std::cout << "Size of X: ";
  // displaySize(X);
  // std::cout << "Size of W: ";
  // displaySize(W);
  // std::cout << "Size of X': ";
  // displaySize(X_prime);

}
