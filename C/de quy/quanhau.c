#include<stdio.h>
int x[100];
int n;
void printSolution(){
    for(int k=1;k<=n;k++) printf("%d",x[k]);
        printf("\n");
    
}
int check(int v, int k){
    for(int i=0; i<=k-1; i++){
        if(x[i]==v) return 0;
        if(x[i]+i==v+k) return 0;
        if(x[i]-i==v-k) return 0;
    }
    return 1;
}
void TRY(int k){
    for(int v = 1;v<=n;v++){
        if(check(v,k)){
            x[k]=v;
            if(k == n) printSolution();
            else TRY(k+1);
        }
    }
}
void main(){
    scanf("%d",&n);
    TRY(1);
}