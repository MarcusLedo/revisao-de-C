//Aluno: Marcus Ledo
//Data: 31/07/2021
//Objetivo: Implemente uma rotina RECURSIVA que some os elementos de um vetor de tamanho n

#include <stdio.h>
#include <time.h>//			 trabalhando com
#include <stdlib.h>//		números aleatorios

#define N 5
int arraySum(int, int[], int);
int main(){
	int myArray[N];
	int i;
	int totalSum;
	
	srand(time(NULL));
	
	for(i = 0; i < N; i++){
		myArray[i] = rand() % 10;
		printf("%d ", myArray[i]);
	}
		
	printf("\nTotal sum = %d", arraySum(N, myArray, 0));
	return 0;
}

int arraySum(int size, int array[], int sum){
	if(size < 0)
		return sum;
	sum += array[size];
	
	return arraySum(size - 1, array, sum);
}
