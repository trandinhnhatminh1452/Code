#include<stdio.h>
#include<stdlib.h>
enum{SUCCESS,FAIL};
typedef struct sinhvien
{
    int stt;
    int msv;
    char name[20];
    int sdt;
    int diem;
}sv;

int main(){
    sv sv_arr[20];
    int i=0;
    FILE *fptr1, *fptr2;
   char filename1[]="mdt.txt";

   char filename2[]="minh.txt";
   int reval = SUCCESS;
   if((fptr1 = fopen(filename1, "r"))==NULL){
    printf("Cannot open %s.\n",filename1);
    reval = FAIL;
   }else if((fptr2 = fopen(filename2, "w"))==NULL){
    printf("Cannot open %s.\n",filename2);
    reval = FAIL;
   }else{
    while(fscanf(fptr1,"%d %d %s %d",&sv_arr[i].stt,&sv_arr[i].msv,sv_arr[i].name,&sv_arr[i].sdt)!=EOF){
        scanf("%d",&sv_arr[i].diem);
        fprintf(fptr2,"%d %d %s %d %d\n",sv_arr[i].stt,sv_arr[i].msv,sv_arr[i].name,sv_arr[i].sdt,sv_arr[i].diem);
        i++;
    }
    fclose(fptr1);
    fclose(fptr2);
   }
    return reval;
}