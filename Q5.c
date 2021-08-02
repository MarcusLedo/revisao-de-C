//Aluno: Marcus Ledo
//Data: 31/07/2021
//Objetivo: Implemente uma rotina que receba uma PILHA de inteiros e, 
//			usando só as operações típicas desse tipo abstrato de dados, retire dessa pilha seu maior número.


#include <stdio.h>
#include <stdlib.h>

struct tNode{
	int data;
	struct tNode *next;
};

void startStack(struct tNode**);
void push(struct tNode**, struct tNode);
int menu();
void printStack(struct tNode*);
struct tNode* findTheLargestNumber(struct tNode*, struct tNode**);
void popEspecificNode(struct tNode**, struct tNode*, struct tNode*);
void freeMemory(struct tNode*);

int main(){
	struct tNode *top, *previous, *p;
	struct tNode auxNode;
	int opt;
	
	startStack(&top);
	
	do{
		opt = menu();
		switch(opt){
			case 1:
				printf("\n\n PUSH \n\n");
				printf("Enter the data: ");
				scanf("%d", &auxNode.data);
				push(&top, auxNode);
			break;
			case 2:
				printf("\n\n PRINT STACK \n\n");
				printStack(top);
			break;
			case 3:
				printf("\n\n REMOVE THE LARGEST NUMBER \n\n");
				p = findTheLargestNumber(top, &previous);
				popEspecificNode(&top, p, previous);
				
		}
	}while(opt != 0);
	
	freeMemory(top);
	
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

int menu(){
	int opt;
	printf("\n1-) PUSH\n");
	printf("2-) PRINT STACK\n");
	printf("3-) REMOVE THE LARGEST NUMBER\n");
	printf("0-) EXIT\n");
	
	printf("\n Enter the option: ");
	scanf("%d", &opt);
	
	return opt;
}

void startStack(struct tNode **top){
	(*top) = NULL;
}

void push(struct tNode **top, struct tNode newNode){
	struct tNode *p = (struct tNode*) malloc(sizeof(struct tNode));
	
	p->data = newNode.data;
	p->next = (*top);
	(*top) = p;
	
}

struct tNode* findTheLargestNumber(struct tNode *top, struct tNode **previous){
	struct tNode *p = top;
	struct tNode *q = top;
	
	while(p->next != NULL){
		if(p->next->data > q->data){
			q = p->next;
			(*previous) = p;
		}
		p = p->next;
	}
	
	return q;
} 

void popEspecificNode(struct tNode **top, struct tNode *node, struct tNode *previous){
	if((*top)->data == node->data)
		(*top) = node->next;
	else
		previous->next = node->next;
		
	free(node);
}

void printStack(struct tNode *top){
	struct tNode *p = top;
	
	while(p != NULL){
		printf("	%d\n", p->data);
		p = p->next;
	}
}
