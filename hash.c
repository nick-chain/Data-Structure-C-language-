#include"cphash.h"

HashTable* InitHash(int TableSize){
    HashTable* H;
    int i;

    if(TableSize<MinHashTable){
        printf("The size is no enough big\n");
        return NULL;
    }

    H = (HashTable*)malloc(sizeof(HashTable));
    if(!H){
        printf("InitHash malloc fail\n");
        exit(-1);
    }

    H->data = (type_t*)malloc(TableSize*sizeof(type_t));
    if(!H->data){
        printf("H->data ,malloc fail\n");
        exit(-1);
    }
    H->length = TableSize;

    for(i=0;i<H->length;i++){
        H->data[i] = -1;
    }

    return H;
}

int func(int p){
    int i;
    for(;p>1;p--){
        for(i=2;i<p;i++){
            if(p%i == 0){
                break;
            }
        }
        if(i>=p){
            printf("%d\n",p);
            return p;
        }
    }
    return -1;
}
void CreateHash(HashTable* H, type_t* a, int N){
    type_t element,i;
    int p = func(H->length);//取不大于表长的质数

    if(p==-1){
        return;
    }
    for(i=0;i<N;i++){
        //用除留余数法构建hash函数
        element = a[i]%p;
        //用线性探测法处理冲突
        while(H->data[element]!=-1){
            element = (element+1)%H->length;
        }
        //将记录存放起来
        H->data[element] = a[i];
        HashShow(H,element);
    }

}
int HashSearch(HashTable* H, int key){
    int flag=0,element;
    element = key%func(H->length);

    while(H->data[element] != key){
        //线性探测发解决冲突
        element = (element+1)%H->length;
        flag++;
        if(flag == H->length){
            printf("No such element\n");
            return -1;
        }
    }

    return element;    
}

void HashShow(HashTable* H, type_t element){
    int i;

    for(i=0;i<H->length;i++){
        if(i==element)
        printf("H->[%02d]:%d <-----当前插入\n",i,H->data[i]);
        else
        printf("H->[%02d]:%d\n",i,H->data[i]);
    }
    printf("*************************\n");
}
