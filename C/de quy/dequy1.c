#include <stdio.h>
int x[100];
void printSolution(int n){
    for(int k=0;k<n;k++) printf("%d",x[k]);
        printf("\n");
    
}

int TRY(int k, int n){
    for(int v =0;v <=1; v++){
        x[k]=v;
        if(k == n-1) printSolution(n);
        else TRY(k+1,n);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    TRY(0,n);
}
