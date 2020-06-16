#include "activation.h"

double max(double a, double b){
  if (a > b){
    return a;
  } else {
    return b;
  }
}

double sigmoid(double x){
  return 1/(1 + exp(-x));
}
