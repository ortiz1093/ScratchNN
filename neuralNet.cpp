#include "neuralNet.h"

NeuralNetwork::NeuralNetwork(){
  setWeights(_seed);
  showWeights();
}

void NeuralNetwork::setWeights(int seed) {
  if (seed){
    std::cout << "Using seed: "<< _seed << std::endl;
    srand(seed);
  } else {
    std::cout << "Using time: " << time(NULL) << std::endl;
    srand(time(NULL));
  }

  std::cout << "RAND_MAX: " << RAND_MAX << std::endl;

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
