#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, swapped;
    int a[100];
    FILE* f=fopen("arr-n.txt","r");
    fscanf(f,"%d",&n);
    for(int k=1;k<=n;k++){
       fscanf(f,"%d",&a[k]);
    }
    do{
        swapped = 0;
        for(int i = 1;i < n; i++){
            if(a[i] > a[i+1]){
                int tmp =a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                swapped =1;
            }
        } 
    }while(swapped == 1);

    for(int k=1;k<=n;k++){
        printf("%d ",a[k]);
    }
    printf("\n");

    do{
        swapped = 0;
        for(int i = 1;i < n; i++){
            if(a[i] < a[i+1]){
                int tmp =a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                swapped =1;
            }
        } 
    }while(swapped == 1);
    fclose(f);
}
