#ifndef _LINKLIST_H
#define _LINKLIST_H

#include<stdlib.h>
typedef int ElementType;
typedef struct Node{
    ElementType Data;
    struct Node* Next;
}LinkList,*List;

List CreateList();

//头部插入元素
void HeadInsertNode(List H, int Element);
//尾部插入
List TailInsertNode(List H,int Element);
// find by key
List FindKey(List H,int Key);
//find by element
List FindElement(List H, int Element);
//insert any postion
List Insert(List H,int postion, int Element);
//delete any postion
int  Delete(List H, int postion);
//reverse list
List ReverseList(List H);
void PrintList(List H);
void Print(List ptr);
#endif
