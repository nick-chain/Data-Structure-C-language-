#include<stdio.h>
#include"linklist.h"

int main(void){
    List H;
    List ptr=NULL;
    int a[] = {43,1,2,46,78,31,89,15,55};
    int i;

    H = CreateList();
    for(i=0;i<sizeof(a)/sizeof(int);i++){
    //    H = TailInsertNode(H,a[i]);
        HeadInsertNode(H,a[i]);
    }
    
    PrintList(H);
    ptr = FindKey(H,5);
    printf("FindKey:%d\n",ptr->Data);
    ptr = FindElement(H, 100);
    if(ptr == NULL){
        printf("no such elemnet\n");
    }
    else{
    printf("FindElment:%d\n",ptr->Data);
    }
    
    ptr = Insert(H,1,66);
    PrintList(H);
    Delete(H,6);
    PrintList(H);
    ptr = ReverseList(H);
    Print(ptr);

    return 0;

}
