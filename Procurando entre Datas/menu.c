#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct pedidoCliente PedidoCliente;

struct pedidoCliente {

    char pedido[20];
    char cpf[12];
    char codigo[6];
    float quant;
    char cor[30];

};

void lerArqPedClt(void);
void exibPedido(PedidoCliente *pedClt);
int anoBissexto(int ano);
int dataValida(int dia, int mes, int ano);
long int charParaInt(char *num);
long int poten(int num, int pot);
int validarNumParData(char *numero);

int main(void) {
    char data[30];
    int tam;

    //printf("Todos os pedidos disponiveis: ");

    //lerArqPedClt();

    do {
        printf("\nDigite a primeira data: (dd/mm/ano) ");
        fgets(data, 30, stdin);

        tam = strlen(data);
        data[tam - 1] = '\0';

    } while (!validarNumParData(data));    

    printf("a");
    return 0;

}

void lerArqPedClt(void) {
    
    FILE *fp;
    PedidoCliente *pedClt;
    
    if (access("arqPedClt.dat", F_OK) != -1) {

        fp = fopen("arqPedClt.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {

            pedClt = (PedidoCliente*) malloc(sizeof(PedidoCliente));

            while (fread(pedClt, sizeof(PedidoCliente), 1, fp)) {

                exibPedido(pedClt);

            }

            free(pedClt);

        }

        fclose(fp);
    }

}

void exibPedido(PedidoCliente *pedClt) {
    
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("\n");
    printf("== Número do pedido: ");
    printf("%s" ,pedClt->pedido);
    printf("\n");
    printf("== CPF do cliente: ");
    printf("%s" ,pedClt->cpf);
    printf("\n");
    printf("== Código do boné: ");
    printf("%s" ,pedClt->codigo);
    printf("\n");
    printf("== Quantidade: ");
    printf("%f" ,pedClt->quant);
    printf("\n");
    printf("== Cor: ");
    printf("%s" ,pedClt->cor);
    printf("\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

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

long int charParaInt(char *num) {
    long int soma = 0;
    int tam = strlen(num);
    int aux = tam - 1; 

    if (tam == 1) {
        return num[0] - '0';

    }

    for (int i = 0; i <= tam - 1; i++) {
        
        soma = soma + ((num[i] - '0') * poten(10, aux));

        aux = aux - 1;

    }

    return soma;

}

long int poten(int num, int pot) {
    long int soma = num;

    if (pot == 0) {
        return 1;
    }

    else if (pot == 1) {
        return num;
    }

    for (int i = 2; i <= pot; i++ ) {
        soma = soma * num;
        
    }

    return soma;

}

int validarNumParData(char *numero) {
    int i = 0;
    int tam = strlen(numero);
    int aux = 0;

    if (tam != 10) {
        return 0;

    }

    while (numero[i] != '\0') {
        if ((numero[i] >= '0') && (numero[i] <= '9')) {
            i = i + 1;

        }

        else if (numero[i] == '/') {
            aux = aux + 1;

            if ((i == 2) || (i == 5)) {
                i = i + 1;

            }

            else {

                return 0;
            }

        }

        else {
            return 0;

        }

    }

    if (aux != 2) {
        return 0;

    }

    return 1;

}