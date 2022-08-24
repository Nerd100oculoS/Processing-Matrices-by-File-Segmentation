#ifndef UNTIL_HPP
#define UNTIL_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void ReadFile(string name_arq);
void PrintMatriz(vector<vector<int> > matriz);
void Tokenizar(stringstream line_token, vector<vector<int> > matriz);

#endif 