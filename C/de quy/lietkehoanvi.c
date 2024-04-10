#include <stdio.h>
#include <stdbool.h>
int x[100];
int n;
bool m[2];
void printSolution(){
    for(int i=1;i<=n;i++) printf("%d",x[i]);
        printf("\n");
    
}

void TRY(int i){
    for(int v =1;v <=n; v++){
        if(!m[v]){
        x[i]=v;
        m[v]= true; //danh dau
       if(i == n) printSolution();
       else TRY(i+1);
       m[v]=false; //khoi phuc
        }
    }
}

void main() {
    for(int v=1; v<=n; v++) m[v]=false;
    
    scanf("%d",&n);
 
    TRY(1);
}