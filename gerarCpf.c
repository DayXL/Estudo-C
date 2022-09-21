#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sortear(void);
void gerarCpf(void);
void escolheVerificadoCPF(int *cpf);

int main(void) {
    char esc;

    srand(time(NULL));
    printf("Bem-vindo ao gerador de CPF");
    printf("\nDeseja gerar um CPF? 1 para sim, 0 para nao.");

    scanf("%c" , &esc);
    getchar();

    while (esc) {
        gerarCpf();

        printf("\nDeseja gerar um CPF? 1 para sim, 0 para nao.");

        scanf("%c" , &esc);
        getchar();

    }

}

int sortear(void) {

    int num;

    num = rand()%10;

    return num;

}

void gerarCpf(void) {
    int cpf[11] = {};

    for (int i = 0; i < 9 ; i++ ) {
        int num = 0;

        num = sortear();

        cpf[i] = num;

        printf("%d", num);

    }

}

void escolheVerificadoCPF(int *cpf) {

    int soma = 0;
    int resto = 0;

    for (int i = 0; i < 9; i++) {
        soma = soma + (cpf[i] * (i + 1));

    }

    resto = soma % 11;

    resto = (resto == 10) ? 0 : resto;

    cpf[9] = resto;

    soma = 0;

    for (int i = 0; i < 10; i++) {
        soma = soma + (cpf[i] * (i));

    }

    resto = soma % 11;

    resto = (resto == 10) ? 0 : resto;

    cpf[10] = resto;

}