#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int ContaAscii(char parola[]){
    int totale = 0;

    for(int i = 0; i < strlen(parola); i++){
        tolower(parola[i]);
        totale += parola[i];
    }

    return totale;
}



int main(){
    char parola[100];

    printf("Inserisci una parola : ");
    scanf("%s", parola);

    int totale = ContaAscii(parola);


}