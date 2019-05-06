#include "Matriz.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

Matriz::Matriz(){
    this->_numero_de_linhas = 0;
    this->_numero_de_colunas = 0;
}

Matriz::Matriz(unsigned int linhas, unsigned int colunas, const double &valor=0){
    while(linhas==0 || colunas==0){
        cout << "Favor inserir valor válido" << endl;
        cin >> linhas;
        cin >> colunas;
    }

    this->_numero_de_linhas = linhas;
    this->_numero_de_colunas = colunas;

    this->M = new double*[linhas];
    for (unsigned int i = 0; i < linhas; ++i)
        this->M[i] = new double[colunas];

    for(unsigned int i = 0; i < linhas; i++)
        for(unsigned int j = 0; j < colunas; j++)
            this->M[i][j] = valor;
}


Matriz::Matriz(const Matriz &m){
    this->_numero_de_linhas = m._numero_de_linhas;
    this->_numero_de_colunas = m._numero_de_colunas;

    this->M = new double*[_numero_de_linhas];
    for (unsigned int i = 0; i < _numero_de_linhas; ++i)
        this->M[i] = new double[_numero_de_colunas];

    for(unsigned int i = 0; i < _numero_de_linhas; i++)
        for(unsigned int j = 0; j < _numero_de_colunas; j++)
            this->M[i][j] = m.M[i][j];
}

Matriz::~Matriz(){
   for(unsigned int i = 0; i < this->_numero_de_linhas; ++i)
        delete [] this->M[i];
    delete [] this->M;
}

int Matriz::ValorLinha(){
    int linhas;
    cout << "Insira a quantidade de linhas da matriz:" << endl;
    cin >> linhas;
    this->_numero_de_linhas = linhas;
    return linhas;
}

int Matriz::ValorColuna(){
    int colunas;
    cout << "Insira a quantidade de colunas da matriz:" << endl;
    cin >> colunas;
    this->_numero_de_colunas = colunas;
    return colunas;
}

void Matriz::MatrizIdentidade(){
    for(unsigned int i = 0; i < this->_numero_de_linhas; i++){
        for(unsigned int j = 0; j < this->_numero_de_colunas; j++){
            if (i == j){
                this->M[i][j] = 1;
            }
            else{
                this->M[i][j] = 0;
            }
        }
    }
}

void Matriz::AlteraValor(){
    unsigned int nL, nC;
    cout << "Digite a posicao que voce deseja alterar:" << endl;
    cin >> nL;
    cin >> nC;
    cout << "Digite o valor que deseja inserir:" << endl;
    cin >> this->M[nL-1][nC-1];
}

/*Matriz Matriz::SomaMatriz(Matriz a){
    if(this->_numero_de_linhas!=a._numero_de_linhas && this->_numero_de_colunas!=a._numero_de_colunas){
       cout << "Operacao invalida!";
       exit(-1);
    }
    else{
        Matriz aux;
        for(unsigned int i = 0; i < a._numero_de_linhas; i++)
        for(unsigned int j = 0; j < a._numero_de_colunas; j++)
            aux.M[i][j] = this->M[i][j] + a.M[i][j];
        return aux;
    }
}
*/

Matriz& Matriz::operator+=(const Matriz &a){

    for(unsigned int i = 0; i < this->_numero_de_linhas; i++)
        for(unsigned int j = 0; j < this->_numero_de_colunas; j++)
            this->M[i][j] += a.M[i][j];

    return *this;
}

Matriz Matriz::operator+(const Matriz &a) const{
    if(this->_numero_de_linhas!=a._numero_de_linhas && this->_numero_de_colunas!=a._numero_de_colunas){
       cout << "Operacao invalida!";
       exit(-1);
    }
    Matriz m(*this);
    m += a;
    return m;
}

/*Matriz Matriz::SubtraiMatriz(Matriz a){
    if(this->_numero_de_linhas!=a._numero_de_linhas && this->_numero_de_colunas!=a._numero_de_colunas){
       cout << "Operacao invalida!";
       exit(-1);
    }
    else{
        Matriz aux;
        for(unsigned int i = 0; i < a._numero_de_linhas; i++)
        for(unsigned int j = 0; j < a._numero_de_colunas; j++)
            aux.M[i][j] = this->M[i][j] - a.M[i][j];
        return aux;
    }
}
*/

Matriz& Matriz::operator-=(const Matriz &a){

    for(unsigned int i = 0; i < this->_numero_de_linhas; i++)
        for(unsigned int j = 0; j < this->_numero_de_colunas; j++)
            this->M[i][j] -= a.M[i][j];

    return *this;
}

Matriz Matriz::operator-(const Matriz &a) const{
    if(this->_numero_de_linhas!=a._numero_de_linhas && this->_numero_de_colunas!=a._numero_de_colunas){
       cout << "Operacao invalida!";
       exit(-1);
    }
    Matriz m(*this);
    m -= a;
    return m;
}

/*Matriz Matriz::Trasposta(){
    Matriz aux;
    for(unsigned int i = 0; i < this->_numero_de_linhas; i++)
        for(unsigned int j = 0; j < this->_numero_de_colunas; j++)
            aux.M[i][j] = this->M[j][i];
    return aux;
}
*/

Matriz Matriz::operator~() const{
    Matriz aux;
    aux._numero_de_linhas = this->_numero_de_colunas;
    aux._numero_de_colunas = this->_numero_de_linhas;
    for(unsigned int i = 0; i < this->_numero_de_linhas; i++)
        for(unsigned int j = 0; j < this->_numero_de_colunas; j++)
            aux.M[i][j] = this->M[j][i];

    return aux;
}

/*Matriz Matriz::MultiplicaMatrizes(Matriz a){
    Matriz m;
    if(this->_numero_de_colunas != a._numero_de_linhas){
        cout << "Operacao invalida!";
        exit(-1);
    }
    else{
        int Aux=0;
        m._numero_de_linhas=this->_numero_de_linhas;
        m._numero_de_colunas=a._numero_de_colunas;
        for(unsigned int i=0; i<this->_numero_de_linhas; i++){
            for(unsigned int j=0; j<a._numero_de_colunas; j++){
                 m.M[i][j]=0;
                 for(unsigned int k=0; k<a._numero_de_linhas; k++){
                    Aux += this->M[i][k] * a.M[k][j];
                 }
                 m.M[i][j]=Aux;
                 Aux=0;
            }
        }
    }
    return m;
}
*/

Matriz Matriz::operator*=(const Matriz &a) const {
    if(this->_numero_de_colunas != a._numero_de_linhas){
        cout << "Operacao invalida!";
        exit(-1);
    }
    else{
        Matriz m(*this);
        int Aux=0;

        m._numero_de_linhas=this->_numero_de_linhas;
        m._numero_de_colunas=a._numero_de_colunas;
        for(unsigned int i=0; i<this->_numero_de_linhas; i++){
            for(unsigned int j=0; j<a._numero_de_colunas; j++){
                m.M[i][j]=0;
                for(unsigned int k=0; k<a._numero_de_linhas; k++){
                    Aux += this->M[i][k] * a.M[k][j];
                }
                m.M[i][j]=Aux;
                Aux=0;
            }
        }
        return m;
    }
}
Matriz Matriz::operator*(const Matriz &a) const {
    if(this->_numero_de_colunas != a._numero_de_linhas){
        cout << "Operacao invalida!";
        exit(-1);
    }
    else{
        Matriz m(*this);
        int Aux=0;

        m._numero_de_linhas=this->_numero_de_linhas;
        m._numero_de_colunas=a._numero_de_colunas;
        for(unsigned int i=0; i<this->_numero_de_linhas; i++){
            for(unsigned int j=0; j<a._numero_de_colunas; j++){
                m.M[i][j]=0;
                for(unsigned int k=0; k<a._numero_de_linhas; k++){
                    Aux += this->M[i][k] * a.M[k][j];
                }
                m.M[i][j]=Aux;
                Aux=0;
            }
        }
        return m;
    }
}
/*int Matriz::Igualdade(Matriz a){
    unsigned int cont=0;
    if(this->_numero_de_linhas!=a._numero_de_linhas || this->_numero_de_colunas!=a._numero_de_colunas){
        cont = 0;
    }
    else{
        for(unsigned int i = 0; i < this->_numero_de_linhas; i++){
            for(unsigned int j = 0; j < this->_numero_de_colunas; j++){
                if(this->M[i][j] == a.M[i][j]){
                    cont += 1;
                }
            }
        }
    }
    if (cont == (a._numero_de_linhas*a._numero_de_colunas))
        return 1;
    else
        return 0;
}
*/

int Matriz::operator==(const Matriz &a) const{
    unsigned int cont=0;
    if(this->_numero_de_linhas!=a._numero_de_linhas || this->_numero_de_colunas!=a._numero_de_colunas){
        cont = 0;
    }
    else{
        for(unsigned int i = 0; i < this->_numero_de_linhas; i++){
            for(unsigned int j = 0; j < this->_numero_de_colunas; j++){
                if(this->M[i][j] == a.M[i][j]){
                    cont += 1;
                }
            }
        }
    }

    if (cont == (a._numero_de_linhas*a._numero_de_colunas))
        return 1;
    else
        return 0;
}

int Matriz::operator!=(const Matriz &a) const{
    unsigned int cont=0;
    if(this->_numero_de_linhas!=a._numero_de_linhas || this->_numero_de_colunas!=a._numero_de_colunas){
        cont = 0;
    }
    else{
        for(unsigned int i = 0; i < this->_numero_de_linhas; i++){
            for(unsigned int j = 0; j < this->_numero_de_colunas; j++){
                if(this->M[i][j] != a.M[i][j]){
                    cont += 1;
                }
            }
        }
    }

    if (cont == (a._numero_de_linhas*a._numero_de_colunas))
        return 1;
    else
        return 0;
}


/*void Matriz::ImprimeMatriz(){
    for(unsigned int i = 0; i < this->_numero_de_linhas; i++) {
        for(unsigned int j = 0; j < this->_numero_de_colunas; j++)
            cout << this->M[i][j] << "\t";
        cout << endl;
    }
}
*/

/*void Matriz::LeituraMatriz(){
    cout << "Insira os valores da matriz:" << endl;
    for(unsigned int i = 0; i < this->_numero_de_linhas; i++)
        for(unsigned int j = 0; j < this->_numero_de_colunas; j++)
            cin >> this->M[i][j];
}
*/

void Matriz::ModificaElementos0(){
    for(unsigned int i = 0; i < this->_numero_de_linhas; i++){
        for(unsigned int j = 0; j < this->_numero_de_colunas; j++){
            this->M[i][j] = 0;
        }
    }
}

void Matriz::ModificaElementos1(){
    for(unsigned int i = 0; i < this->_numero_de_linhas; i++){
        for(unsigned int j = 0; j < this->_numero_de_colunas; j++){
            this->M[i][j] = 1;
        }
    }
}

Matriz& Matriz::operator=( const Matriz &m ){
    for (unsigned int i = 0; i < m._numero_de_linhas; ++i)
        memcpy(this->M[i], m.M[i], sizeof(int) * m._numero_de_colunas);

    return *this;
}

ostream &operator<<(ostream &out, const Matriz &m ){
    for(unsigned int i = 0; i < m._numero_de_linhas; i++) {
        for(unsigned int j = 0; j < m._numero_de_colunas; j++)
            out << m.M[i][j] << "\t";
        out << endl;
    }
    return out;
}

istream &operator>>(istream &in, Matriz &m){
    for(unsigned int i = 0; i < m._numero_de_linhas; i++)
        for(unsigned int j = 0; j <m._numero_de_colunas; j++){
            cout << "(" << i << "," << j << "): ";
            in >> m.M[i][j];
        }
    return in;
}

int Matriz::get_numero_de_linhas(){
    return _numero_de_linhas;
}
int Matriz::get_numero_de_colunas(){
    return _numero_de_colunas;
}
