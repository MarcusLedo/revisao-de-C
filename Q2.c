//Aluno: Marcus Ledo
//Data: 30/07/2021
//Objetivo: Implemente uma rotina que faça a multiplicação de duas matrizes nxn

#include <stdio.h>
#include <time.h>//			 trabalhando com
#include <stdlib.h>//		números aleatorios

#define N 2

void printMatrix(int, int[N][N]);
void calculateMatrixProduct(int , int[N][N], int[N][N], int[N][N]);

int main(){
	int myMatrix1[N][N], myMatrix2[N][N];
	int productMatrix[N][N];
	int i, j;
	
	srand(time(NULL));
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			myMatrix1[i][j] = rand() % 10;
			myMatrix2[i][j] = rand() % 10;
		}
	}
	
	printMatrix(N, myMatrix1);
	puts("");
	printMatrix(N, myMatrix2);
	calculateMatrixProduct(N, myMatrix1, myMatrix2, productMatrix);
	printf("\nProduct: \n");
	printMatrix(N, productMatrix);
	
	return 0;
}

void printMatrix(int size, int matrix[size][size]){
	int i, j;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++)
			printf("%03d ", matrix[i][j]);
		puts("");	
	}
}

void calculateMatrixProduct(int size, int matrix1[size][size], int matrix2[size][size], int matrixDestiny[size][size]){
	int i, j, k;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			matrixDestiny[i][j] = 0;
			for(k = 0; k < size; k++)
				matrixDestiny[i][j] += matrix1[i][k] * matrix2[k][j];
		}
	}	
}
