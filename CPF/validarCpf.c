#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    char esc;

    printf("Bem-vindo ao validador de CPF");

    esc = '1';

    while (esc == '1') {
        printf("\nDeseja gerar validar um CPF? 1 para sim, 0 para nao.");

        scanf("%c" , &esc);
        getchar();

        char cpf[13];
        int tam;

        printf("CPF(somente números): ");
        fgets(cpf, 13, stdin);

        tam = strlen(cpf);
        cpf[tam - 1] = '\0';

    }

}


