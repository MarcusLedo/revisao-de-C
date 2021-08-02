//Aluno: Marcus Ledo
//Data: 30/07/2021
//Objetivo: Implemente uma rotina que retorne todos os valores acima da média 
//			de um vetor de inteiro passado como parâmetro

#include <stdio.h>
#include <time.h>//			 trabalhando com
#include <stdlib.h>//		números aleatorios

#define TAM 5

struct tNode{
	int data;
	struct tNode *next;
};

float calculateAverage(int[], int);
struct tNode* getValuesAboveAverage(int[], int );
void addNode(int, struct tNode**);
void freeMemory(struct tNode*);

int main(){
	int myArray[TAM];
	int i;
	struct tNode *p;
	struct tNode *start;
	
	srand(time(NULL));
	
	printf("[ ");
	for(i = 0; i != TAM; i++){
		myArray[i] = rand() % 100;
		printf("%d ", myArray[i]);
	}
	printf("]");
	printf("\n-> Average = %.2f", calculateAverage(myArray, TAM));
	
	
	start = getValuesAboveAverage(myArray, TAM);
	puts("");
	printf("-> Above average: ");
	p = start;
	while(p != NULL){
		printf("%d -> ", p->data);
		p = p->next;
	}
	
	freeMemory(start);
	return 0;
}

void freeMemory(struct tNode *start){
	struct tNode *p = start;
	struct tNode *q;
	while(p != NULL){
		q = p;
		p = p->next;
		free(q);
	}
}

float calculateAverage(int array[], int size){
	int i = 0;
	int total = 0;
	
	for(i = 0; i < size; i++)
		total += array[i];
		
	return (float) total/size;
}

void addNode(int value, struct tNode **start){
	struct tNode *p = (struct tNode*) malloc(sizeof(struct tNode));
	
	if(start == NULL)
		p->next = NULL;
	else
		p->next = (*start);
	
	p->data = value;
	(*start) = p;		
}

struct tNode* getValuesAboveAverage(int array[], int size){
	struct tNode *start = NULL; //É preciso liberar a memória se for chamar essa função mais de uma vez!
	float average = calculateAverage(array, size);
	int i;
	
	for(i = 0; i < size; i++)
		if(array[i] > average)
			addNode(array[i], &start);
	
	return start;
}
