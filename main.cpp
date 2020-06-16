#include "activation.h"
#include "readIris.h"
#include  <iostream>

int main () {
  std::string file = "./DATA/10-working/iris.csv";

  std::vector<std::vector<double>> result = readIris(file);

  for (int i = 0; i < result.size(); i++){
    for (int j = 0; j < result[i].size(); j++){
      std::cout << result[i][j] << " ";
    }
    std::cout << "\n";
  }


  return 0;
}
