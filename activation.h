#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <math.h>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>
#include "matrixOps.h"

double max(double a, double b);
double sigmoid(double x);
std::vector<std::vector<double>> softmax(std::vector<std::vector<double>> X, int axis = 1);
double activate(double x, std::string fcn);
std::vector<std::vector<double>> matrixActivation(std::vector<std::vector<double>> mat, std::string activation);

#endif
