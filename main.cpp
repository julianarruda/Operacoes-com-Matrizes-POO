#include <iostream>

#include "Matriz.cpp"

using namespace std;

int main(){
    Matriz Y;
    Matriz X(3,1), A(3,3), C(3,3);
    Matriz W = C;
    Matriz Z(A);
    int numeroLinhas = A.ValorLinha();
    int numeroColunas = A.ValorColuna();
    C.MatrizIdentidade(); // inicializa Y com a matriz identidade
    //A(2,1)=10; // altera o valor de uma posição de A

    cout<<"Matriz Identidade: "<< endl;
    cout<< C << endl;
    A.AlteraValor();
    cout<<"Valor Alterado: "<< endl;
    cout<< A <<endl;
    //C.ModificaElementos0(); // modifica todos os elementos de Y para o valor zero
    cout<<"Soma das matrizes: "<< endl;
    C=A+A; // Soma
    cout << C << endl;
    cout<<"Subtracao das matrizes: "<< endl;
    C-=A; // Subtração
    cout << C << endl;
    cout<<"Subtracao das matrizes2: "<< endl;
    A=C-A; // Subtração
    cout << A << endl;
    cout<<"Soma das matrizes2: "<< endl;
    A+=A; // Soma
    cout << A << endl;
    cout<<"Transposta: "<< endl;
    ~C;
    cout << C << endl;
    cout<< "Multiplicacao por constante: " << endl;
    //X*=2; // multiplicação por uma constante.
    cout<< X << endl;
    cout<< "Multiplicacao de Matrizes: "<< endl;
    C=A*X; // multiplicação de matrizes
    cout<< C << endl;
    cout<< "Multiplicacao de Matrizes2: "<< endl;
    C*=X; // multiplicação de matrizes
    cout<< C << endl;
    cout<<"Verifica a igualdade:\n "<< endl;// verifica a igualdade entre A e C.
    if (A == C)
        cout<< "A Igualdade é verdadeira. \n"<< endl;
    else
        cout<< "As matrizes sao diferentes. \n"<< endl;
    cout<<"Verifica a desigualdade:\n "<< endl;// verifica a igualdade entre A e C.
    if (X != Y)
        cout<< "A Igualdade é verdadeira. \n"<< endl;
    else
        cout<< "As matrizes sao diferentes. \n"<< endl;
    X.ModificaElementos1(); // modifica todos os elementos de X com 1s
    cout << C << endl; // Impressão de matrizes
    cin >> Y; // leitura de dados para dentro da matriz Y

    return 0;
}
