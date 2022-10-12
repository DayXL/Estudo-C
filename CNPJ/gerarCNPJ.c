#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sortear(void);
void gerarCnpj(void);
void escolheVerificadoCNPJ(int *cnpj);

int main(void) {
    char esc;

    srand(time(NULL));
    printf("Bem-vindo ao gerador de CNPJ");

    esc = '1';

    while (esc == '1') {
        printf("\nDeseja gerar um CNPJ? 1 para sim, 0 para nao.");

        scanf("%c" , &esc);
        getchar();

        gerarCnpj();

    }

}

int sortear(void) {

    int num;

    num = rand()%10;

    return num;

}

void gerarCnpj(void) {
    
    int cnpj[14] = {};

    for (int i = 0; i < 12 ; i++ ) {
        int num = 0;

        num = sortear();

        cnpj[i] = num;

    }

    escolheVerificadoCNPJ(cnpj);

    for (int i = 0; i < 14 ; i++ ) {

        printf("%d" , cnpj[i]);

    }

}

void escolheVerificadoCNPJ(int *cnpj) {

    int parteUm[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int parteDois[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

    int soma = 0;
    int resto = 0;

    for (int i = 0; i < 12; i++) {
        soma = soma + ((cnpj[i]) * (parteUm[i]));

    }

    resto = soma % 11;

    resto = (resto == 0 || resto == 1) ? 0 : 11 - resto;

    cnpj[12] = resto;

    soma = 0;

    for (int i = 0; i < 13; i++) {
        soma = soma + ((cnpj[i]) * (parteDois[i]));

    }

    resto = soma % 11;

    resto = (resto == 0 || resto == 1) ? 0 : 11 - resto;

    cnpj[13] = resto;

}