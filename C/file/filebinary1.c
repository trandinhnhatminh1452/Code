#include <stdio.h>
#include<stdlib.h>
enum {MAX_LEN = 80,SUCCESS,FAIL};
int main(){
int num;
FILE *fptr1,*fptr2;
char filename1[]="mdt.txt";
char filename2[]="mdt1.txt";
char buff[MAX_LEN +1];
int reval = SUCCESS;
if((fptr1 = fopen(filename1, "r"))==NULL){
    printf("Cannot open %s.\n",filename1);
    reval = FAIL;
   }else if((fptr2 = fopen(filename2, "w"))==NULL){
    printf("Cannot open %s.\n",filename2);
    reval = FAIL;
   }else{
num = fread(buff,sizeof(char),MAX_LEN,fptr1);
buff[num * sizeof(char)]='\0';
printf("%s\n%d",buff,sizeof(buff));
fwrite(buff,sizeof(char),num,fptr2);
 fclose(fptr1);
fclose(fptr2);
}
}