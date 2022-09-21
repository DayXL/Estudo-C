#include <stdio.h>

// Atividade de validar data

int dataValida(int, int, int);
int anoBissexto(int);
int escolha(void);

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
            printf("Data válida");
            printf("\n");

            a = escolha();

        }

        else {
            printf("Data inválida");
            printf("\n");

            a = escolha();

        }

    }

    printf("Programa encerrado");

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

int escolha(void) {
    int op;
    int a;

    printf("Deseja testar outra data? 1 para sim, 2 para não" );
    scanf("%d", &op);
    system ( " clear||cls " );

    a = (op == 1) ? 0 : 1;

    return a;

}