//*****************************TRABALHO PRÁTICO I - PROGRAMAÇÃO ORIENTADA A OBJETOS **********************************************//
#ifndef _MATRIZ_H
#define _MATRIZ_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Matriz{
public:
    Matriz(); //cria uma matriz vazia com número de linhas e colunas iguais a 0.
    Matriz(int linhas, int colunas, const double &valor = 0); //cria uma matriz com o número de linhas e colunas iguais aos recebidos pelos argumentos.
    Matriz(const Matriz &m); //Construtor de cópia.
    ~Matriz(); //destrutor.
    double MatrizIdentidade();
    double AlteraValor(); //Altera o valor de uma posição da matriz.
    double ModificaElementosY(); //Modifica os elementos da matriz para 0.
    double ModificaElementosX(); //Modifica os elementos da Matriz com 1.
    double SomaMatriz();
    double SubtraiMatriz();
    double Trasposta();
    double MultiplicaMatrizes();
    double Igualdade(); //Verifica se duas Matrizes são iguais.
    double ImprimeMatriz();
    double LeituraMatriz();
private:
    int _numero_de_linhas;
    int _numero_de_colunas;
};
#endif // _MATRIZ_H
