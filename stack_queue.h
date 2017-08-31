#ifndef _STACK_QUEUE
#define _STACK_QUEUE

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef char ElementType;
typedef struct TNode{
	ElementType Data;
	struct TNode* Rchild;
	struct TNode* Lchild;
}BinTree;

typedef int type_t;
typedef struct SNode{
    type_t Data;
    struct SNode* next;    
}link_stack,*stack;

typedef struct QNode{
    BinTree* Data;
    struct QNode* next;
}link_queue,*queue;

typedef struct {
    queue rear;
    queue front;
}LinkQueue,Queue;

typedef struct STNode{
    type_t Data[MAXSIZE];
    int top;
}Stack;

typedef struct QENode{
    type_t Data[MAXSIZE];
    int front;
    int rear;
}sqQueue;

//initialize
stack initialize_stack();
//push stack
void push_satck(stack Top,type_t element);
//pop stack
type_t pop_stack(stack Top);

//initialize queue
void initialize_queue(LinkQueue* Q);
//push queue
void push_queue(LinkQueue* Q, BinTree* element);
//pop  queue
BinTree* pop_queue(LinkQueue* Q);

Stack* CreateStack();

void Push(Stack* ST, type_t data);

type_t Pop(Stack* ST);

sqQueue* CreateQueue();

void EnQueue(sqQueue* Q,type_t data);

type_t DeQueue(sqQueue* Q);




#endif
