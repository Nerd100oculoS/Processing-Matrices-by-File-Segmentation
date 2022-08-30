#include "until.hpp"

void InicializateCOO(COO *c){

    c->p1_i = 0;
    c->p1_j = 0;
    c->p2_i = 0;
    c->p2_j = 0;

    c->size_line = 0;
    c->size_column = 0;
}

void SizeMatrixAll(COO *c){

    c->size_line = c->p2_i - c->p1_i + 1;
    c->size_column = c->p2_j - c->p1_j + 1;

}

void PrintMatrixQuandrant(vector<vector<int> > *v){

    vector<vector<int> >::iterator it,itr;
    
    for(it = v->begin(); it < v->end(); ++it){

        for(int n: *it){

            cout << n << " ";
        }

        cout << endl;
    }
}

void MakeTransposeMatrix(vector<vector<int> > *v, vector<vector<int> > *result, COO *c){
    
    for(int i = 0; i < c->size_line; i++){
        
        for(int j = 0; j < c->size_column; j++){

            result->at(j).at(i) = v->at(i).at(j);
        }
    }

}

void MakeMultplicationMatrix(vector<vector<int> > *v,vector<vector<int> > *result, vector<vector<int> > *result_final, COO *c){

    int aux = 0;

    for(int i = 0; i < c->size_line; i++){
        
        for(int j = 0; j < c->size_column; j++){

            for(int x = 0; x < c->p2_i; x++){

                aux += v->at(i).at(x) * result->at(x).at(j);
            
            }

            result_final->at(i).at(j) = aux;
            aux = 0;
        }
    }
}

void VerifySizeMatrix(){

    int count_line, count_column;
    count_line = count_column = 0;
    string line, token;
    char del = ','; 
    ifstream file("./src/input/original_matriz.txt");

    if(file.is_open()){

        while(!file.eof()){

            getline(file,line);        
            stringstream sstream(line);

            while(getline(sstream,token,del)){

                count_column++;
            }
    
            count_line++;
        }

        cout << "Tamanho da matrix = (" << count_line << "," << count_column/count_line << ")\n";

    }else{cout << "Erro ao abrir o arquivo!" << endl;}

    file.close();
    return;
}

void TokenizarCoodinates(COO *c, string line_token, int count_line){
 
    stringstream sstream(line_token);
    string token;
    char del = ',';
    int count_column = 0; 

    // Da linha 11 a 23 é possivel otimizar pois a repetição de codigo.
    while(getline(sstream,token,del)){

        if(count_line == 0){
             
            if(count_column == 0){c->p1_i = stoi(token);}
            else{c->p1_j = stoi(token);}
        
        }else{

            if(count_column == 0){c->p2_i = stoi(token);}
            else{c->p2_j = stoi(token);}
            
        }

        count_column++;
    }
}

void ReadFile_Coordinates(COO *c){

    string line, token;
    int count_line = 0;

    ifstream file("./src/input/coordinates.txt");

    if(file.is_open()){

        while(!file.eof()){

            getline(file,line);

            TokenizarCoodinates(c,line,count_line);

            count_line++;
        }

        cout << "p1 = " << c->p1_i << " , " << c->p1_j << endl;
        cout << "p2 = " << c->p2_i << " , " << c->p2_j << endl;

    }else{cout << "Erro ao abrir o arquivo!" << endl;}

    file.close();
    return;
}


void TokenizarQuadrante(COO *c, string line_token, int cont_line, vector<vector<int> > *v){

    stringstream sstream(line_token);
    string token;
    stringstream aux;
    char del = ',';
    int count_column = 1;
    int j = 0; // coluna da matriz de armazenamento
    //cont_line // linha da matriz de armazenamento 
    
    while(getline(sstream,token,del)){

        if(count_column >= c->p1_j && count_column <= c->p2_j){

            //cout << token << " ";
            v->at(cont_line).at(j) = stoi(token);
            
            j++;
        }

        count_column++;
    }
    
    //cout << endl;
}

void ReadFile_BigMatrix(COO *c){

    SizeMatrixAll(c);
    string line_string;
    int count_line = 1;
    ifstream file("./src/input/original_matriz.txt");
    int cont_line = 0;
    
    //int lineI = c->p2_i - c->p1_i + 1;
    //int column = c->p2_j - c->p1_j + 1;
    cout << c->size_line << "," << c->size_column << endl;

    vector<vector<int> > v(c->size_line, vector<int> (c->size_column));

    if(file.is_open()){

        while(!file.eof()){

            getline(file,line_string);

            if(count_line >= c->p1_i && count_line <= c->p2_i){
                
                TokenizarQuadrante(c,line_string,cont_line, &v);
                cont_line++;
            }
            //cout << endl;
            count_line++;
            
        }

    }else{cout << "Erro ao abrir o arquivo!" << endl;}

    file.close();
    //cout << endl << endl;
    PrintMatrixQuandrant(&v);
    //ImprimeMatriz(m,lineI,column);
    cout << endl;

    vector<vector<int> > result(c->size_line, vector<int> (c->size_column));
    vector<vector<int> > result_final(c->size_line, vector<int> (c->size_column));
    MakeTransposeMatrix(&v, &result,c);
    MakeMultplicationMatrix(&v, &result,&result_final, c);

    PrintMatrixQuandrant(&result_final);

    return;
}

void ReadFiles(){

    VerifySizeMatrix();
    
    COO c;
    InicializateCOO(&c);
    
    ReadFile_Coordinates(&c);
    cout << endl << endl;
    ReadFile_BigMatrix(&c);

    return;
}
