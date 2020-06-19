#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <math.h>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>
#include "matrixOps.h"


/**
* Return max of two numbers, a and b.
* @param a number to be evaluated
* @param b number to be evaluated
* @return the highest value between a and b
*/
double max(double a, double b);

/**
* Calculate the logistic sigmoid value of x.
* @param x input value
* @return logistic sigmoid of x
*/
double sigmoid(double x);

/**
* Normalizes each row or column of a matrix into a probability distribution.
* @param X input matrix
* @param axis direction along which to normalize
* @return Probability distributions for the vectors in X
*/
std::vector<std::vector<double>> softmax(std::vector<std::vector<double>> X, int axis = 1);

/**
* Applies a chosen activation function to a value
* @param x value to be evaluated
* @param fcn the name of the activation to be applied
* @return the output of the selected function given the input x
*/
double activate(double x, std::string fcn);

/**
* Applies a chosen activation function to each element in a matrix
* @param mat m x n matrix to be evaluated
* @param activation the name of the activation to be applied
* @return m x n matrix containing outputs of the activation fcn provided
*/
std::vector<std::vector<double>> matrixActivation(std::vector<std::vector<double>> mat, std::string activation);

#endif
