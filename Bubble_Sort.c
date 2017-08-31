#include<stdio.h>
//冒泡排序是属于一种交换排序，一次排序将最大的元素逐步交换至最低端
//如此反复，即要排n次，且每次交换的次数比上一次少一次
void Bubble_Sort(int A[], int N){
	int temp,change,P,i;
	for(P=N-1;P>=0;P--){
		change = 0;
		for(i=0;i<P;i++){
			if(A[i]>A[i+1]){
				temp = A[i];
				A[i] = A[i+1];
				A[i+1] = temp;
				change = 1;
			}
		}
		if(change==0) break;
	}
}
int main(void){
	int i;
	int A[] = {2,4,1,23,43,45,23,123,567,12};
	Bubble_Sort(A,sizeof(A)/sizeof(int));
	//printf("%p,%d,%d",A,sizeof(A),sizeof(A)/sizeof(int));
	for(i=0;i<sizeof(A)/sizeof(int);i++){
		printf(" %d",A[i]);
	}
	return 0;
} 
