//Aluno: Marcus Ledo
//Data: 31/07/2021
//Objetivo: Escreva uma rotina que receba duas FILAS de inteiros e retorne a quantidade
//		    de elementos que aparecem simultaneamente nas duas. Use só as operações 
//		    típicas desse tipo de estrutura de dados.

#include <stdio.h>
#include <time.h>//			 trabalhando com
#include <stdlib.h>//		números aleatorios

#define N 5

struct tNode{
	int data;
	struct tNode *previous;
};

void startQueue(struct tNode**, struct tNode**);
void enqueue(int, struct tNode**, struct tNode**);
void printQueue(struct tNode*);
int countEqualNumbers(struct tNode*, struct tNode*, int);
int isRepeated(int[], int, int);
void freeMemory(struct tNode*);

int main(){
	struct tNode *front, *back;
	struct tNode *front2, *back2;
	int i;
	
	srand(time(NULL));
	
	startQueue(&front, &back);
	startQueue(&front2, &back2);
	
	for(i = 0; i < N; i++){
		enqueue(rand() % 10, &front, &back);
		enqueue(rand() % 10, &front2, &back2);
	}
	
	printQueue(front);
	puts("");
	printQueue(front2);
	printf("\n\nQuantity of repeated numbers: %d", countEqualNumbers(front, front2, N));
	
	freeMemory(front);
	freeMemory(front2);
	
	return 0;
}

void freeMemory(struct tNode *start){
	struct tNode *p = start;
	struct tNode *q;
	while(p != NULL){
		q = p;
		p = p->previous;
		free(q);
	}
}

void startQueue(struct tNode **front, struct tNode **back){
	(*front) = NULL;
	(*back) = NULL;
}

void printQueue(struct tNode *queue){
	struct tNode *p = queue;
	
	while(p != NULL){
		printf("%d ", p->data);
		p = p->previous;
	}
}

void enqueue(int data, struct tNode **front, struct tNode **back){
	struct tNode *p = (struct tNode*) malloc(sizeof(struct tNode));
	
	if((*front) == NULL){
		(*front) = p;
		(*back) = p;
	}else{
		(*back)->previous = p;
		(*back) = p;
	}
	p->previous = NULL;
	p->data = data;
}

int countEqualNumbers(struct tNode *queue1, struct tNode *queue2, int size){
	struct tNode *p = queue1, *q = queue2;
	int flag, qnty = 0;
	int repeatedNumbers[size];
	
	while(p != NULL){
		flag = 0;
		q = queue2;
		while(q != NULL){
			if(p->data == q->data && isRepeated(repeatedNumbers, qnty, q->data) == 0){
				flag = 1;
				repeatedNumbers[qnty] = q->data;
			}	
			q = q->previous;
		}
		if(flag == 1)
			qnty++;
		p = p->previous;
	}
	
	return qnty;
}

int isRepeated(int array[], int size, int number){
	int i;
	
	for(i = 0; i < size; i++)
		if(number == array[i])
			return 1;
			
	return 0;
}
