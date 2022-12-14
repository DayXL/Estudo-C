#include <stdio.h>
#include <stdlib.h>

int diaDoAno(int, int, int);
int dataValida(int, int, int);
int anoBissexto(int);
int escolha(void);

int main(void) {
    int dia;
    int mes;
    int ano;
    int a = 0;
    int diaCalc;

    while (a == 0) {

        system ( " clear||cls " );

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
            diaCalc = diaDoAno(dia, mes, ano);
            printf("\n");
            printf("%d", diaCalc);
            printf("\n");

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

    for (int i = 0; i < mes - 1; i++) {

        if (mes == 1) {
        return dia;

        }
    
        else if (mes == 2) {
        diaDoAno = dia + 31;

        }

        else {
            diaDoAno = diaDoAno + diasDoMes[i];

        }


    }

    diaDoAno = diaDoAno + dia;

    if ((mes >= 2) && anoBissexto(ano)) {
        diaDoAno = diaDoAno + 1;

    }

    return diaDoAno;

}

int anoBissexto(int ano) {
    int a;

    //Caso ele siga a expressão nos parenteses retornara 1, caso não, irá retorna 0.
    a = (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)) ? 1 : 0;

    return a;

}

int dataValida(int dia, int mes, int ano) {
    int maiorDiaMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maiorDia = 0;
    int a;

    if ((mes > 12) || (mes < 1)) {
        return 0;

    }

    maiorDia = maiorDiaMes[mes - 1];

    if ((mes == 2) && anoBissexto(ano)) {
        maiorDia = maiorDia + 1;

    }

    a = ((dia > maiorDia) || (dia < 0)) ? 0 : 1;

    return a;

}