#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct node
{
    char malop[20];
    char hp[20];
    struct node *next;
} node;
struct node *head=NULL;

node* makenode(char* malop, char* hp) {
    node* p = (node*)malloc(sizeof(node));
    strcpy(p->malop, malop);
    strcpy(p->hp, hp);
    p->next = NULL;
    return p;
}
void addfirst(char* malop,char* hp)
{
     node* a=(node*)malloc(sizeof(node));
    strcpy(a->malop,malop);
    strcpy(a->hp,hp);
    a->next=head;
    head=a;
}

void addlast(char* malop,char* hp)
{
     node *a=head;
    if(head==NULL)
    {
        addfirst(malop,hp);
        return;
    }
    while(a->next!=NULL) a=a->next;
    node* c=makenode(malop,hp);
    a->next=c;
}

void loadlist(char* filename){
    
    FILE* f=fopen(filename,"r");
    while(!feof(f))
    {
        char malop[40], hp[40];
        fscanf(f,"%s %s",&malop,&hp);
        addlast(malop,hp);
    }
    fclose(f);
}
void printlist()
{
    for( node *a=head;a!=NULL;a=a->next) printf("%s %s \n",a->malop,a->hp);
}

bool search(char* hp)
{
    for( node *a=head;a!=NULL;a=a->next) {
    if(strcmp(a->hp,hp) ==0){
         return true;
    }
    return false;
}
}

bool searchclass(char* malop)
{
    for( node *a=head;a!=NULL;a=a->next) {
    if(strcmp(a->malop,malop) ==0){
         return true;
    }
    return false;
}
}

void print_name(char* hp)
{
    for( node *a=head;a!=NULL;a=a->next) {
    if(strcmp(a->hp,hp) ==0) {printf("%s\n",a->malop);return;}
}
}



void deleteclass(char* malop)
{
     node *a=head;
    if(strcmp(a->malop,malop) ==0) 
    {
        head=a->next;
        a->next=a;
        return;
    }
    while(a->next->malop!=malop) a=a->next;
     node *b=a->next;
    a->next=b->next;
    b->next=b;
}

void store(char* filename) {
    FILE* f = fopen(filename, "w");
    node* tmp = head;
    while (tmp != NULL) {
        fprintf(f, "%s %s\n", tmp->malop, tmp->hp);
        tmp = tmp->next;
    }
    fclose(f);
}

void count(){
    
}


int main()
{
    int n;
    char hp[40];
    char malop[40];
    while(1)
    {
        printf("\n======================MENU======================\n\n");
        printf("\t\t1.Doc thong tin\n");
        printf("\t\t2.Hien thi\n");
        printf("\t\t3.Tim kiem\n");
        printf("\t\t4.Them vao dau \n");
        printf("\t\t5.Them vao cuoi\n");
        printf("\t\t6.Xoa thong tin\n");
        printf("\t\t7.luu du lieu\n");
        printf("\t\t8.Dem so luong lop\n");
        printf("\t\t9.Thoat\n");
        printf("\n======================END======================\n\n");
        printf("nhap:");
        scanf("%d",&n);
        if (n == 1) {
            printf("nhap vao filename: ");
            char filename[100];
            scanf("%s", filename);
            loadlist(filename);
        }
        else if(n==2) printlist();
        else if(n==3)
        {
            printf("nhap ma hoc phan:");
            scanf("%s",&hp);
            if(search(hp)==false) printf("Khong co lop nay \n");
            else print_name(hp);
        }
        else if(n==4)
        {
            printf("nhap ma lop va ma hoc phan:");
            scanf("%s %s",&malop,&hp);
            if(search(hp)==true) printf("Da co lop nay\n");
            else 
            {
                addfirst(malop,hp);
            }
        }

        else if(n==5)
        {
            printf("nhap ma lop va ma hoc phan:");
            scanf("%s %s",&malop,&hp);
            if(search(hp)==true) printf("Da co lop nay\n");
            else 
            {
                addlast(malop,hp);
            }
        }
        else if(n==6){
            printf("nhap ma lop:");
            scanf("%s",&malop);
            if(searchclass(malop)==false) printf("Khong co lop nay \n");
            else deleteclass(malop);
        }
        else if(n==7)
        {
           printf("nhap vao filename: ");
            char filename[100];
            scanf("%s", filename);
            store(filename);
        }
        else if(n==8){
            printf("ERROR");
        }
        else if(n==9){ printf("Da thoat"); break;}
        
    }
    return 0;
}