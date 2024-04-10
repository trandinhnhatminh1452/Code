#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n,*a;
int random(int minN, int maxN){
	return minN + rand() % (maxN + 1 - minN);
}

void selectionsort(int n, int a[]){
    for(int k = 1;k<=n;k++){
        int min = k;
        for(int j = k+1;j<=n;j++){
            if(a[min]>a[j]) min = j;
        }
        int tmp =a[min];
        a[min] = a[k];
        a[k] =tmp;
    }
}

void bubblesort(int n,int* a){
    int swapped;
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
}

void insertsort(int n,int* a){
    for(int k=1;k<=n;k++){
        int last = a[k];
        int j = k;
        while(j>1 && a[j-1]>last){
            a[j] = a[j-1];
            j--;
        }
        a[j] = last;
    }
}

void DoctuFile(char *filename)
{
    FILE*f=fopen(filename,"r");
    fscanf(f,"%d\n",&n);
    a=(int*)malloc(n*sizeof(int));
    for(int i=1;i<=n;i++){
        fscanf(f,"%d ",&a[i]);
    }
    fclose(f);
}

int main(){
     DoctuFile("arr-n.txt");
    // FILE*f=fopen("arr-n.txt","r");
    // fscanf(f,"%d\n",&n);
    // a=(int*)malloc(n*sizeof(int));
    // for(int i=1;i<=n;i++){
    //     fscanf(f,"%d ",&a[i]);
    // }
    // fclose(f);
    clock_t begin = clock();
    for(int k = 1;k<=n;k++){
    selectionsort(n,a);
    }

   clock_t end = clock(); 
  printf("Time run: %f s\n",(float)(end-begin)/CLOCKS_PER_SEC);

      clock_t begin1 = clock();
    for(int k = 1;k<=n;k++){
    insertsort(n,a);
    }

   clock_t end1 = clock(); 
  printf("Time run: %f s\n",(float)(end1-begin1)/CLOCKS_PER_SEC);

     clock_t begin2 = clock();
    for(int k = 1;k<=n;k++){
    bubblesort(n,a);
    }

   clock_t end2 = clock(); 
  printf("Time run: %f s",(float)(end2-begin2)/CLOCKS_PER_SEC);
  return 0;
}