
#ifndef _LIST_H
#define _LIST_H

#include<stdio.h>
#include<stdlib.h>
typedef int type_t;

typedef struct node{
    type_t Data;
    struct node* Next;
}LinkList,*List;

typedef struct cir_node{
    type_t Data;
    struct cir_node* prior;
    struct cir_node* next;
}cir_double_list,*cir_list;

//create list who have a header of pointer
List InitList();

//insert by anyplace
List AnyplaceInsert(List H,int postion, type_t data);
//find element by postion
List FindKey(List H,int postion);
//delete element by postion
int DeleteNode(List H, int postion);
//print list
void PrintList(List H);
//reverse linklist
List ReverseList(List H);
//reverse print
void PrintReverse(List H);

List CreateJoseph();

void PrintJoseph(List H);
//Joseph alogrithm
int DeleteJoseph(List H, int m, int k);

//insert on tail
cir_list cir_list_insert();
//insert on anypalce
void cir_list_anyinsert(cir_list H, int postion, int data);    

void cir_list_print(cir_list H);

cir_list cir_list_findkey(cir_list H,int postion);

int delete_cir_node(cir_list H, int postion);
#endif
