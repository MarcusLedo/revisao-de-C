//Aluno: Marcus Ledo
//Data: 31/07/2021
//Objetivo: 

#include <stdio.h>
#include <time.h>//			 trabalhando com
#include <stdlib.h>//		números aleatorios

#define N 3
#define TAM 3

struct tGeneric{
	int x;
	int y;
	int z;
};

void startMatrix(int, int[N][N]);
void convertToAnIntArray(struct tGeneric[], int, int[]);
void printMatrix(int, int[N][N]);
void generateMatrix(int[], int, int, int[N][N]);
int isRepeated(int, int, int[N][N]);
void printArray(int, int[]);

int main(){
	struct tGeneric myStruct[TAM];
	int myArray[TAM * 3];
	int myMatrix[N][N];
	int i, j;
	
	srand(time(NULL));
	
	for(i = 0; i < TAM; i++){
		myStruct[i].x = rand() % 10;
		myStruct[i].y = rand() % 10;
		myStruct[i].z = rand() % 10;
		printf("%d %d %d   ", myStruct[i].x, myStruct[i].y, myStruct[i].z);
	}
	puts("");
	
	startMatrix(N, myMatrix);
	convertToAnIntArray(myStruct, TAM, myArray);
	printArray(TAM * 3, myArray);
	generateMatrix(myArray, 3 * TAM, N, myMatrix);
	printMatrix(N, myMatrix);
	
	return 0;
}

void startMatrix(int n, int matrix[n][n]){
	int i, j;
	
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			matrix[i][j] = -1;
}

void convertToAnIntArray(struct tGeneric generic[], int size, int array[]){
	int n = size * 3;
	int i, j = 0;
	
	for(i = 0; i < n; i += 3){
		array[i] = generic[j].x;
		array[i + 1] = generic[j].y;
		array[i + 2] = generic[j].z;
		j++;
	}
}

void generateMatrix(int array[], int size, int n, int matrix[n][n]){
	int i, j, control = 0;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(control < size && isRepeated(array[control], n, matrix) == 0){
				matrix[i][j] = array[control];
			} else
				matrix[i][j] = 0;
			control++;	
		}
	}
}

int isRepeated(int number, int n, int matrix[n][n]){
	int i, j;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(number == matrix[i][j])
				return 1;
		}
	}
	return 0;	
	
}

void printMatrix(int size, int matrix[size][size]){
	int i, j;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++)
			printf("%03d ", matrix[i][j]);
		puts("");	
	}
	puts("");
}

void printArray(int size, int array[]){
	int i;
	
	for(i = 0; i < size; i++)
		printf("%d ", array[i]);
		
	puts("");
}

