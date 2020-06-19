#include "activation.h"


// Return max of two numbers, a and b.
double max(double a, double b){

  if (a > b){
    return a;
  } else {
    return b;
  }
}

// Calculate the logistic sigmoid value of x.
double sigmoid(double x){
  return 1/(1 + exp(-x));
}

// Normalizes each row or column of a matrix into a probability distribution.
std::vector<std::vector<double>> softmax(std::vector<std::vector<double>> X, int axis){

  std::vector<std::vector<double>> result;
  std::vector<double> row;
  int numSamples, numOutputs;
  double sumExp;
  bool transposed = false;
  const int ROWS = 1,
            COLS = 2;

  switch(axis){
    case COLS:
      X = transpose(X);
      transposed = true;
    case ROWS:
      numSamples = getSize(X)[0];
      numOutputs = getSize(X)[1];
      break;
    default:
      std::cout << "Axis selection invalid" << std::endl;
      return {{}};
  }

  while (numSamples < numOutputs){
    std::cout << "You have more outputs than samples, is this correct [y/n]:" << std::endl;
    std::string verify;
    std::cin >> verify;
    if (verify == "y"){
      break;
    } else {
      std::cout << "Transposing input." << std::endl;
      X = transpose(X);
      transposed = !transposed;
      numSamples = getSize(X)[0];
      numOutputs = getSize(X)[1];
      break;
    }
  }

  for (int i = 0; i < numSamples; i++){
    row = {};
    sumExp = 0;
    for (int j = 0; j < numOutputs; j++){
      sumExp += exp(X[i][j]);
    }


    for (int j = 0; j < numOutputs; j++){
      row.push_back(exp(X[i][j])/sumExp);
    }
    result.push_back(row);
  }


  if (transposed){
    result = transpose(result);

  }

  return result;
}

// Applies a chosen activation function to each element of a matrix
double activate(double x, std::string fcn){

  double result;
  int function;
  const int SIGMOID = 1,
            TANH = 2,
            RELU = 3;

  transform(fcn.begin(), fcn.end(), fcn.begin(), ::tolower);
  if (fcn == "sigmoid"){
    function = SIGMOID;
  } else if (fcn == "tanh"){
    function = TANH;
  } else if (fcn == "relu"){
    function = RELU;
  } else {
    std::cout << "No activation function of the specified type is available" << std::endl;
    return nan("1");
  }

  switch (function){

    case SIGMOID:
      result = sigmoid(x);
      break;

    case TANH:
      result = tanh(x);
      break;

    case RELU:
      result = max(0,x);
      break;
  }

  return result;
}

// Applies a chosen activation function to each element in a matrix
std::vector<std::vector<double>> matrixActivation(std::vector<std::vector<double>> mat, std::string activation){

  std::vector<std::vector<double>> result;
  double value;

  for (int i = 0; i < mat.size(); i++){
    std::vector<double> row;
    for (int j = 0; j < mat[i].size(); j++){
      value = activate(mat[i][j], activation);
      row.push_back(value);
    }
    result.push_back(row);
    delete &row;
  }

  return result;
}
