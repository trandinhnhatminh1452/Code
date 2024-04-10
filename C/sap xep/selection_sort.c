#include<stdio.h>
#include<stdlib.h>


int main(){
    int n, min;
    int a[100];
    FILE* f=fopen("arr-n.txt","r");
    fscanf(f,"%d",&n);
    for(int k=1;k<=n;k++){
       fscanf(f,"%d",&a[k]);
    }
    for(int k = 1;k<=n;k++){
        min = k;
        for(int j = k+1;j<=n;j++){
            if(a[min]>a[j]) min = j;
        }
        int tmp =a[min];
        a[min] = a[k];
        a[k] =tmp;
    }

    for(int k=1;k<=n;k++){
        printf("%d ",a[k]);
    }
}