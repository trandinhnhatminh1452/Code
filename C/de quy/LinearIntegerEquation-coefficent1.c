#include <stdio.h>
int x[100];
int n,m;
int s=0;
void printSolution(){
    for(int k=0;k<n;k++) printf("%d ",x[k]);
        printf("\n");
    
}

int TRY(int k){
    for(int v =1;v <=n; v++){
        if(x[k-1]+v<m){
             x[k]=v;
            s+=x[k-n+1];
        if(k == n-1) {
            if(s==m){
            printSolution();
            }
        }
        else TRY(k+1);
        }
       
    }
}

int main() {
    
    scanf("%d %d",&n,&m);
    TRY(0);
}