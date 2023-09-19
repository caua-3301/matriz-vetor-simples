//Matriz vetor simples

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Dimensionado matriz
int dimensionarMatriz(int m, int n) {
	int tamanho = m * n;
	return tamanho;
}

//Procedimento que zera a matriz
void zerarMatriz(int vet[], int tamanho) {
	int k;
	for (k = 0; k < tamanho; k++){
		vet[k] = 0;
	}
}

//Funcao que retorna um indice para a matriz
int indice(int linha, int coluna, int numColunas) {
	int k = (linha - 1) * numColunas + (coluna - 1);
	return k;
}

//Funï¿½ï¿½o que retorna um elemento de uma matriz
int buscaElemento(int mat[], int linha, int coluna, int numColunas) {
	int aux = mat[indice(linha, coluna, numColunas)];
}

//Procedimento que adiciona um elemento
void adicionarElemento(int vet[], int numColunas, int valor, int linha, int coluna) {
	int k = (linha - 1) * numColunas + (coluna - 1);
	vet[k] = valor;
}

//Procedimento que printa uma matriz
void printarMatriz(int vet[], int linhas, int colunas) {
	int i, j;
	for (i = 0; i < linhas; i++){
		for (j = 0; j < colunas; j++){
			printf("%d  ", vet[i*colunas + j]);
		}
		printf ("\n");
	}
}

//Procedimento que preenche uma matriz com valores aleatorios (reservada para testes)
void preencher (int mat[], int linhas, int colunas) {
	int i, j;
	for (i = 0; i < linhas; i++){
		for (j = 0; j< colunas; j++){
			mat[indice(i+1, j+1, colunas)] = rand() % (0 - 4);
		}
	} 
}

//Caluclando o produto de duas matrizes
void produtoMatriz(int mat1[], int mat2[], int numLinhasMat1, int numColunasMat1, int numLinhasMat2, int numColunasMat2, int matrizResposta[]) {
	int i, j, x, mult = 0;
	for (i = 0; i < numLinhasMat1; i ++) {
		for (j = 0; j < numColunasMat2; j++) {
			for (x = 0; x < numColunasMat1; x++) {
				mult += mat1[indice(i +1, x +1, numColunasMat1)] * mat2[indice(x +1, j +1, numColunasMat2)];
			}
			matrizResposta[indice(i +1, j +1, numColunasMat2)] = mult;
			mult = 0;
		}
	}
}

//Printar transposta
void printarTransposta (int mat[], int linhas, int colunas) {
	int i, j;
	for (i = 0; i < linhas; i++){
		for (j = 0; j < colunas; j++){
			printf ("%d  ", mat[indice(j+1, i+1, colunas)]);
		}
			printf("\n");
	}
}

//Soma duas matrizes
void somarMatrizes (int mat1[], int mat2[], int linhas, int colunas, int matrizSoma[]) {
	int i, j;
	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			matrizSoma[indice(i+1, j+1, colunas)] = mat1[indice(i+1, j+1, colunas)] + mat2[indice(i+1, j+1, colunas)];
			
		}
	}
	printf ("ANTES\n");
	printarMatriz(matrizSoma, linhas, colunas);
	printf ("DEPOIS\n");
	printarTransposta(matrizSoma, linhas, colunas);
}

//Verificar se matriz eh identidade
int ehIdentidade(int mat[], int linhas, int colunas) {
	int i, j;
	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			if (i == j){
				if (mat[indice(i+1, j+1, colunas)] == 1){
					continue;
				}
				else{
					return 0;
				}
			}
			else if (mat[indice(i+1, j+1, colunas)] == 0){
				continue;
			}
			else{
				return 0;
			}
		}
	}
	return 1;
}

//Verificar se matriz eh invers a outra
int ehInversa (int mat1[], int mat2[], int numColunasMat1, int numLinhasMat1, int numColunasMat2, int numLinhasMat2) {
	
	int matResultante[dimensionarMatriz(numColunasMat1, numColunasMat1)]; //matriz quadrad, sempre
	
	produtoMatriz(mat1, mat2, numColunasMat1, numLinhasMat1, numColunasMat2, numLinhasMat2, matResultante);
	
	if (ehIdentidade(matResultante, numColunasMat1, numColunasMat1)) {
		return 1;
	}
	return 0;
}

void main() {
	
	srand(time(NULL));
	

	// TESTE QUESTÃO 01 =====
	int mat1[6],  mat2[6], matProduto[9];
	
	preencher(mat1, 3, 2);
	
	preencher(mat2, 2, 3);
	
	printarMatriz(mat1, 3, 2);
	printf ("\n");
	printarMatriz(mat2, 2, 3);
	printf ("\n");
	
	produtoMatriz(mat1, mat2, 3, 2, 2, 3, matProduto);
	
	printf("\n PRODUTO\n");
	printarMatriz(matProduto, 3, 3);
	printf ("\n");
	
	
	// TESTE QUESTÃO 02 =====
	//Para que a soma exista, as matrizes devem ter a mesma dimensão, se preferirem, podem adicionar um teste de condição
	
	int mat3[9], mat4[9], matSoma[9];
	
	preencher(mat3, 3, 3);
	preencher(mat4, 3, 3);
	
	printf ("SOMA\n\n");
	somarMatrizes(mat3, mat4, 3, 3, matSoma); //O prcedimento ja printa;
	printf ("\n\n");
	
	// TESTE QUESTÃO 03 =====
	
	//A matriz deve ser quadrada, se preferirem, podem adicionar um teste de condição
	int mat5[9];
	
	//Mat, nº de colunas, valor, linhas e coluna
	//PODEM ALTERAR OS VALORES, JA FOI TESTADO E ELA FUNCIONA
	
	adicionarElemento(mat5, 3, 1, 1, 1);
	adicionarElemento(mat5, 3, 0, 1, 2);
	adicionarElemento(mat5, 3, 0, 1, 3);
	adicionarElemento(mat5, 3, 0, 2, 1);
	adicionarElemento(mat5, 3, 1, 2, 2);
	adicionarElemento(mat5, 3, 0, 2, 3);
	adicionarElemento(mat5, 3, 0, 3, 1);
	adicionarElemento(mat5, 3, 0, 3, 2);
	adicionarElemento(mat5, 3, 1, 3, 3);
	
	printf ("\nMATRIZ IDENTIDADE \n\n");
	printarMatriz(mat5, 3, 3);
	
	if (ehIdentidade(mat5, 3, 3)){
		printf ("E identidade");
	}
	else{
		printf ("Nao eh identidade");
	}
	
	//TESTE QUESTÃO 04 =====
	
	

}
