#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n;
    
    printf("-----Program filtrujacy liczby dodatnie-----\n");
    printf("Podaj liczbe elementow: ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Należy podac liczbe wieksza od 0!");
        return 1;
    }

    printf("System: Alokowanie pamięci dla %d elementow....\n", n);
    double *tablica = (double*)malloc(n*sizeof(double));
    if(tablica == NULL){
        printf("!Blad alokacji pamieci! Program zakonczony.\n");
        return 1;
    }

    printf("---Wprowadzenie danych---\n");
    printf("Wpisz dane:\n");
    for(int i=0; i<n; i++){
        if(scanf("%lf", &tablica[i]) != 1){
            printf("Blad wprowadzenia danych! Zakonczenie programu...\n");
            free(tablica);
            return 1;
        }
    }

    printf("------TWOJA TABLICA:-------\n");
    for(int i=0; i<n; i++){
        printf("%.2f ", tablica[i]);
    }
    
    printf("Szukam liczby dodatnie!\n");
    int czy_dodatnia = 0;
    for(int i=0; i<n; i++){
        if(tablica[i]>0){
            czy_dodatnia++;
        }
    }

    double *tablica_dodatnia = NULL;
    if(czy_dodatnia>0){
        tablica_dodatnia = (double*)malloc(czy_dodatnia*sizeof(double));
        if(tablica_dodatnia == NULL){
            printf("Blad krytyczny - brak pamieci! Zamykanie programu.\n");
            free(tablica);
            return 1;
        }
    

    int index = 0;
    for(int i = 0; i<n; i++){
        if(tablica[i]>0){
            tablica_dodatnia[index] = tablica[i];
            index++;
        }
    }

    printf("----TABLICA LICZB DODATNICH-------:\n");
    for(int i=0; i<czy_dodatnia; i++){
        printf("%.2f ", tablica_dodatnia[i]);
    }
    printf("\n");

} else {
    printf("\n[Informacja] W pierwszej tablicy nie bylo zadnych liczb dodatnich. Druga tablica nie zostala utworzona.\n");
}

free(tablica);
free(tablica_dodatnia);
printf("Zakonczenie programu!");

}