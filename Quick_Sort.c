#include<stdio.h>

void Swap(int *n, int *m){
	int temp;
	temp = *n;
	*n = *m;
	*m = temp;
}

void Insert_Sort(int A[], int N){
	int i,p,temp;
	for(p=1;p<N;p++){
		temp  =A[p];
		for(i=p;i>0&&A[i-1]>temp;i--){
			A[i] = A[i-1];
			A[i-1] = temp;
		}
	}
}

int Median3(int A[], int Left, int Right){
	int Center;
	Center  =(Left+Right)/2;
	if(A[Left]>A[Center]){
		Swap(&A[Left],&A[Center]);
	}
	if(A[Left]>A[Right]){
		Swap(&A[Left],&A[Right]);
	}
	if(A[Center]>A[Right]){
		Swap(&A[Center],&A[Right]);
	}
	Swap(&A[Center],&A[Right-1]);
	return A[Right-1];
}
void QuickSort(int A[], int Left, int Right){
	int i,j,pivot;
	if(5<=Right-Left){
		pivot = Median3(A,Left,Right);
		i = Left;
		j  =Right-1;
		for(; ;){
			while(A[++i]<pivot){
			}
			while(A[--j]>pivot){
			}
			if(i<j){
				Swap(&A[i],&A[j]);
			}
			else break;
		}
		Swap(&A[i],&A[Right-1]);
		QuickSort(A,Left,i-1);
		QuickSort(A,i+1,Right);
	}
	else{
		Insert_Sort(A+Left,Right-Left+1);
	} 
}
void Quick_Sort(int A[], int N){//快排标准接口
	QuickSort(A,0,N-1); 
} 
int main(void){
	int A[] = {4,2,7,8,6,55,45,54,22,41,26,59,56,12,14};
	int i;
	Quick_Sort(A,sizeof(A)/sizeof(int));
	for(i=0;i<sizeof(A)/sizeof(int);i++){
		printf(" %d",A[i]);
	}
	
	return 0;
} 
