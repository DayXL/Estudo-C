#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sortear(void);
void gerarCnpj(void);

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

void gerarCnpj(void) {
    
    int cnpj[13] = {};

    for (int i = 0; i < 12 ; i++ ) {
        int num = 0;

        num = sortear();

        cpf[i] = num;

    }

    escolheVerificadoCNPJ(cnpj);

    for (int i = 0; i < 11 ; i++ ) {

        printf("%d" , cnpj[i]);

    }

}