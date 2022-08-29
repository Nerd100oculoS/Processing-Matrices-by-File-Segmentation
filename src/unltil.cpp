#include "until.hpp"

void InicializateCOO(COO *c){

    c->p1_i = 0;
    c->p1_j = 0;
    c->p2_i = 0;
    c->p2_j = 0;

}

void VerifySizeMatrix(){

    int count_line, count_column;
    count_line = count_column = 0;
    string line, token;
    char del = ' '; 
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

void TokenizarQuadrante(COO *c, string line_token){

    stringstream sstream(line_token);
    string token;
    char del = ' ';
    int count_column = 1;

    while(getline(sstream,token,del)){

        if(count_column >= c->p1_j && count_column <= c->p2_j){

            cout << token << " ";
        }

        count_column++;
    }
    
    cout << endl;
}

void ReadFile_BigMatrix(COO *c){

    string line;
    int count_line = 1;
    ifstream file("./src/input/original_matriz.txt");

    if(file.is_open()){

        while(!file.eof()){

            getline(file,line);

            if(count_line >= c->p1_i && count_line <= c->p2_i){
                
                TokenizarQuadrante(c,line);

            }
            //cout << endl;
            count_line++;
            
        }

    }else{cout << "Erro ao abrir o arquivo!" << endl;}

    file.close();
    return;
}

void ReadFiles(){

    VerifySizeMatrix();
    
    COO c;
    InicializateCOO(&c);
    
    ReadFile_Coordinates(&c);
    cout << endl << endl;
    ReadFile_BigMatrix(&c);

    //cout << "p1 = " << c.p1_i << " , " << c.p1_j << endl;
    //cout << "p2 = " << c.p2_i << " , " << c.p2_j << endl;
    return;
}