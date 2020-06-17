#ifndef NEURALNET_H
#define NEURALNET_H

#include "matrixOps.h"
#include "activation.h"
#include <time.h>

class NeuralNetwork{
private:
  std::vector<std::vector<double>> _w1;
  std::vector<std::vector<double>> _w2;
  int _seed = 1230;
  int _numInputs = 4;
  int _numOutputs = 1;
  int _layerSz = 4;
  std::string _activation = "relu";
public:
  NeuralNetwork();
  void setWeights(int seed = 0);
  void showWeights();
};

#endif
