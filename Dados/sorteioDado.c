#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void desenhoDado(int dado);
void sortearDado(void);

int main(void) {
    char esc;

    srand(time(NULL));
    printf("Bem-vindo ao girar dado");

    esc = '1';

    while (esc == '1') {
        printf("\nDeseja gerar um dado? 1 para sim, 0 para nao.");

        scanf("%c" , &esc);
        getchar();

        sortearDado();

    }

}

void sortearDado(void) {

    int num;

    num = rand()%10;

    desenhoDado(num);

}

void desenhoDado(int dado) {
    if (dado == 1) {

        printf(".........\n");
        printf(".       .\n");
        printf(".   *   .\n");
        printf(".       .\n");
        printf(".........\n");

    }

    else if (dado == 2) {

        printf(".........\n");
        printf(".*      .\n");
        printf(".       .\n");
        printf(".      *.\n");
        printf(".........\n");

    }

    else if (dado == 3) {

        printf(".........\n");
        printf(".*      .\n");
        printf(".   *   .\n");
        printf(".      *.\n");
        printf(".........\n");

    }

    else if (dado == 4) {

        printf(".........\n");
        printf(".*     *.\n");
        printf(".       .\n");
        printf(".*     *.\n");
        printf(".........\n");

    }

    else if (dado == 5) {

        printf(".........\n");
        printf(".*     *.\n");
        printf(".   *   .\n");
        printf(".*     *.\n");
        printf(".........\n");

    }

    else {

        printf(".........\n");
        printf(".*     *.\n");
        printf(".*     *.\n");
        printf(".*     *.\n");
        printf(".........\n");

    }

}