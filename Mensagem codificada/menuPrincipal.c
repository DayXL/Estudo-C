#include <stdio.h>
#include <stdlib.h>

char verMenuPrincipal(void);
void arqEntrada(char *txt);
void arqSaid(char *txt);
void passarEnter(void);
char auxEscolha(void);

int main(void) {
    char esc = verMenuPrincipal();

    while (esc!='0') {

        if (esc=='1') {
            printf("Codificar");

        }

        else if (esc=='2') {
            printf("Descodificar");

        }

        else {
            printf("Opção inválida!");
        
        }

        passarEnter();

        esc = verMenuPrincipal();
    }
        

    printf("Programa finalizado!");


    return 0;
}

char verMenuPrincipal(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===           = = = = = PROGRAMA TOP SECRET = = = = =                       ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Codificar mensagem                                   ===\n");
    printf("===                 2. Descodificar mensagem                                ===\n");
    printf("===                 0. Sair                                                 ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void arqEntrada(char *txt) {

    FILE *fp;

    fp = fopen("arquEnt.txt","at");

        if (fp == NULL){
            printf("Criando novo arquivo!");
            fp = fopen("arquEnt.txt","wt");

            if (fp == NULL) {
                printf("Erro ao criar arquivo!");

            }

            else {
                fprintf(fp,txt, "\n");

            }
        }

        else {
            fprintf(fp,txt, "\n");

        }

}

void arqSaid(char *txt) {

    FILE *fp;

    fp = fopen("arquSaid.txt","at");

        if (fp == NULL){
            printf("Criando novo arquivo!");
            fp = fopen("arquSaid.txt","wt");

            if (fp == NULL) {
                printf("Erro ao criar arquivo!");

            }

            else {
                fprintf(fp,txt, "\n");

            }
        }

        else {
            fprintf(fp,txt, "\n");

        }

}

void passarEnter(void) {

    printf("Tecle ENTER para continuar");
    getchar();

}

char auxEscolha(void) {

    printf("Selecione sua opção:");
    char esc;
    scanf("%c" , &esc);
    getchar();

    return esc;

}