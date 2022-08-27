#ifndef UNTIL_HPP
#define UNTIL_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef struct Coodinates{

    //Coordenadas P1
    int p1_i;
    int p1_j;

    //Coordenadas P2
    int p2_i;
    int p2_j;

}COO;

void ReadFiles();
void PrintMatriz(vector<vector<int> > matriz);

void ReadFile_BigMatrix();
void TokenizarMatrix(string line_token, int count_line);

void ReadFile_Coordinates();
void TokenizarCoodinates(COO *c, string line_token, int count_line);
#endif 