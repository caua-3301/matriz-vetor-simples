//Developed by: Cauã Pires Soares
//30/08/2023

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
void valorAleatorio (Matriz * mat) {
	int k;
	for (k = 0; k < mat -> linhas * mat -> colunas; k++){
		//Gerando valores de 0 a 100
		mat -> vet[k] = rand() % 100;
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



void main(){
	
	srand(time(NULL));
	
	setlocale (LC_ALL, "portuguese");
	
	int n, m, fazer, quant, num, i, j, executar = 1;
	
	printf ("Dimensões da matriz: \n");
	scanf ("%d%d", &m, &n);
	
	//Gerando a matriz com suas respectivas dimensões
	Matriz * mat = gerarMatriz(n, m);

	while(executar == 1){
		printf ("O que deseja fazer: \n\nAdicioar numero [1]: \nExibir matriz [2]\nZerar matriz atual [3]: \nBuscar elemento: [4]\nPreencher matriz aleatoriamente [5]: \nEncerrar execucao [0]: \n\n");
		scanf("%d", &fazer);
		switch (fazer){
			
			//Adicionando valor
			case 1: printf ("\nDigite quantos numeros serao adicionados: \n");
				scanf ("%d", &quant);
				while (quant > 0){
					printf ("Informe o valor a ser adicionado, a linha (i) e em seguida a coluna (j): \n");
					scanf ("%d%d%d", &num, &i, &j);
					adicionarValor(mat, num, i, j);
					quant--;
				}
				break;
			
			//Exibindo matriz
			case 2: printf ("\n");
				printarMatriz(mat);
				printf ("\n\n");
				break;
			
			//Zerando matriz
			case 3: zerarMatriz(mat);
				break;
			
			//Encontrando elemento
			case 4: printf ("Informe as coordenadas do elemento (i e j): \n");
				scanf ("%d%d", &i, &j);
				int elemento = buscarElemento(mat, i, j);
				printf ("Elemento = %d", elemento);
				break;	
				
			case 5: valorAleatorio (mat);
				break;
			
			//Encerrando programa	
			case 0: executar = 0;
				break;
			
			default: printf ("Valor invalido\n");
		}
		
	}

	printf ("ATÉ A PRÓXIMA!");
}
