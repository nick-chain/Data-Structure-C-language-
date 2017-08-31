#include<stdio.h>
//插入排序相当于一个抓牌插入的过程
//最小的牌放在左边，最大的放在右边
//从最后开始比较，一旦有不合适的牌（比待插的牌大）
//就往后移动，知道插入合适的位置为止，如此循环
void Insertion_Sort(int A[], int N){
	int temp,p,i;
	for(p=1;p<N;p++){
		temp = A[p];
		for(i=p;i>0&&A[i-1]>temp;i--){
			A[i] = A[i-1];
			A[i-1] = temp;
		}
	}
}
int main(void){
	int i;
	int A[] = {28,37,34,2,3,55,23,123,23};
	Insertion_Sort(A,sizeof(A)/sizeof(int));
	for(i=0;i<sizeof(A)/sizeof(int);i++){
		printf(" %d",A[i]);
    }
    
    return 0;
}
