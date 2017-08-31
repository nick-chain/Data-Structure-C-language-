#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef char ElementType;


typedef struct TNode{
	ElementType Data;
	struct TNode* Rchild;
	struct TNode* Lchild;
}BinTree;

typedef struct Node{
	BinTree* Data[MAXSIZE];
	int front;
	int rear;
}Queue;

Queue* CreateQ(Queue* Q){

	Q = (Queue*)malloc(sizeof(Queue));
	if(!Q){
		printf("no enough memory\n");
		exit(-1);
	}
	else{
		Q->front = Q->rear = 0;
		return Q;
	}
}

void Add(Queue* Q,BinTree* T){
	if((Q->rear+1)%MAXSIZE == Q->front){
		printf("Queue was full\n");
		return;
	}
	else{
		Q->rear = (Q->rear+1)%MAXSIZE;
		Q->Data[Q->rear] = T;
	}
}

BinTree* DeleteQ(Queue* Q){
	BinTree* BT;
	if(Q->rear == Q->front){
		printf("Queue was empty\n");
		exit(-1);
	}
	else{
		Q->front = (Q->front+1)%MAXSIZE;
		BT = Q->Data[Q->front];
	}
	return BT;
}


BinTree* InitTree(BinTree* Tree){

		Tree = (BinTree*)malloc(sizeof(BinTree));
		if(!Tree){
			printf("no enough memory\n");
			exit(-1);
		}
		else{
			Tree->Rchild = NULL;
			Tree->Lchild = NULL;
			return Tree;
		}
}

int IsEmpty(Queue* Q){
	if(Q->front == Q->rear){
		return 0;
	}
	else{
		return 1;
	}
}

BinTree* CreateTree(){
	BinTree *BT,*T;
	Queue* Q;
	ElementType data;

	Q = CreateQ(Q);
	scanf("%c",&data);
	if(data){
		BT = (BinTree*)malloc(sizeof(BinTree));
		if(!BT){
			printf("no enough memory\n");
			exit(-1);
		}
			BT->Data = data;
			Add(Q,BT);
	}
		else{
			return NULL;
		}
		while(IsEmpty(Q)){
			T = DeleteQ(Q);
			scanf("%c",&data);
			if(data == '0'){
				T->Lchild = NULL;
			}
			else{
				T->Lchild = (BinTree*)malloc(sizeof(BinTree));
				T->Lchild->Data = data;
				Add(Q,T->Lchild);
			}
			scanf("%c",&data);
			if(data == '0'){
				T->Rchild = NULL;
			}
			else{
				T->Rchild = (BinTree*)malloc(sizeof(BinTree));
				T->Rchild->Data = data;
				Add(Q,T->Rchild);
			}
		}
		return BT;
}



void PreOrder(BinTree* BT){

	if(BT){
		printf("%c ",BT->Data);
		PreOrder(BT->Lchild);
		PreOrder(BT->Rchild);
	}
}
void InOrder(BinTree* BT){

	if(BT){
		PreOrder(BT->Lchild);
		printf("%c ",BT->Data);
		PreOrder(BT->Rchild);
	}
}

int main(int argc,char* argv[]){

	ElementType data;
	BinTree* Tree;

	Tree = CreateTree();
	PreOrder(Tree);
	printf("\n");
	InOrder(Tree);
	
		return 0;
}
