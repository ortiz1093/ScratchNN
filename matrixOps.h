#ifndef MATRIXOPS_H
#define MATRIXOPS_H

#include <iostream>
#include <vector>
#include <utility>

/**
* Determines if a value lies on an closed interval
* @param x value to be evaluated
* @param lo lower bound of the closed interval, inclusive
* @param hi upper bound of the closed interval, inclusive
* @return true if x on the interval, else false
*/
bool between(double lo, double hi, double x);

/**
* Prints a matrix to the console
* @param A matrix to be displayed
* @return Nothing
*/
void displayMat(std::vector<std::vector<double>> A);

/**
* Prints the first 5 rows and 10 columns of a matrix to the console
* for preview
* @param A matrix to be displayed
* @return Nothing
*/
void headMat(std::vector<std::vector<double>> A);

/**
* Prints the size of a matrix to the console as (rows x cols)
* @param A matrix to be displayed
* @return Nothing
*/
void displaySize(std::vector<std::vector<double>> A);

/**
* Returns the size of a matrix to the calling program as {rows, cols}
* @param A matrix from which to get the size
* @return vector containing the rows and cols of A
*/
std::vector<int> getSize(std::vector<std::vector<double>> A);

/**
* Performs matrix multiplication on A and B
* @param A m x n LHS matrix
* @param B n x p RHS matrix
* @return m x p matrix product
*/
std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B);

/**
* Performs matrix tranpose on A
* @param A m x n matrix
* @return n x m matrix tranpose of A
*/
std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> A);

/**
* Creates a submatrix of A
* @param A m x n matrix
* @param rows vector containing first and last+1 row index of A for submatrix
* @param cols vector containing first and last+1 col index of A for submatrix
* @return p x q submatrix of A
*/
std::vector<std::vector<double>> submatrix(std::vector<std::vector<double>> A, std::vector<int> rows, std::vector<int> cols);

#endif
