#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void desenhoDado(char dado);

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

void desenhoDado(char dado) {
    if (dado == 1) {

        printf(".........");
        printf(".       .");
        printf(".   *   .");
        printf(".       .");
        printf(".........");

    }

    else if (dado == 2) {

        printf(".........");
        printf(".*      .");
        printf(".       .");
        printf(".      *.");
        printf(".........");

    }

    else if (dado == 3) {

        printf(".........");
        printf(".*      .");
        printf(".       .");
        printf(".      *.");
        printf(".........");

    }


}