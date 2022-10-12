#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sortear(void);

int main(void) {
    char esc;

    srand(time(NULL));
    printf("Bem-vindo ao gerador de CNPJ");

    esc = '1';

    while (esc == '1') {
        printf("\nDeseja gerar um CNPJ? 1 para sim, 0 para nao.");

        scanf("%c" , &esc);
        getchar();

    }

}

int sortear(void) {

    int num;

    num = rand()%10;

    return num;

}