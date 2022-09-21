#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    char esc;

    srand(time(NULL));
    printf("Bem-vindo ao girar dado");

    esc = '1';

    while (esc == '1') {
        printf("\nDeseja gerar um dado? 1 para sim, 0 para nao.");

        scanf("%c" , &esc);
        getchar();

    }

}