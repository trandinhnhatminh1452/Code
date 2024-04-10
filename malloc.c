#include <stdlib.h>
#include <stdio.h>
int main(){
    int i,n,*p;
    printf("How many numbers do you want to enter ?\n");
    scanf("%d",&n);
    p = (int *)malloc(n* sizeof(int));
    if (p == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Please enter numbers now: \n");
    for (i =0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("The numbers in reverse order are - \n");
    for(i=n-1;i>=0;--i) printf("%d ",p[i]);
    printf("\n");
    free(p);
    return 0;
}