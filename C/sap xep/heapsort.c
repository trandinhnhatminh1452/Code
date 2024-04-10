#include <stdio.h>
#include <stdlib.h>

void heapify(int A[],int i,int N){
    int L=2*i;
    int R=2*i+1;
    int max = i;
    if(L<=N && A[L]>A[i]) max = L;
    if(R<=N && A[R]>A[max]) max = R;
    if(max != i){
        swap(A[i],A[max]);
        heapify(A,max,N);
    }
}

void buildHeap(int A[], int N){
    for(int i=N/2; i>=1;i--)
        heapify(A,i,N);
}

void heapSort(int A[], int N){
    buildHeap(A,N);
    for(int i=N;i>1;i--){
        swap(A[1],A[i]);
        heapify(A,1,i-1);
    }
}