/*SITUAÇÃO: Faça uma função que Leia (ou receba como parâmetro) uma matriz 3x2 e outra
2x3 de números INT e Imprima o produto d estas duas matrizes.*/

#include <stdio.h>
#include "opera-matriz.h"

void calcularProduto (Matriz * matriz01, Matriz * matriz02, Matriz * matrizResposta){
	int i, j, aux = 0;
	for (i = 0; i < matriz01 -> linhas; i++){
		for (j = 0; j < matriz01 -> colunas; j++){
			matrizResposta -> vet[aux] = buscarElemento(matriz01, i, j) * buscarElemento(matriz02, j, i) + buscarElemento(matriz01, i+1, j+1) * buscarElemento(matriz02, j+1, i);    
			aux++;
		}
	}
	printf ("\n\n");
	printarMatriz(matrizResposta);
}

void main(void){
	
	int limite = 3;
	
	srand(time(NULL));
	
	setlocale (LC_ALL, "portuguese");
	
	//Gerando as matrizes
	Matriz * matriz01 = gerarMatriz(3, 2);
	Matriz * matriz02 = gerarMatriz(2, 3);
	Matriz * matrizResposta = gerarMatriz(3, 2);
	
	valorAleatorio(matriz01, limite);
	valorAleatorio(matriz02, limite);
	
	printarMatriz(matriz01);
	printf ("\n\n");
	printarMatriz(matriz02);
	
	calcularProduto(matriz01, matriz02, matrizResposta);

}


