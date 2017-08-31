#include<stdio.h>
//希尔排序，一种以一定间隔交换的排序
void Shell_Sort(int A[], int N){
	int p,D,i,temp;
	for(D=N/2;D>0;D/=2){
		for(p=D;p<N;p++){
			temp = A[p];
			for(i=p;i>=D&&A[i-D]>temp;i-=D){
				A[i] = A[i-D];
				A[i-D]  =temp;
			}
		}
	}
}
int main(void){
	int i;
	int A[] = {23,43,123,45,22,121,453,1,3,2,8};
	Shell_Sort(A,sizeof(A)/sizeof(int));
    for(i=0;i<sizeof(A)/sizeof(int);i++){
		printf(" %d",A[i]);
    }
    
    return 0;

}
