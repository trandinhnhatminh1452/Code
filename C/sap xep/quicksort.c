#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quickSort(int A[],int L,int R){
    if(L<R){
        int index =(L+R)/2;
        index = partition(A,L,R,index);
        if(L<index)
            quickSort(A,L,index-1);
        if(index , R)
            quickSort(A,index+1,R);
    }
}

int partition(int A[],int L,int R,int indexPivot){
    int pivot =A[indexPivot];
    swap(A[indexPivot],A[R]);
    int storeIndex = L;
    for(int i=L;i<=R-1;i++){
        if(A[i]<pivot){
            swap(A[indexPivot],A[i]);
            storeIndex++;
        }
    }
    swap(A[storeIndex],A[R]);
    return storeIndex;
}