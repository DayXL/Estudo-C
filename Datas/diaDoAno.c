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
    int diasDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < mes; i++) {

        if (mes == 1) {
        return dia;

        }
    
        else if (mes == 2) {
        return dia + 31;

        }

        else {
            diaDoAno = diaDoAno + diasDoMes[i];

        }


    }

    diaDoAno = diaDoAno + dia;

    if ((mes == 2) && anoBissexto(ano)) {
        diaDoAno = diaDoAno + 1;

    }

    return diaDoAno;
    
}

