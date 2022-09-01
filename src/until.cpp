#include "until.hpp"

void InicializateCOO(COO *c) {

    c->p1_i = 0;
    c->p1_j = 0;
    c->p2_i = 0;
    c->p2_j = 0;

    c->size_line = 0;
    c->size_column = 0;

    string key = "";
}

void SizeMatrixAll(COO *c) {

    c->key = to_string(c->p1_i) + ',' + to_string(c->p1_j) + ' ' + to_string(c->p2_i) + ',' + to_string(c->p2_j);
    c->size_line = c->p2_i - c->p1_i+1;
    c->size_column = c->p2_j - c->p1_j+1;
}

void PrintMatrixQuandrant(vector<vector<int> > *v) {

    vector<vector<int> >::iterator it;
    vector<int>::iterator itr;

    for(it = v->begin(); it < v->end(); ++it){

        for(itr = (*it).begin(); itr < (*it).end(); ++itr){cout << *itr << " ";}

        cout << endl;
    }

    
}

void MakeTransposeMatrix(vector<vector<int> > *v, vector<vector<int> > *result, COO *c) {

    for(int i = 0; i < c->size_line; i++){

        for(int j = 0; j < c->size_column; j++){

            result->at(j).at(i) = v->at(i).at(j);
        }
    }

    //PrintMatriz(result);

}

void MakeMultplicationMatrix(vector<vector<int> > *v, vector<vector<int> > *result, vector<vector<int> > *result_final, COO *c) {

    int aux = 0;
    //cout << "Multiplication = " << c->size_line << "," << c->size_column << endl;
    for(int i = 0; i < c->size_line; i++){

        for(int j = 0; j < c->size_column; j++){

            for(int x = 0; x < c->size_line; x++){

                aux += v->at(i).at(x) * result->at(x).at(j);
                //cout << i << "," << x << " ";

            }

            //cout << endl;
            result_final->at(i).at(j) = aux;
            aux = 0;
        }
    }
}

void VerifySizeMatrix() {

    int count_line, count_column;
    count_line = count_column = 0;
    string line, token;
    char del = ',';
    ifstream file("./input/original_matriz.txt");

    if(file.is_open()){

        while(!file.eof()){

            getline(file, line);
            stringstream sstream(line);

            while(getline(sstream, token, del)){

                count_column++;
            }

            count_line++;
        }

        cout << "Tamanho da matrix = (" << count_line << "," << count_column / count_line << ")\n";

    }else{ cout << "Erro ao abrir o arquivo!" << endl; }

    file.close();
    return;
}

void TokenizarCoodinates(COO *c, string line_token, int count_line) {

    stringstream sstream(line_token);
    string token;
    char del = ',';
    int count_column = 0;

    // Da linha 11 a 23 é possivel otimizar pois a repetição de codigo.
    while(getline(sstream, token, del)){

        if(count_column < 2){

            if(count_column == 0){c->p1_i = stoi(token);}
            else{c->p1_j = stoi(token);}
        
        }else{

            if(count_column == 2){c->p2_i = stoi(token);}
            else{c->p2_j = stoi(token);}
        }

        count_column++;
    }
}

void ReadFile_Coordinates(vector<COO> *c){

    string line, token;
    stringstream sstream;
    int count_line, count_column;
    count_line = count_column = 0;
    COO aux;

    ifstream file("./src/input/coordinates.txt");

    if(file.is_open()) {

        while(!file.eof()) {
            
            InicializateCOO(&aux);
            getline(file, line);

            TokenizarCoodinates(&aux,line,count_line);

            SizeMatrixAll(&aux);
            c->push_back(aux);

            count_line++;
        }

        //cout << "p1 = " << c->p1_i << " , " << c->p1_j << endl;
        //cout << "p2 = " << c->p2_i << " , " << c->p2_j << endl;

    }else{ cout << "Erro ao abrir o arquivo!" << endl;}

    file.close();

    for(int i = 0; i < c->size(); i++){

        cout << c->at(i).key << endl;
    
    }

    return;
}

void TokenizarQuadrante(COO *c, string line_token, int cont_line, vector<vector<int> > *v) {

    stringstream sstream(line_token);
    string token;
    stringstream aux;
    char del = ',';
    int count_column = 0;
    int j = 0; // coluna da matriz de armazenamento
    //cont_line // linha da matriz de armazenamento

    while(getline(sstream, token, del)){

        if (count_column >= c->p1_j && count_column <= c->p2_j) {

            //cout << token << " ";
            (*v)[cont_line][j] = stoi(token);

            j++;
        }

        count_column++;
    }
}

void ReadFile_BigMatrix(vector<COO> *c, unordered_map<string, vector<vector<int> > > *Umap) {

    for(int i = 0; i < c->size(); i++){

        string line_string = "";
        int cont_line = 0;
        int count_line = 0; // Começa igual a 1 pois o editor de texto conta linhas a partir de 1.

        if(Umap->find((*c)[i].key) != Umap->end()){

            cout << (*c)[i].key << " está presente no Mapa!" << endl;
        
        }else{

            ifstream file("./src/input/original_matriz.txt");

            vector<vector<int> > v((*c)[i].size_line, vector<int>((*c)[i].size_column));
            //cout << "cria vetor = " << (*c)[i].size_line << "," << (*c)[i].size_column << endl;

            if(file.is_open()){

                while (!file.eof()) {

                    getline(file, line_string);
                    
                    // Erro esta aqui no count_line
                    if (count_line >= (*c)[i].p1_i && count_line <= (*c)[i].p2_i) {

                        //COO aux = c->at(i);
                        TokenizarQuadrante(&(*c)[i], line_string, cont_line, &v);
                        cont_line++;
                    }
                    //cout << endl;
                    count_line++;
                }
                
                //PrintMatriz(&v);
                //count_line = 1;

            } else { cout << "Erro ao abrir o arquivo!" << endl; }

            file.close();
            //cout << endl;
            //PrintMatriz(&v);

            vector<vector<int> > result((*c)[i].size_line, vector<int>((*c)[i].size_column));
            vector<vector<int> > result_final((*c)[i].size_line, vector<int>((*c)[i].size_column));

            MakeTransposeMatrix(&v, &result, &(*c)[i]);
            //PrintMatriz(&result);
            //return;
            MakeMultplicationMatrix(&v, &result, &result_final, &(*c)[i]);

            //cout << endl;
            //PrintMatrixQuandrant(&result_final);
            //cout << endl;

            StorData(Umap, result_final, &(*c)[i]);
            
        }
    }    

    return;
}

void StorData(unordered_map<string, vector<vector<int> > > *Umap, vector<vector<int> > result_final, COO *c) {

    //(*Umap)[c->key].insert(result_final);
    //Umap->insert({c->key, result_final });
    (*Umap)[c->key] = result_final;
}


void PrintMap(unordered_map<string,vector<vector<int> > > *Umap){

    unordered_map<string,vector<vector<int> > >::iterator it;
    vector<vector<int> >::iterator itr;
    vector<int>::iterator itrv;

    for(it = (*Umap).begin(); it != (*Umap).end(); ++it){

        cout << "Key = " << it->first << endl;

        for(itr = it->second.begin(); itr < it->second.end(); ++itr){

            for(itrv = (*itr).begin(); itrv != (*itr).end(); ++itrv){

                cout << *itrv << " ";
            }

            cout << endl;
        }

        cout << endl;
    }

}

//Funcao que testa o funcionamento de todas as funcoes
void ReadFiles(){

    unordered_map<string, vector<vector<int> > > Umap;
    vector<COO> Vc;
    
    ReadFile_Coordinates(&Vc);

    cout << endl << endl;
    ReadFile_BigMatrix(&Vc, &Umap);

    cout << endl;
    PrintMap(&Umap);

    return;
}

void PrintMatriz(vector<vector<int> > *matriz){
    
    vector<vector<int> >::iterator it;
    vector<int>::iterator itr;

    for(it = matriz->begin(); it < matriz->end(); ++it){

        for(itr = (*it).begin(); itr < (*it).end(); ++itr){cout << *itr << " ";}

        cout << endl;
    }

}

