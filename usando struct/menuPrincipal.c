#include <stdio.h>
#include <stdlib.h>
#include "funcoesAux.h"


char verMenuPrincipal(void);

int main(void) {

    char esc = verMenuPrincipal();

    while (esc!='0') {

        if (esc=='1') {
            printf("1. Cadastrar cliente\n");
        }

        else if (esc=='2') {
            printf("2. Ver cliente\n");

        }

        else {
            printf("Opção inválida!");
        
        }

        passarEnter();

        esc = verMenuPrincipal();
    }
        

    printf("Programa finalizado!\n");

    return 0;
}

char verMenuPrincipal(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                   = = = = = Cliente = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Cadastrar cliente                                    ===\n");
    printf("===                 2. Ver cliente                                          ===\n");
    printf("===                 0. Finalizar                                            ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}