//Developed by: Cauã Pires Soares
//30/08/2023
//Biblioteca para auxiliar nos exercícios

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Estrutura matriz (linhas e colunas estão contidas na estrutura para facilitar operações futuras)
typedef struct matriz{
	int linhas;
	int colunas;
	int * vet;
}Matriz;

//Gerando matriz
Matriz * gerarMatriz(int m, int n){
	int k;
	Matriz * mat = (Matriz *)malloc(sizeof(Matriz));
	mat -> linhas = n;
	mat -> colunas = m;
	
	/*O o ponteiro vet apontará para um endereço de memória cujo as dimensões são calculadas pelas linhas e colunas, e o tamanho de cada espaço, tem como
	base o tipo de variável*/
	mat -> vet = (int *)malloc(sizeof(m*n*sizeof(int)));
	
	//Preenchendo todas as posições do vetor com 0
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
	//Posição no vetor
	int k = i* mat -> colunas + j;
	mat -> vet[k] = num;
}

//Procedimento que exibe a matriz
void printarMatriz(Matriz * mat){
	int k, aux = 1;
	for (k = 0; k < mat -> linhas * mat -> colunas; k++, aux++){
		printf ("%d ", mat -> vet[k]);
		//Quebra de linha
		if (aux == mat -> colunas){
			printf ("\n");
			aux = 0;
		}
	}
}

//Buscando elemento na matriz
int buscarElemento(Matriz * mat, int i, int j) {
	return mat -> vet[i * mat -> colunas + j];
}
