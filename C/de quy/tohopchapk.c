#include <stdio.h>

int x[100];
int n,k;
void printSolution(){
    for(int i=1;i<=k;i++) printf("%d",x[i]);
        printf("\n");
    
}

int TRY(int i){
    for(int v =x[i-1]+1;v <=n-k+i; v++){
        x[i]=v;
       if(i ==k) printSolution();
       else TRY(i+1);
    }
}

int main() {
    
    
    scanf("%d %d",&n,&k);
 
    TRY(1);
}