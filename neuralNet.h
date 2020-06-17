#ifndef NEURALNET_H
#define NEURALNET_H

#include "matrixOps.h"
#include "activation.h"
#include <time.h>

class NeuralNetwork{
private:
  std::vector<std::vector<double>> _w1;
  std::vector<std::vector<double>> _w2;
  std::vector<double> _logit;
  std::vector<double> _y_hat;
  int _seed = 1230;
  int _numInputs = 4;
  int _numOutputs = 3;
  int _layerSz = 4;
  std::string _activation = "relu";
public:
  NeuralNetwork();
  void setWeights(int seed = 0);
  void showWeights();
  std::vector<std::vector<double>> getWeight(int layer);
};

#endif
