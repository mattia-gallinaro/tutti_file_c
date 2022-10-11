#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char *stringa = "NEGRO PAZZO IN CULO";

    char c = 'c';
    printf("%c vale %d\n", c, c);
    c = toupper(c);
    printf("%c vale %d\n", c, c);
    c = '\0';
    printf("%c vale %d\n", c, c);
    char a = 'a';
    printf("%c vale %d\n", a, a);
    a = toupper(a);
    printf("%c vale %d\n", a, a);
    int numero = 5;
    printf("%c vale %d\n", numero, numero);
    if(strchr(stringa, c) != NULL){
        printf("Esiste nella stiringasdasndasbkdfbsd\n"); 
    }
    return 0;
}