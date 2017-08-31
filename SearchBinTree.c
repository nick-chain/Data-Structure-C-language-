#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;

typedef struct TNode{
      ElementType Data;
      struct TNode* Lchild;
      struct TNode* Rchild;
}SearchTree;

SearchTree* Insert(ElementType data,SearchTree* BST){
  if(!BST){
    BST = (SearchTree*)malloc(sizeof(SearchTree));
    BST->Data = data;
    BST->Lchild = BST->Rchild = NULL;
  }
  else{
    if(data<BST->Data){
      BST->Lchild = Insert(data,BST->Lchild);
    }
    else if(data>BST->Data){
      BST->Rchild = Insert(data,BST->Rchild);
    }
    //else,一样大什么都不要做
  }
  return BST;

}

void PreOrder(SearchTree* BST){
  if(BST){
    printf("%d ",BST->Data);
    PreOrder(BST->Lchild);
    PreOrder(BST->Rchild);
  }
}

int main(void){
    SearchTree* BST=NULL;
    ElementType data;

    do{
      scanf("%d",&data);
    BST = Insert(data,BST ) ;
    }while(data!=0);
    
    PreOrder(BST);
  return 0;
}
