#include "until.hpp"

void TokenizarCoodinates(COO *c, string line_token, int count_line){
    
    stringstream sstream(line_token);
    string token;
    char del = ',';
    int count_column = 0; 

    // Da linha 11 a 23 é possivel otimizar pois a repetição de codigo.
    while(getline(sstream,token,del)){

        if(count_line == 1){
             
            if(count_column == 0){c->p1_i = stoi(token);}
            else{c->p1_j = stoi(token);}
        
        }else{

            if(count_column == 0){c->p2_i = stoi(token);}
            else{c->p2_j = stoi(token);}
            
        }

        count_column++;
    }
}

void ReadFile_Coordinates(){

    COO c;
    string line, token;
    int count_line = 1;

    ifstream file("./src/input/coordinates.txt");

    if(file.is_open()){

        while(!file.eof()){

            getline(file,line);

            TokenizarCoodinates(&c,line,count_line);

            count_line++;
        }
    }

    cout << "p1 = " << c.p1_i << " , " << c.p1_j << endl;
    cout << "p2 = " << c.p2_i << " , " << c.p2_j << endl;

}

void TokenizarMatrix(string line_token, int count_line){

    stringstream sstream(line_token);
    string token;
    char del = ' '; //space é o delimitador
    int count_column = 0;

    while(getline(sstream,token,del)){

        count_column++;
    }

    cout << "quantidade de colunas na linha " << count_line << " = " << count_column << endl;
}

void ReadFile_BigMatrix(){

    string line, token;
    int count_line = 1;

    ifstream file("./src/input/original_matriz.txt");

    if(file.is_open()){

        while(!file.eof()){

            getline(file,line);

            TokenizarMatrix(line,count_line);

            count_line++;
        }
    }

}