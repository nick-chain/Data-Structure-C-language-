#include<stdio.h>
#include<stdlib.h>
#include"stack_queue.h"

stack initialize_stack(){
    stack Top;

    Top = (stack)malloc(sizeof(link_stack));
    if(!Top){
        printf("initialize malloc fail \n");
        exit(-1);
    }

    Top->Data = -1;
    Top->next = NULL;

    return Top;
}

void push_satck(stack Top,type_t element){
    stack st;

    st = (stack)malloc(sizeof(link_stack));
    if(!st){
        printf("push_stack malloc fail\n");
        exit(-1);
    }

    st->Data = element;
    st->next = Top->next;
    Top->next = st;
 //   printf("push:%d ",st->Data);
}

type_t pop_stack(stack Top){
    stack st;
    type_t element;

    if(!Top->next){
        printf("pop_stack fail\n");
        return -1;
    }
    st = Top->next;
    Top->next = st->next;
    element = st->Data;
    free(st);

    return element;
}
void initialize_queue(LinkQueue* Q){

    //在队尾入队，在对头出队，开始时头尾地址均指向空
    //这是一个不带头结点，只有头尾指针的链表
    Q->front = Q->rear = (queue)malloc(sizeof(link_queue));
    if(!Q->front){
        printf("initialize queue malloc fail\n");
        exit(-1);
    }
    Q->front->next = NULL;
    printf("initialize suceess\n");
    
}

void push_queue(LinkQueue* Q, BinTree* element){
    queue p;
    
    p = (queue)malloc(sizeof(link_queue));
    if(!p){
        printf("push_queue malloc fail\n");
        return exit(-1);
    }
    p->Data = element;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

BinTree* pop_queue(LinkQueue* Q){
    BinTree* element;
    queue p;
    
    if(Q->rear == Q->front){
        printf("Queue was empty");
        exit(-1);
    }
    p = Q->front->next;
    Q->front->next = p->next;
    if(Q->rear == p){
        Q->rear = Q->front;
    }
    element = p->Data;
    free(p);

    return element;
    
}

Stack* CreateStack(){
    Stack* ST;

    if(!(ST = (Stack*)malloc(sizeof(Stack)))){
        printf("CreateSatck malloc fail\n");
        exit(-1);
    }
    ST->top = -1;

    return ST;
}

void Push(Stack* ST, type_t data){
    if(ST->top == MAXSIZE-1){
        printf("satck is full\n");
        return;
    }
        ST->Data[++ST->top] = data;
    //    printf("%d\n",ST->Data[ST->top]);
}


type_t Pop(Stack* ST){
    type_t element;
    if(ST->top == -1){
        printf("satck was empty\n");
        return -1;
    }
    element = ST->Data[ST->top--];
    return element;

}

sqQueue* CreateQueue(){
    sqQueue* Q;
    
    if(!(Q = (sqQueue*)malloc(sizeof(sqQueue)))){
        printf("CreateQueue malloc fail\n");
        exit(-1);
    }

    Q->front = Q->rear = 0;
    return Q;
}

void EnQueue(sqQueue* Q,type_t data){
    if(Q->front == (Q->rear+1)%MAXSIZE){
        printf("The queue is full\n");
        return;
    }

    Q->Data[Q->rear] = data;
    Q->rear = (Q->rear+1)%MAXSIZE;
}

type_t DeQueue(sqQueue* Q){
    type_t element;
    if(Q->rear == Q->front){
        printf("The queue is empty\n");
        return -1;
    }

    element =  Q->Data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return element;
}
