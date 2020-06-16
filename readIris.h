#ifndef READIRIS_H
#define READIRIS_H

#include <string>
#include <fstream>
#include <vector>

std::vector<double> line2vec(std::string line);
std::vector<std::vector<double>> readIris(std::string filename);

#endif
