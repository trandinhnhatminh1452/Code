#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, last;
    int a[100];
    FILE* f=fopen("arr-n.txt","r");
    fscanf(f,"%d",&n);
    for(int k=1;k<=n;k++){
       fscanf(f,"%d",&a[k]);
    }
    for(int k=1;k<=n;k++){
        last = a[k];
        int j = k;
        while(j>1 && a[j-1]>last){
            a[j] = a[j-1];
            j--;
        }
        a[j] = last;
    }
    for(int k=1;k<=n;k++){
        printf("%d ",a[k]);
    }
    printf("\n");

    for(int k=1;k<=n;k++){
        last = a[k];
        int j = k;
        while(j>1 && a[j-1]<last){
            a[j] = a[j-1];
            j--;
        }
        a[j] = last;
    }
    for(int k=1;k<=n;k++){
        printf("%d ",a[k]);
    }
    fclose(f);
}
