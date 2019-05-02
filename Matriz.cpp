#include "Matriz.h"

Matriz::Matriz(){
    int _numero_de_linhas = linhas;
    linhas = 0;
    int _numero_de_colunas = colunas;
    colunas = 0;
}
Matriz::Matriz(int linhas, int colunas, const double &valor = 0){
}

Matriz::Matriz(const Matriz &m){
}

Matriz::~Matriz(){
}
