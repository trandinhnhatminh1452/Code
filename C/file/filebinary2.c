#include <stdio.h>
#include<stdlib.h>
enum {MAX_LEN = 100,SUCCESS,FAIL};
typedef struct danhba{
    char name[20];
    int sdt;
    char email[50];
}db;
int main(){
int num;
db db_arr[100];
int i,n,irc;
printf("Nhap n: ");
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%s%d%s",&db_arr[i].name,&db_arr[i].sdt,&db_arr[i].email);
}
FILE *fptr1;
char filename1[]="mdt.txt";
char buff[MAX_LEN +1];
int reval = SUCCESS;
if((fptr1 = fopen(filename1, "w+b"))==NULL){
    printf("Cannot open %s.\n",filename1);
    reval = FAIL;
   }
irc = fwite(db_arr,sizeof(db),n,fptr1);
printf("fwitr return code = %d\n",irc);
 fclose(fptr1);

 if((fptr1 = fopen(filename1, "w+b"))==NULL){
    printf("Cannot open %s.\n",filename1);
    reval = FAIL;
   }
irc = fread(db_arr,sizeof(db),n,fptr1);
printf("fwitr return code = %d\n",irc);
 fclose(fptr1);

}