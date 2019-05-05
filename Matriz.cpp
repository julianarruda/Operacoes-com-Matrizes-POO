#include "Matriz.h"

using namespace std;

Matriz::Matriz(){
    _numero_de_linhas = 0;
    _numero_de_colunas = 0;
}

Matriz::Matriz(unsigned int linhas, unsigned int colunas, const double &valor){
    while(linhas==0 || colunas==0){
        cout << "Favor inserir valor válido" << endl;
        cin >> linhas;
        cin >> colunas;
    }
    this->_numero_de_linhas = linhas;
    this->_numero_de_colunas = colunas;
    for(unsigned int i=0; i < _numero_de_linhas; i++){
        for(unsigned int j=0; j < _numero_de_colunas; j++){
            M[i][j] = valor;
        }
    }
}

Matriz::Matriz(const Matriz &m){
    this->_numero_de_linhas = m._numero_de_linhas;
    this->_numero_de_colunas = m._numero_de_colunas;
    for (unsigned int i = 0; i < _numero_de_linhas; ++i)
        this->M[i] = new int[_numero_de_colunas];
    for(unsigned int i = 0; i < _numero_de_linhas; i++)
        for(unsigned int j = 0; j < _numero_de_colunas; j++)
            this->M[i][j] = m.M[i][j];
}

Matriz::~Matriz(){
    //destrui a matriz
}

void Matriz::MatrizIdentidade(){
    for(unsigned int i = 0; i < this->_numero_de_linhas; i++){
        for(unsigned int j = 0; j < this->_numero_de_colunas; j++){
            if (_numero_de_linhas==_numero_de_colunas)
                this->M[i][j] = 1;
            else
                this->M[i][j] = 0;
        }
    }
}

void Matriz::AlteraValor(){
    unsigned int nL, nC;
    char resp[3];
    cout << "Digite a posicao que voce deseja alterar:" << endl;
    cin >> nL;
    cin >> nC;
    cout << "Digite o valor que deseja inserir:" << endl;
    cin >> this->M[nL][nC];
}

Matriz Matriz::SomaMatriz(Matriz a){
    if(this->_numero_de_linhas!=a._numero_de_linhas && this->_numero_de_colunas!=a._numero_de_colunas){
       cout << "Operacao invalida!";
       exit(-1);
    }
    else{
        Matriz aux;
        for(unsigned int i = 0; i < _numero_de_linhas; i++)
        for(unsigned int j = 0; j < _numero_de_colunas; j++)
            aux.M[i][j] = this->M[i][j] + a.M[i][j];

        return aux;
    }
}
