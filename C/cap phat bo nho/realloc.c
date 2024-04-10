#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    char *str;
    str = (char *)malloc(15);
    strcpy(str,"tutorialspoint");
    printf("String = %s, Address = %u\n",str,str);
    printf("%d\n",strlen(str));

    str=(char *) realloc(str, 25);
    strcat(str, ".com");
    printf("String= %s,Assress=%u\n",str,str);
    printf("%d\n",strlen(str));
    free(str);
    return 0;
}