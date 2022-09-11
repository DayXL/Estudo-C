#include <stdio.h>

int dataValida(int, int, int);
int anoBissexto(int);

int main(void) {
    int dia;
    int mes;
    int ano;
    int a;

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
        printf("Data valida");
    }

    else {
        printf("Data invalida");

    }

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