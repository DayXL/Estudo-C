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
int anoBissexto(long int ano);
int dataValida(long int dia, long int mes, long int ano);
long int charParaInt(char *num);
long int poten(int num, int pot);
int validarNumParData(char *numero);
char* dividPal(char *pal, int del1, int del2);
void lerArqPedCltEntDat(long int *diaMesAno1, long int *diaMesAno2);

int main(void) {
    char data1[30];
    char data2[30];
    int aux = 0;
    int tam;
    char* dia;
    char* mes;
    char* ano;
    long int vetDiaMesAno1[3];
    long int vetDiaMesAno2[3];

    //printf("Todos os pedidos disponiveis: ");

    //lerArqPedClt();

    do {

        printf("\nDigite a primeira data: (dd/mm/aa) ");
        fgets(data1, 30, stdin);

        tam = strlen(data1);
        data1[tam - 1] = '\0';

        if (validarNumParData(data1) == 1) {
            dia = dividPal(data1, 0, 1);
            mes = dividPal(data1, 3, 4);
            ano = dividPal(data1, 6, 7);

            vetDiaMesAno1[0] = charParaInt(dia);
            vetDiaMesAno1[1] = charParaInt(mes);
            vetDiaMesAno1[2] = charParaInt(ano);

            if (dataValida(vetDiaMesAno1[0], vetDiaMesAno1[1], vetDiaMesAno1[2]) == 1) {

                aux = 1;
            
            }
        }

    } while (aux == 0);

    do {

        printf("\nDigite a segunda data: (dd/mm/ano) ");
        fgets(data2, 30, stdin);

        tam = strlen(data2);
        data2[tam - 1] = '\0';

        if (validarNumParData(data2) == 1) {
            dia = dividPal(data2, 0, 1);
            mes = dividPal(data2, 3, 4);
            ano = dividPal(data2, 6, 7);

            vetDiaMesAno2[0] = charParaInt(dia);
            vetDiaMesAno2[1] = charParaInt(mes);
            vetDiaMesAno2[2] = charParaInt(ano);

            if (dataValida(vetDiaMesAno2[0], vetDiaMesAno2[1], vetDiaMesAno2[2]) == 1) {

                aux = 1;
            
            }
        }

    } while (aux == 0);

    lerArqPedCltEntDat(vetDiaMesAno1, vetDiaMesAno2);

    free(dia);
    free(mes);
    free(ano);

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

int anoBissexto(long int ano) {
    int a;

    //Caso ele siga a expressão nos parenteses retornara 1, caso não, irá retorna 0.
    a = (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)) ? 1 : 0;

    return a;

}

int dataValida(long int dia, long int mes, long int ano) {
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

    if (tam != 8) {
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

char* dividPal(char *pal, int del1, int del2) {
    int tam = del2 - del1;
    int aux = 0;

    char* palavra = (char*) malloc((tam + 1) * sizeof(char));

    palavra[0] = pal[del1];

    for (int i = del1; i <= del2; i++) {
        
        palavra[aux] = pal[i];

        aux = aux + 1;

    }

    palavra[tam + 1] = '\0';
    
    return palavra;

}

void lerArqPedCltEntDat(long int *diaMesAno1, long int *diaMesAno2) {
    
    FILE *fp;
    PedidoCliente *pedClt;

    char* dia;
    char* mes;
    char* ano;
    long int vetDiaMesAnoPed[3];
    
    if (access("arqPedClt.dat", F_OK) != -1) {

        fp = fopen("arqPedClt.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {

            pedClt = (PedidoCliente*) malloc(sizeof(PedidoCliente));

            while (fread(pedClt, sizeof(PedidoCliente), 1, fp)) {

                dia = dividPal(pedClt->pedido, 0, 1);
                mes = dividPal(pedClt->pedido, 2, 3);
                ano = dividPal(pedClt->pedido, 4, 5);
            
                vetDiaMesAnoPed[0] = charParaInt(dia);
                vetDiaMesAnoPed[1] = charParaInt(mes);
                vetDiaMesAnoPed[2] = charParaInt(ano);               

                if ((vetDiaMesAnoPed[2] >= diaMesAno1[2]) && (vetDiaMesAnoPed[2] <= diaMesAno2[2])) {

                    if ((vetDiaMesAnoPed[1] >= diaMesAno1[1]) && (vetDiaMesAnoPed[1] <= diaMesAno2[1])) {

                        if ((vetDiaMesAnoPed[0] >= diaMesAno1[0]) && (vetDiaMesAnoPed[0] <= diaMesAno2[0])) {
                            exibPedido(pedClt);

                        }

                    }

                }


            }

            free(pedClt);

        }

        fclose(fp);
    }

    free(dia);
    free(mes);
    free(ano);

}