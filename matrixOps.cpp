#include "matrixOps.h"

void displayMat(std::vector<std::vector<double>> A){
  for (int i = 0; i < A.size(); i++){
    for (int j = 0; j < A[i].size(); j++){
      std::cout << A[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B){
  std::vector<std::vector<double>> result;
  double num;

  for (int i = 0; i < A.size(); i++){
    std::vector<double> row;
    for (int j = 0; j < B[0].size(); j++){
      num = 0;
      for (int k = 0; k < A[0].size(); k++){
        num += A[i][k]*B[k][j];
      }
      row.push_back(num);
    }
    result.push_back(row);
    delete &row;
  }

  return result;
}
