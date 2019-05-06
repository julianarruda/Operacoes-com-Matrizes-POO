Universidade Federal de Minas Gerais
Escola de Engenharia
Departamento de Engenharia Elétrica

Programação Orientada à Objetos

Professor Cristiano Leite de Castro 			                                              Turma:  TECAD
Eduarda Fernanda Avila – 2017050665                                   Juliana Arruda Narcizo – 2016020851

Trabalho Prático 1:

Introdução
O problema proposto para este trabalho, foi a criação de uma classe, denominada Matriz, capaz de realizar operações tal como às do Matlab. O tipo das funções implementadas para a realização de tal é double e deve ser permitido aos usuários a manipulação das linhas e colunas das matrizes ao realizar cada método.

Como Compilar e Executar
O sistema operacional usado para a implementação do código foi o Windows, versão 10.  Além disso, a IDE (Integrated Development Enviroment) utilizada foi o Code::Blocks, uma IDE de código aberto e multiplataforma que suporta multicompiladores. O compilador utilizado foi o GCC e o debugger é o GDB da MinGW.

Implementação
Header file
O arquivo header criado tem o nome de Matriz.h. Nesse arquivo a classe foi implementada e suas funções membro, atributos, construtores e destrutores foram declarados de forma a manter o código do programa mais organizado. Nesse arquivo todas as bibliotecas que seriam necessárias para a execução do código foram colocadas, por exemplo, “iostream. Além disso, atributos de restrição (private e public) foram utilizados para que houvesse o encapsulamento dos dados que não devem ser acessados pelos usuários.
Na imagem a seguir é possível visualizar a implementação da classe.
 
Figura 1: Implementação da classe.
Construtores
Foram criados dois construtores para a classe Matriz: Matriz() e Matriz(unsigned int linhas, unsigned int colunas, const double &valor) e um construtor de cópia também foi criado declarado como: Matriz(const Matriz &m) . O primeiro com a função de criar uma matriz vazia com os números de linhas e colunas da matriz iguais a 0.
 
Figura 2: Construtor cria matriz vazia.
O segundo construtor foi criado para que as linhas e colunas da matriz pudessem ser inicializados de acordo com os argumentos passados pelo o usuário.
 
Figura 3: Construtor inicializa matriz com argumentos.

O construtor de cópia usa-se quando um objeto faz uma cópia a partir de um outro objeto esse comportamento é padrão da linguagem. Isso é feito para controlar a passagem de parâmetros e o retorno da função. O construtor de cópia implementado no programa usa this para que o objeto que chamou a função seja apontado.
 
Figura 4: Construtor de Cópia.

Getters
Os getters construídos no programa tem a função de retornar o número de linhas e colunas da matriz.
 
Figura 5: Getters.

Sobrecarga de Operadores 
Nas funções implementadas para realizar as operações de soma, subtração, igualdade e transposta de matrizes foram realizadas sobrecargas de operador. Na imagem abaixo  pode se ver a implementação da função para somar matrizes usando sobrecarga de operadores. 

 
Figura 6: Sobrecarga na função Soma Matriz.


Conclusão
Ao implementar o código do trabalho para o problema proposto foi possível ver como conceitos vistos até o momento em sala são aplicados e funcionam, pois quando se tem apenas a teoria pensar como esses conceitos e métodos se aplicam estava um pouco difícil de serem compreendidos que foram sanados a medida que os problemas de compilação e execução do código iam aparecendo.

