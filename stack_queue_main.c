#include"stack_queue.h"
#include<stdio.h>

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

    initialize_queue(Q);
	scanf("%c",&data);
	if(data){
		BT = (BinTree*)malloc(sizeof(BinTree));
		if(!BT){
			printf("no enough memory\n");
			exit(-1);
		}
			BT->Data = data;
			push_queue(Q,BT);
	}
		else{
			return NULL;
		}
		while(IsEmpty(Q)){
			T = pop_queue(Q);
			scanf("%c",&data);
			if(data == '0'){
				T->Lchild = NULL;
			}
			else{
				T->Lchild = (BinTree*)malloc(sizeof(BinTree));
				T->Lchild->Data = data;
				push_queue(Q,T->Lchild);
			}
			scanf("%c",&data);
			if(data == '0'){
				T->Rchild = NULL;
			}
			else{
				T->Rchild = (BinTree*)malloc(sizeof(BinTree));
				T->Rchild->Data = data;
				push_queue(Q,T->Rchild);
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
		InOrder(BT->Lchild);
		printf("%c ",BT->Data);
		InOrder(BT->Rchild);
	}
}

int main(int argc,char* argv[]){

/*	ElementType data;
	BinTree* Tree;

	Tree = CreateTree();
	PreOrder(Tree);
	printf("\n");
//	InOrder(Tree);
*/
	Stack* ST;
	type_t data;
	sqQueue* Q;
/*	
	ST = CreateStack();
	while(scanf("%d",&data),data){
		Push(ST,data);
	}
	//printf("\n");
	while(ST->top != -1){
		printf("%d ",Pop(ST));
	}
	printf("\n");
*/
	Q = CreateQueue();
	while(scanf("%d",&data),data){
		EnQueue(Q,data);
	}
	while(Q->front != Q->rear){
		printf("%d ",DeQueue(Q));
	}
	return 0;
}
