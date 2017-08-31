#include<stdio.h>
#include<stdlib.h>
#define MaxData 10000 
//堆的特性1.用数组表示的完全二叉树
//2. 只有最大堆和最小堆 
typedef struct HeapStruct* MaxHeap; 
struct HeapStruct{
int *Elemnets;//存储堆元素的数组！
int size;//堆的当前元素个数 
int capacity;//堆的最大容量 
};


MaxHeap Create(int MaxSize){
//创建最大容量的堆
MaxHeap H = malloc(sizeof(struct HeapStruct));
H->Elemnets = malloc((MaxSize+1)*sizeof(int));
//从1开始
H->size=0;
H->capacity= MaxSize;
H->Elemnets[0] = MaxData;
//哨兵大于所有可能元素
return H; 
} 


void Insert(MaxHeap H, int item){
int i;
if(IsFull(H)){
printf("最大堆已经满");
return; 
} 
i = ++H->size;
//向下过滤 节点 
for(;H->Elemnets[i/2]<item;i/=2)
{
H->Elemnets[i] = H->Elemnets[i/2];
}
H->Elemnets[i] = item;//将新增元素插入 
} 




int DeleteMax(MaxHeap H){
int Parent,child;
int MaxItem,temp;
if(IsEmpty(H)){
printf("堆已经满");
return;
} 
MaxItem = H->Elemnets[1];
temp = H->Elemnets[size--];
for(Parent=1;Parent*2<=H->size;Parent=child){
child = 2*Parent;
if(child!=H->size&&H->Elemnets[child]<H->Elemnets[child+1])
{
child++;//child指向左右儿子较大的 
}
H->Elemnets[Parent]=H->Elemnets[child];
//移动temp到下一层 
}
H->Elemnets[Parent] = temp; 
} 
