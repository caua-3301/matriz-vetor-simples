//Developed by: Cau� Pires Soares
//30/08/2023
//Biblioteca para auxiliar nos exerc�cios

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Estrutura matriz (linhas e colunas est�o contidas na estrutura para facilitar opera��es futuras)
typedef struct matriz{
	int linhas;
	int colunas;
	int * vet;
}Matriz;

//Gerando matriz
Matriz * gerarMatriz(int n, int m){
	int k;
	Matriz * mat = (Matriz *)malloc(sizeof(Matriz));
	mat -> linhas = m;
	mat -> colunas = n;
	
	/*O o ponteiro vet apontar� para um endere�o de mem�ria cujo as dimens�es s�o calculadas pelas linhas e colunas, e o tamanho de cada espa�o, tem como
	base o tipo de vari�vel*/
	mat -> vet = (int *)malloc(sizeof(m*n*sizeof(int)));
	
	//Preenchendo todas as posi��es do vetor com 0
	for (k = 0; k < mat -> linhas * mat -> colunas; k++){
		mat -> vet[k] = 0;
	}
	
	return mat;
}

//Procedimento que zera a matriz
void zerarMatriz(Matriz * mat){
	int k;
	for (k = 0; k < mat -> linhas * mat -> colunas; k++){
		mat -> vet[k] = 0;
	}
}

//Gerando valores aleatorios para matriz
void valorAleatorio (Matriz * mat, int limite) {
	int k;
	for (k = 0; k < mat -> linhas * mat -> colunas; k++){
		//Gerando valores de 0 a 100
		mat -> vet[k] = rand() % limite;
	}
}

//Adicionado valor a matriz
void adicionarValor(Matriz * mat,  int num, int i, int j){
	//Posi��o no vetor
	int k = i* mat -> colunas + j;
	mat -> vet[k] = num;
}

//Procedimento que exibe a matriz
void printarMatriz(Matriz * mat){
	int i, j;
	for (i = 0; i < mat -> linhas; i++){
		for (j = 0; j < mat -> colunas; j++){
			printf ("%d  ",  mat -> vet[ i* mat -> colunas + j]);
		}
		printf ("\n");
	}
}

//Buscando elemento na matriz
int buscarElemento(Matriz * mat, int i, int j) {
	return mat -> vet[i * mat -> colunas + j];
}
