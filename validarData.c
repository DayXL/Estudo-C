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

    a = anoBissexto(ano);

    if (a == 1) {
        printf("Ano bissexto");
    }

    else {
        printf("Ano não bissexto");

    }

}

int anoBissexto(int ano) {
    int a;

    //Caso ele siga a expressão nos parenteses retornara 1, caso não, irá retorna 0.
    a = (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)) ? 1 : 0;

    return a;

}