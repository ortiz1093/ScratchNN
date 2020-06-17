#ifndef MATRIXOPS_H
#define MATRIXOPS_H

#include <iostream>
#include <vector>
// #include <cmath>
// #include <math.h>

void displayMat(std::vector<std::vector<double>> A);
void displaySize(std::vector<std::vector<double>> A);
std::vector<int> getSize(std::vector<std::vector<double>> A);
std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B);
std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> A);

#endif
