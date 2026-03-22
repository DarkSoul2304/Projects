#include <stdio.h>
#include <math.h>

int main() {
    float bufor;
    float liczba;
    char znak;

    printf("=== KALKULATOR ===\n");

    printf("Podaj poczatkowa liczbe: ");
    scanf("%f", &bufor);

    printf("Opcje: +, -, *, /, p (pierwiastek), c (czysc/nowa liczba), q (wyjdz)\n");

    while (1) {
        printf("\n------------------------\n");
        printf("Aktualny wynik (bufor): %.2f\n", bufor);
        printf("Podaj znak dzialania: ");
        scanf(" %c", &znak);

        if (znak == 'q') {
            printf("Wychodzenie z programu. Do widzenia!\n");
            break; 
        } 
        else if (znak == 'c') {
            printf("Podaj nowa poczatkowa liczbe: ");
            scanf("%f", &bufor);
            continue; 
        } 
        else if (znak == 'p') {
            if (bufor >= 0) {
                bufor = sqrt(bufor);
            } else {
                printf("Blad: Nie mozna pierwiastkowac liczby ujemnej!\n");
            }
            continue; 
        }

        printf("Podaj liczbe: ");
        scanf("%f", &liczba);

        switch (znak) {
            case '+':
                bufor = bufor + liczba;
                break;
            case '-':
                bufor = bufor - liczba;
                break;
            case '*':
                bufor = bufor * liczba;
                break;
            case '/':
                if (liczba != 0) {
                    bufor = bufor / liczba;
                } else {
                    printf("Blad: Nie mozna dzielic przez zero!\n");
                }
                break;
            default:
                printf("Blad: Nieznany znak dzialania!\n");
        }
    }

    return 0;
}