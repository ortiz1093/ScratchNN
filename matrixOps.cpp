#include "matrixOps.h"

// Determines if a value lies on an closed interval
bool between(double lo, double hi, double x){
  bool ans = false;

  if (x >= lo && x <= hi){
    ans = true;
  }

  return ans;
}

// Prints a matrix to the console
void displayMat(std::vector<std::vector<double>> A){
  for (int i = 0; (double)i < A.size(); i++){
    for (int j = 0; (double)j < A[i].size(); j++){
      std::cout << A[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

// Prints the first 5 rows and 10 columns of a matrix to the console
void headMat(std::vector<std::vector<double>> A){
  for (int i = 0; i < std::min(5,(int)A.size()); i++){
    for (int j = 0; j < std::min(10,(int)A[i].size()); j++){
      std::cout << A[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

// Prints the size of a matrix to the console as rows x cols
void displaySize(std::vector<std::vector<double>> A){
  std::cout << A.size() << " x " << A[0].size() << std::endl;
  std::cout << "\n";
}

// Returns the size of a matrix to the calling program as {rows, cols}
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

// Performs matrix multiplication on A and B
std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B){
  std::vector<int> sizeA = getSize(A);
  std::vector<int> sizeB = getSize(B);

  if (sizeA[1] != sizeB[0]){
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

// Performs matrix tranpose on A
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

// Creates a submatrix of A
std::vector<std::vector<double>> submatrix(std::vector<std::vector<double>> A, std::vector<int> rows, std::vector<int> cols){
  int maxRows = getSize(A)[0];
  int maxCols = getSize(A)[1];
  int rowBegin = 0, rowEnd = maxRows, colBegin = 0, colEnd = maxCols;

  if (!between(0,2,rows.size())){
    std::cout << "'rows' may only contain 0, 1, or 2 elements." << std::endl;
  } else if (rows[0] >= rows[1]){
    std::cout << "rows[0] must be less than rows[1]" << std::endl;
  }

  if (rows.size()==1 && between(1, maxRows - 1, rows[0])){
    rowBegin = rows[0];
    rowEnd = rows[0] + 1;
  }

  if (rows.size()==2 && between(1, maxRows - 1, rows[1])){
    rowEnd = rows[1];
  }

  if (!between(0,2,cols.size())){
    std::cout << "'cols' may only contain 0, 1, or 2 elements." << std::endl;
  } else if (cols[0] >= cols[1]){
    std::cout << "cols[0] must be less than cols[1]" << std::endl;
  }

  if (cols.size()==1 && between(1, maxCols, cols[0])){
    colBegin = cols[0];
    colEnd = cols[0] + 1;
  }

  if (cols.size()==2 && between(0, maxCols, cols[1])){
    colEnd = cols[1];
  }

  std::vector<std::vector<double>> result;
  std::vector<double> row;
  double num;

  for (int i = rowBegin; i < rowEnd; i++){
    row = {};
    for (int j = colBegin; j < colEnd; j++){
      num = A[i][j];
      row.push_back(num);
    }
    result.push_back(row);
  }

  return result;

}
