#include <stdio.h>
#include "cabecalhoData.h"

int diaDoAno(int, int, int);

int main(void) {
    int dia;
    int mes;
    int ano;
    int a = 0;

    while (a == 0) {

        printf("Digite o dia: ");
        scanf("%d", &dia);
        getchar();

        printf("Digite o mês: ");
        scanf("%d", &mes);
        getchar();

        printf("Digite o ano: ");
        scanf("%d", &ano);
        getchar();

        a = dataValida(dia, mes, ano);

        if (a == 1) {
            int diaDoAno(dia, mes, ano);

        }

        else {
            printf("Data inválida");
            printf("\n");

        }

    }

    printf("Programa encerrado");

}

int diaDoAno(int dia , int mes, int ano) {
    int diaDoAno = 0; 

    if (mes == 1) {
        diaDoAno = dia;

    }
    
    else if (mes == 2) {
        diaDoAno = dia + 31;

    }



}

