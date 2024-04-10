#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int n, min;
    int a[10000];
    FILE* f=fopen("arr-n.txt","r");
    fscanf(f,"%d",&n);
    for(int k=1;k<=n;k++){
       fscanf(f,"%d",&a[k]);
    }
   clock_t begin = clock();

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

   clock_t end = clock(); 
  printf("Time run: %f s",(float)(end-begin)/CLOCKS_PER_SEC);
   return 0;
}

