#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
typedef int ElmentType;

typedef struct LNode{
    ElmentType Data[MAXSIZE];
    int Last;
}List,*sqList;

sqList CreateList(){
    sqList PtrL;

    PtrL = (sqList)malloc(sizeof(List));
    if(!PtrL){
        printf("no enough memory\n");
        exit(-1);
    }
    PtrL->Last = -1;

    return PtrL;
}

ElmentType FindNode(sqList PtrL,ElmentType data){
    int i=0;

    while(PtrL->Data[i]!=data&& i <= PtrL->Last){
        i++;
    }
    if(i>PtrL->Last){
        return -1;//no find
    }
    else{
        return i;
    }
}

void DeleteList(sqList PtrL,int postion){
    int i;

    if(postion<0||postion>MAXSIZE-1){
        printf("no such emlement\n");
        return ;
    }

    for(i=postion+1;i<=PtrL->Last;i++){
        PtrL->Data[i-1] = PtrL->Data[i];
    }
    PtrL->Last--;
}
void InsertList(sqList PtrL,int postion,ElmentType data){
    int i;
    if(PtrL->Last == MAXSIZE-1){
        printf("List was full\n");
        return;
    }
    if(postion<0||postion>PtrL->Last+1){
        printf("postion was illegal\n");
        return;
    }
    for(i=PtrL->Last;i>=postion;i--){
        PtrL->Data[i+1] = PtrL->Data[i];//往后移 
    }
    PtrL->Data[postion] = data;//插入
    PtrL->Last++;
}

void PrintList(sqList PtrL){
    int i;

    for(i=0;i<PtrL->Last+1;i++){
        printf("%d ",PtrL->Data[i]);
    }
    printf("\n");
}

int main(void){
    sqList PtrL;
    int i,offset,set=0;
    ElmentType a[MAXSIZE]={3,4,11,7,5,9,10};
    ElmentType b[]={2,3,6,7,10,1};

    
    PtrL = CreateList();
    for(i=0;a[i]!=0;i++){
        InsertList(PtrL,i,a[i]);
    }
   
    offset = i-1;
    for(i=0;i<sizeof(b)/sizeof(int);i++){
        if(FindNode(PtrL,b[i]) == -1){
            InsertList(PtrL,offset-set+i+1,b[i]);
        }
        else{
            set++;
        }
    }
    PrintList(PtrL);

    return 0;

}
