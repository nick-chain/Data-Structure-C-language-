#include<stdio.h>
#include<stdlib.h>

void InsertSort(int a[], int n){
    int i,j,temp;

    for(i=1;i<n;i++){
        temp = a[i];
        for(j=i;j>0&&temp<a[j-1];j--){
            a[j] =a[j-1];
        }
        a[j] = temp;
     }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int BinaryTree(int a[],int n,int element){
    int left,mid,right;
    left = 0;
    right = n;

    while(left<=right){
        mid = (left+right)/2;
        if(element>a[mid]){
            left =mid+1;
        }
        else if(element<a[mid]){
            right = mid -1;
        }
        else{
            return mid;
        }

    }
    return -1;//没有找到
}
int main(void){
    int a[] = {43,5,3,23,6,87,54,23,89};
    int element=0;
    int number;

    InsertSort(a,sizeof(a)/sizeof(int));
    number = BinaryTree(a,sizeof(a)/sizeof(int),element);
    printf("%d\n",a[number]);
    return 0;
}
