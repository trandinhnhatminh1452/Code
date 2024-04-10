#include <stdio.h>
#include<ctype.h>
enum {SUCCESS, FAIL, max_len=81};

struct{
    int no;
    char name[20];
    double price;
}product;

void LineReadWrite(FILE *fin,FILE *fout){
    char buff[max_len];
    int i=1;

    while (fgets(buff, max_len, fin) != NULL){
        
    }
}
int main(void)  
{
   FILE *fptr1, *fptr2;
   char filename1[]="minh.txt";
   char filename2[]="mdt.txt";
   int reval = SUCCESS;
   if((fptr1 = fopen(filename1, "r"))==NULL){
    printf("Cannot open %s.\n",filename1);
    reval = FAIL;
   }else if((fptr2 = fopen(filename2, "w"))==NULL){
    printf("Cannot open %s.\n",filename2);
    reval = FAIL;
   }else{
    LineReadWrite(fptr1, fptr2);
    fclose(fptr1);
    fclose(fptr2);
   }
   return reval;
}