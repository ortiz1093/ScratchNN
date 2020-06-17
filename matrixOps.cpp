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

void displaySize(std::vector<std::vector<double>> A){
  std::cout << A.size() << " x " << A[0].size() << std::endl;
  std::cout << "\n";
}

std::vector<int> getSize(std::vector<std::vector<double>> A){
  // int rows = A.size();
  // int cols = A[0].size();
  int rows = A.size();
  int cols = A[0].size();
  std::vector<int> size(2);
  size[0] = rows;
  size[1] = cols;

  return size;
};

std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B){
  std::vector<int> sizeA = getSize(A);
  std::vector<int> sizeB = getSize(B);

  if (sizeA[0] != sizeB[1]){
    std::cout << "Matrix size mismatch." << std::endl;
    return {};
  }

  int rows = sizeA[0];
  int cols = sizeB[1];
  int inner = sizeA[1];

  std::vector<std::vector<double>> result;
  double num;

  for (int i = 0; i < rows; i++){
    std::vector<double> row;
    for (int j = 0; j < cols; j++){
      num = 0;
      for (int k = 0; k < inner; k++){
        num += A[i][k]*B[k][j];
      }
      row.push_back(num);
    }
    result.push_back(row);
    delete &row;
  }

  return result;
}

std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> A){
  std::vector<int> size = getSize(A);

  std::vector<std::vector<double>> result;
  std::vector<double> row;

  for (int j = 0; j < size[1]; j++){
    row = {};
    for (int i = 0; i < size[0]; i++){
      row.push_back(A[i][j]);
    }
    result.push_back(row);
  }

  return result;
}
