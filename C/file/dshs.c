#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
enum {SUCCESS, FAIL, max_len=81};

typedef struct sinhvien{
    int no;
    int msv;
    char name[20];
    int sdt;
}SV;

int main(void)  
{
   FILE *fp;
   int n;
   scanf("%d",&n);
   SV *student;
   student = (SV*) malloc(n* sizeof(SV));
   if (student == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    int reval = SUCCESS;
    int i=0;
if((fp=fopen("student.txt","r"))==NULL){
    printf("Can not open %s.\n","student.txt");
    reval=FAIL;
}else{
    while (fscanf(fp,"%d%d%s%d"),&student[i].no,&student[i].msv,&student[i].name,&student[i].sdt);
    i++;
}
n=i;
for(i=0;i<n;i++){
    printf("%-6d%-24d%-6s%-6d\n",student[i].no,student[i].msv,student[i].name,student[i].sdt);
}
fclose(fp);
return reval;
}