#include <stdio.h>
#include <stdlib.h>
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

int main(void) {
    printf("Todos os pedidos disponiveis: ");

    lerArqPedClt();

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