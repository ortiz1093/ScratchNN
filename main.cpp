#include "activation.h"
#include "readIris.h"
#include "matrixOps.h"
#include "neuralNet.h"
#include <iostream>
#include <time.h>


int main () {
  using namespace std;

  string file = "./DATA/10-working/iris.csv";
  vector<vector<double>> D = readIris(file);
  NeuralNetwork NN1;

  vector<vector<double>> X = submatrix(D,{0,getSize(D)[0]},{0,4});
  vector<vector<double>> Y = submatrix(D,{0,getSize(D)[0]},{4,getSize(D)[1]});
  vector<vector<double>> W1 = NN1.getWeight(1);

  vector<vector<double>> X_prime = transpose(X);

  vector<vector<double>> Z = multiply(W1, X_prime);

  vector<vector<double>> A = matrixActivation(Z,"sigmoid");

  vector<vector<double>> W2 = NN1.getWeight(2);
  vector<vector<double>> L = multiply(W2,A);

  cout << "Size L: " << endl;
  // L = transpose(L);
  displaySize(L);
  headMat(L);

  vector<vector<double>> Y_hat = softmax(L,2);
  cout << "Size Y_hat: " << endl;
  displaySize(Y_hat);

  headMat(Y_hat);

  return 0;

}
