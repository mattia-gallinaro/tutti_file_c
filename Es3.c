#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

int CheckInput(char string[], int grandezza){
    int numero[10];
    int posizione = 0;
    int risultato = 0;
    int numero_da_togliere= 0;
    char stringa[2];
    char azzera = '\0';
    for(int i = 0; i < grandezza; i++ ){
        if(isdigit(string[i])){
            stringa[0] = string[i];
            numero[posizione] += atoi(stringa);
            posizione++;
        }
        if(string[i] == '-'){
            if(isdigit(string[i+1])){
                stringa[0] = string[i];
                stringa[1] = string[i+1];
                numero_da_togliere += atoi(stringa);
                stringa[0] = azzera;
                i++;
            }
        }
    }
    for (int i = 0; i < posizione; i++){
        int test = CalcolaPotenza(posizione - i, numero[i]);
    }
    risultato -= numero_da_togliere;
    return risultato;
}
int CalcolaPotenza(int quantita, int numero){
    int risult = 0;
    for (int i = 1; i < quantita; i++){
        if(i == 1){
            risult += 10;
        }
        else{
            risult = risult * 10;
        }
    }
    return risult * numero;
}
void PopolaArray(int array[], int grandezza)
{
    printf("\nGrandezza array: %d", grandezza);
    for (int i = 0; i < grandezza; i++)
    {
        array[i] = rand() % 200;
    }
}

void StampaArray(int array[], int grandezza, int scelta)
{
    if (scelta == 1)
    {
        for (int i = 0; i < grandezza; i++)
        {
            printf("\n%d", array[i]);
        }
    }
    else
    {
        for(int i = grandezza -1; i >= 0; i--){
            printf("\n%d", array[i]);
        }
    }
}
void StampaNumeri(int array[], int grandezza, int scelta)
{
    for (int i = 0; i < grandezza; i++)
    {
        if (array[i] % 2 == 0 && scelta == 1)
        {
            printf("\n%d", array[i]);
        }
        if (array[i] % 2 != 0 && scelta == 0)
        {
            printf("\n%d", array[i]);
        }
    }
}
void Somma_e_Media(int array[], int grandezza){
    int tot = 0;
    for(int i = 0; i < grandezza; i++){
        tot += array[i];
    }
    printf("\n Il totale e': %d\n La media e': %d", tot, (tot/grandezza));
}
void Scambiavalori(int array[], int grandezza)
{
    for (int i = 0; i < grandezza; i++)
    {
        if (i + 1 == grandezza)
        {
            break;
        }
        else
        {
            int j = array[i];
            array[i] = array[i + 1];
            array[i + 1] = j;
        }
    }
}

int RicercaNumero(int array[], int grandezza, int numero){
    int posizione = -1;
    for(int i = 0;i < grandezza; i++){
        if(array[i] == numero){
            posizione = i;
            break;
        }
    }
    return posizione;
}

void EliminaElementi(int array[], int *grandezza, int numero){
    int count =0;
    for(int i =0; i < (*grandezza) -count; i++){
        if(array[i] == numero){
            for(int j = i; j <  (*grandezza) - count -1; j++){
                array[j] = array[j+1];
            }
            count++;
        }
        else if((*grandezza) -count == i){
            break;
        }
    }
    *grandezza -= count;
}
void AlternaValori(int array[], int grandezza){
    for(int i = 0 ;i < grandezza; i += 2){
        if(i + 1 >= grandezza){
            break;
        }
        int valore = array[i+1];
        array[i+1] =array[i];
        array[i] = valore;
    }
}
void Ordinamento(int array[], int grandezza){
    for(int i = 0; i < grandezza; i++){
        for(int j = i + 1; j < grandezza; j++){
            if(array[i] > array[j]){
                int valore = array[j];
                array[j] =array[i];
                array[i] = valore;
            }
        }
    }

}
int main()
{
    char risposta[100];
    int grandezza = 0;
    srand(time(NULL));
    do
    {
        printf("\nInserisci la grandezza dell'array: ");
        scanf("%s", risposta);
        grandezza = CheckInput(risposta, strlen(risposta));
        printf("\nValore di grandezza : %d", grandezza);

    } while (grandezza <= 0);

    int array[grandezza];
    PopolaArray(array, grandezza);
    while (1)
    {
        int number = 0;
        printf("\nPremi 1 per stampare gli elementi dell'array \nPremi 2 per eseguire la stampa inversa dell'array \nPremi 3 per eseguire la somma e la media dell'array\nPremi 4 per stampare tutti i numeri pari\nPremi 5 pre stampare tutti i numeri dispari\nPremi 6 per cercare il numero selezionato\nPremi 7 per eliminare un elemento dell'array\nPremi 8 per alternare a due a due i numeri dell'array\nPremi 9 per ordinare l'array\nPremi 10 per terminare la selezione\nSelezione: ");

        scanf("%d", &number);
        switch(number)
        {
        case 1:
            StampaArray(array, grandezza, 1);
            break;
        case 2:
            StampaArray(array, grandezza, 0);
            break;
        case 3:
            Somma_e_Media(array, grandezza);
            break;
        case 4:
            StampaNumeri(array, grandezza, 1);
            break;
        case 5:
            StampaNumeri(array, grandezza, 0);
            break;
        case 6:
            int numero = 0;
            printf("\nInserisci un numero da cercare: ");
            scanf("%d", &numero);
            int risultato = RicercaNumero(array, grandezza, numero);
            if(risultato == -1){
                printf("\nmi spiace ma non esiste il numero");
            }
            else{
                printf("Il numero %d si trova alla posizione: %d", numero, risultato);
            }
            break;
        case 7:
            printf("\nInserisci un numero da cercare: ");
            scanf("%d", &numero);
            EliminaElementi(array, &grandezza, numero);
            break;
        case 8:
            AlternaValori(array, grandezza);
            break;
        case 9: 
            Ordinamento(array, grandezza);
            break;
        }
        if(number == 10)
        {
            break;
        }
        
    }

    return 0;
}