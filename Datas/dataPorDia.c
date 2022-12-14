#include <stdio.h>
#include <stdlib.h>

void diaParaData(int dia, int ano, int *data);
int anoBissexto(int ano);

int main(void) {
    int dia;
    int data[3] = {};

    system ( " clear||cls " );

    printf("Digite o dia: ");
    scanf("%d", &dia);
    getchar();

    diaParaData(dia, 2022, data);

    printf("Data: %d/%d/%d\n", data[0], data[1], data[2]);

    printf("\nPrograma encerrado\n");

}

void diaParaData(int dia, int ano, int *data) {

    int diasDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = 0;

    if (dia > 365) {
        dia = dia - 365;
        ano = ano + 1;
    }

    while (i < 12 && dia >= 0) {
        dia = dia - diasDoMes[i];

        i = i + 1;
    }

    if (anoBissexto(ano)) {
        if (i > 1) {
            dia = dia - 1;

        }
        else if (i == 1 && dia == 0) {
            dia = dia - 1;
        }
    }

    data[0] = diasDoMes[i - 1] + dia;
    data[1] =  i;
    data[2] = ano;

}

int anoBissexto(int ano) {
    int a;

    //Caso ele siga a expressão nos parenteses retornara 1, caso não, irá retorna 0.
    a = (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)) ? 1 : 0;

    return a;

}

