#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SV{
    char name[20];
    char date[20];
    struct SV* next;
}SV;

struct SV *head=NULL;

SV* makenode(char* name,char* date){
    SV* node = (SV*)malloc(sizeof(SV));
    strcpy(node->name,name);
    strcpy(node->date,date);
    node->next = NULL;
    return node;
}

void addfirst(char* name,char*date)
{
    SV* a=(SV*)malloc(sizeof(SV));
    strcpy(a->name,name);
    strcpy(a->date,date);
    a->next=head;
    head=a;
}

void addlast(char* name,char*date)
{
    SV *a=head;
    if(head==NULL)
    {
        addfirst(name,date);
        return;
    }
    while(a->next!=NULL) a=a->next;
    SV* c=makenode(name,date);
    a->next=c;
}

void printlist()
{
    for( SV *a=head;a!=NULL;a=a->next) printf("%s\n %s\n",a->name,a->date);
}

void store(char* filename) {
    FILE* f = fopen(filename, "w");
    SV* tmp = head;
    while (tmp != NULL) {
        fprintf(f, "%s\n%s\n", tmp->name, tmp->date);
        tmp = tmp->next;
    }
    fclose(f);
}

int main(){
    int n;
    char name[20];
    char date[20];
    char filename[20];
    // scanf("%d",&n);
    gets(name);
    gets(date);
    addlast(name,date);
    scanf("%s",&filename);
    printlist();
    store(filename);
}