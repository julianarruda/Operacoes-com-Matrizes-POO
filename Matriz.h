//*****************************TRABALHO PRÁTICO I - PROGRAMAÇÃO ORIENTADA A OBJETOS **********************************************//
#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Matriz{
public:
    Matriz(); //cria uma matriz vazia com número de linhas e colunas iguais a 0.
    Matriz(unsigned int linhas, unsigned int colunas, const double &valor); //cria uma matriz com o número de linhas e colunas iguais aos recebidos pelos argumentos.
    Matriz(const Matriz &m); //Construtor de cópia.
    ~Matriz(); //destrutor.
    void MatrizIdentidade();
    void AlteraValor(); //Altera o valor de uma posição da matriz.
    void ModificaElementosY(); //Modifica os elementos da matriz para 0.
    double ModificaElementosX(); //Modifica os elementos da Matriz com 1.
    Matriz SomaMatriz(Matriz a);
    double SubtraiMatriz(Matriz a);
    double Trasposta();
    double MultiplicaMatrizes(Matriz a);
    int Igualdade(Matriz a); //Verifica se duas Matrizes são iguais.
    void ImprimeMatriz();
    void LeituraMatriz();
private:
    int _numero_de_linhas;
    int _numero_de_colunas;
    double **M;
};

#endif // MATRIZ_H
