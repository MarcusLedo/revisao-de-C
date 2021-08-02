//Aluno: Marcus Ledo
//Data: 01/08/2021
//Objetivo: Escreva uma rotina que receba uma árvore binária contendo números inteiros e que 
//			retorne o maior valor nela contido. Defina a estrutura de dados do nó.

#include <stdio.h>
#include <time.h>//			 trabalhando com
#include <stdlib.h>//		números aleatorios

#define N 10

struct tNode{
	int data;
	struct tNode *left;
	struct tNode *right;
};

void startTree(struct tNode**);
void addNode(struct tNode**, struct tNode*);
struct tNode* createNode(struct tNode);
void printTree(struct tNode*, int, int);
int searchLargestNumber(struct tNode*);

int main(){
	struct tNode *root, *p;
	struct tNode auxNode;
	int i;
	
	srand(time(NULL));
	
	startTree(&root);
	
	for(i = 0; i < N; i++){
		auxNode.data = rand() % 99;
		p = createNode(auxNode);
		addNode(&root, p);
	}
	printf("TREE IS IN HORIZONTAL");
	for(i = 0; i < N; i++)
		printf("-----");
	printf(">\n");
	printTree(root, 0, 8);
	printf("\n-> Largest number: %d", searchLargestNumber(root));
	return 0;
}

void startTree(struct tNode **root){
	(*root) = NULL;
}

struct tNode* createNode(struct tNode auxNode){
	struct tNode *p = (struct tNode*) malloc(sizeof(struct tNode));
	
	p->data = auxNode.data;
	p->left = NULL;
	p->right = NULL;
	
	return p;
}

void addNode(struct tNode **root, struct tNode *node){
	if((*root) == NULL){
		(*root) = node;
		return;
	}	
	
	if(node->data >= (*root)->data)
		addNode(&(*root)->right, node);
	else
		addNode(&(*root)->left, node);
}

void printTree(struct tNode *root, int space, int n){
	int i;
	if(root == NULL)
		return;
		
	space += n;
	printTree(root->right, space, n);
	puts("");
	for(i = 0; i < space; i++)
		printf(" ");
	printf("%d\n", root->data);
	
	printTree(root->left, space, n);
}

int searchLargestNumber(struct tNode *root){
	if(root == NULL)
		return -1;
		
	if(root->right != NULL)
		searchLargestNumber(root->right);
	else
		return root->data;
}

/*void printTree(struct tNode *root){
	if(root == NULL)
		return;
	printTree(root->left);
	printf("(");
	printf("%d", root->data);
	printTree(root->right);
	printf(")");
}
*/
