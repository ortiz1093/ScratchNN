#include "neuralNet.h"

NeuralNetwork::NeuralNetwork(){
  setWeights(_seed);
}

void NeuralNetwork::setWeights(int seed) {
  if (seed){
    srand(seed);
  } else {
    srand(time(NULL));
  }

  std::vector<double> row;
  double num;

  for (int i = 0; i < _layerSz; i++){
    row = {};
    for (int j = 0; j < _numInputs; j++){
      num = (double) rand()/RAND_MAX;
      row.push_back(num);
    }
    _w1.push_back(row);
  }

  for (int i = 0; i < _numOutputs; i++){
    row = {};
    for (int j = 0; j < _layerSz; j++){
      num = (double) rand()/RAND_MAX;
      row.push_back(num);
    }
    _w2.push_back(row);
  }
}

void NeuralNetwork::showWeights(){
  std::cout << "First weight matrix:" << std::endl;
  displayMat(_w1);
  std::cout << "Second weight matrix:" << std::endl;
  displayMat(_w2);
}

std::vector<std::vector<double>> NeuralNetwork::getWeight(int layer){
  if (layer == 1){
    return _w1;
  } else if (layer == 2){
    return _w2;
  } else {
    std::cout << "Layer selection out of range." << std::endl;
    return {{}};
  }
}
