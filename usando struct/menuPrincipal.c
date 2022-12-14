#include <stdio.h>
#include <stdlib.h>
#include "funcoesAux.h"
#include "modCliente.h"

typedef struct cliente Cliente;

char verMenuPrincipal(void);

int main(void) {

    char esc = verMenuPrincipal();

    while (esc!='0') {

        if (esc=='1') {
            cadastrarCliente();
        }

        else if (esc=='2') {
            lerArqClt();

        }

        else if (esc=='3') {
            pesqClt();

        }

        else if (esc=='4') {
            atlClt();

        }

        else if (esc=='5') {
            apgClt();
        }

        else {
            printf("Opção inválida!\n");
        
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
    printf("===                 2. Relatório cliente                                    ===\n");
    printf("===                 3. Pesquisar cliente                                    ===\n");
    printf("===                 4. Atualizar cliente                                    ===\n");
    printf("===                 5. Deletar cliente                                      ===\n");
    printf("===                 0. Finalizar                                            ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}