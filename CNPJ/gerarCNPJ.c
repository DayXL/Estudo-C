#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char esc;

    printf("Bem-vindo ao gerador de CNPJ");

    esc = '1';

    while (esc == '1') {
        printf("\nDeseja gerar um CNPJ? 1 para sim, 0 para nao.");

        scanf("%c" , &esc);
        getchar();

    }

}