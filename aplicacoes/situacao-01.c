/*SITUAÇÃO: Faça uma função que Leia (ou receba como parâmetro) uma matriz 3x2 e outra
2x3 de números INT e Imprima o produto d estas duas matrizes.*/

#include <stdio.h>
#include "opera-matriz.h"

void calcularProduto (Matriz * matriz01, Matriz * matriz02, Matriz * matrizResposta){
	int i, j, i1, a = 0, aux = 0, contador = 0, posicaoMat = 0, valorPrevisto;
	
	for (i = 0; i < matriz01 -> linhas * 2; i++){	
		for (j = 0; j < matriz01 -> colunas; j++){
			//Acumulando valor da multiplicação
			valorPrevisto += (buscarElemento(matriz01, a, j) * buscarElemento(matriz02, j, i1));
			contador++;
		}
		if (contador == matriz01 -> colunas * matriz01 -> linhas){
			a++;
			i1--;
			contador = 0;
		}	
		if (contador == matriz01 -> colunas){
			i1++;
		}
		matrizResposta -> vet[posicaoMat] = valorPrevisto;
		valorPrevisto = 0;               
		posicaoMat++;    
	}
	printf ("\n\n");
	printarMatriz(matrizResposta);
 
}
	

void main(void){
	
	int limite = 5;
	
	srand(time(NULL));
	
	setlocale (LC_ALL, "portuguese");
	
	//Gerando as matrizes (aceita qualquer valor, desde que, o numero de colunas da primeira seja igual o de linhas da segunda)
	Matriz * matriz01 = gerarMatriz(3, 2);
	Matriz * matriz02 = gerarMatriz(2, 3);
	Matriz * matrizResposta = gerarMatriz(matriz01 -> linhas, matriz02 -> colunas);
	
	valorAleatorio(matriz01, limite);
	valorAleatorio(matriz02, limite);
	
	printarMatriz(matriz01);
	printf ("\n\n");
	printarMatriz(matriz02);
	
	calcularProduto(matriz01, matriz02, matrizResposta);

}


