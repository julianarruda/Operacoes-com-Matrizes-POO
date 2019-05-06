//*****************************TRABALHO PRÁTICO I - PROGRAMAÇÃO ORIENTADA A OBJETOS **********************************************//
#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Matriz{
public:
    Matriz(); //cria uma matriz vazia com número de linhas e colunas iguais a 0.
    Matriz(unsigned int linhas, unsigned int colunas, const double &valor); //cria uma matriz com o número de linhas e colunas iguais aos recebidos pelos argumentos.
    Matriz(const Matriz &m); //Construtor de cópia.
    ~Matriz(); //destrutor.

    friend ostream &operator<<(ostream &out, const Matriz& a);
    friend istream &operator>>(istream &in, Matriz &a);

    //int Igualdade(Matriz a); //Verifica se duas Matrizes são iguais.
    //Matriz SomaMatriz(Matriz a);
    //Matriz SubtraiMatriz(Matriz a);
    //Matriz Trasposta();
    //Matriz MultiplicaMatrizes(Matriz a);
    Matriz operator*(const Matriz &a) const;
    int operator==(const Matriz &a) const;
    Matriz& operator=( const Matriz &m );
    Matriz operator~() const;
    Matriz& operator-=(const Matriz &a);
    Matriz operator-(const Matriz &a) const;
    Matriz operator+(const Matriz &a) const;
    Matriz& operator+=(const Matriz &a);

    void MatrizIdentidade();
    void AlteraValor(); //Altera o valor de uma posição da matriz.
    void ModificaElementos0(); //Modifica os elementos da matriz para 0.
    void ModificaElementos1(); //Modifica os elementos da Matriz com 1.
    void ValorLinha();
    void ValorColuna();
    int get_numero_de_linhas();
    int get_numero_de_colunas();

private:
    int _numero_de_linhas;
    int _numero_de_colunas;
    double **M;
};

#endif // MATRIZ_H
