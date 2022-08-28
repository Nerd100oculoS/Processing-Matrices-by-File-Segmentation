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

void InicializateCOO(COO *c); // Inicializa a struct

/**
 * Funções Gerais 
 */
void ReadFiles();
void PrintMatriz(vector<vector<int> > matriz);

/**
 * Funções relacionadas ao processamento da Matriz;
 */
void ReadFile_BigMatrix(COO *c);
void TokenizarQuadrante(COO *c, string line_token);
void ReadFile_Coordinates(COO *c);
void TokenizarCoodinates(COO *c, string line_token, int count_line);

#endif 