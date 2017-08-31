#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
List Reverse( List L );
void Print( List L ); /* 细节在此不表 */

//PAT乙级题目
int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}


List Read(){
    List ptr,p,q;
    int number,i;
    ElementType data;

    scanf("%d",&number);
    p = (List)malloc(sizeof(PtrToNode));
    p->Next = NULL;
    q = p;
    for(i=0;i<number;i++){
        scanf("%d",&data);
        ptr = (List)malloc(sizeof(PtrToNode));
        ptr->Data = data;
        ptr->Next = NULL;
        q->Next = ptr;
        q= ptr;
    }

    return p;
}
//每次操作都有一个逆序好的链表和一个待逆序的链表
List Reverse(List L1){
    List p,q,t;

    p = L1;
    q = NULL;
    while(p!=NULL){
        t = p->Next;//保存队列的下一个位置便于找到
        p->Next = q;
        q = p;
        p = t;

    }
     p;
    return p;
}

void Print(List L){
    List ptr=L;
    while(ptr->Data){
        printf("%d ",ptr->Data);
        ptr=ptr->Next;
    }
}

