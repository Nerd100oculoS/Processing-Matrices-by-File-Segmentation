#ifndef UNTIL_HPP
#define UNTIL_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef struct Coodinates{

    //Coordenadas P1
    int p1_i;
    int p1_j;

    //Coordenadas P2
    int p2_i;
    int p2_j;

    //Tamanho da matriz
    int size_line;
    int size_column;

    string key;

}COO;

/**
 * Funcoes auxiliares importantes
 */
void InicializateCOO(COO *c); // Inicializa a struct

/**
 * Funções Gerais 
 */
void ReadFiles();
void ReadFileAutomatic();
void SizeMatrixAll(COO *c); // coloca o tamanho das matrizes e cria a chave
void VerifySizeMatrix(); //Verifica quantas linhas e quantas colunas a matriz possui.
void PrintMatrixQuandrant(vector<vector<int> > *v);

// Funcões relacionadas ao Map
void StorData(unordered_map<string,vector<vector<int> > > *Umap, vector<vector<int> > result_final, COO *c);
void PrintMap(unordered_map<string,vector<vector<int> > > *Umap);


/**
 * Funções relacionadas ao processamento da Matriz;
 */
void ReadFile_BigMatrix(vector<COO> *c, unordered_map<string,vector<vector<int> > > *Umap);
void TokenizarQuadrante(COO *c, string line_token,int cont_line, vector<vector<int> > *v);
void ReadFile_Coordinates(vector<COO> *c);
void TokenizarCoodinates(COO *c, string line_token, int count_line);

void MakeTransposeMatrix(vector<vector<int> > *v, vector<vector<int> > *result, COO *c);
void MakeMultplicationMatrix(vector<vector<int> > *v, vector<vector<int> > *result, vector<vector<int> > *result_final, COO *c);

#endif 