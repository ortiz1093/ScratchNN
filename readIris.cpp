#include "readIris.h"

std::vector<double> line2vec(std::string line){
  /**
  * Convert delimited numeric string to vector<double>.
  *
  * Assumes delimiters are single-char and non-numeric. Agnostic to delimiter
  * type. No built-in error handling.
  *
  * @param line: string of delimiter-separated numeric values
  * @return 1-D vector of double precision values.
  */

  //Initialize vars
  std::string::size_type sz = 0; //Set sz to default type for std::string.size()
  std::vector<double> result;

  while (sz <= line.length()) {
    line = line.substr(sz); //Return substring of line beginning at sz
    double num = std::stod (line,&sz); //Reads line until 1st non-numeric char
                                       //Sets sz to index of delimiter
                                       //Assign numeric substr to num as double
    sz++; //Skip delimiter for next iteration
    result.push_back(num); //Append num to end of output vector
  }

  return result;
}

std::vector<std::vector<double>> readIris(std::string filename){
  /**
  * Convert csv file to 2-D vector<double>.
  *
  * Design specifically for iris.data file. May need modification for others.
  * Assumes no headers, and that delimiters are single-char and non-numeric.
  * Agnostic to delimiter type. No built-in error handling.
  *
  * @param filename: (string) full path to file
  * @return 2-D vector of double precision values.
  */

  //Initialize vars
  std::vector<std::vector<double>> result;
  std::vector<double> row;
  std::string line;

  std::ifstream myFile(filename); //Open filename

  //Loop over lines in filename
  while (std::getline(myFile,line)){
    row = line2vec(line); //Convert each line to 1-D vector<double>
    result.push_back(row); //Append row vector to end of 2-D result vector
  }

  myFile.close(); //Closefile

  return result;

}
