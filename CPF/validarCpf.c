#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificarCpf(char *cpf);


int main(void) {
    char esc;

    printf("Bem-vindo ao validador de CPF");

    esc = '1';

    while (esc == '1') {
        printf("\nDeseja validar um CPF? 1 para sim, 0 para nao. ");

        scanf("%c" , &esc);
        getchar();

        if (esc=='0') {
            printf("Fim do programa");
            esc = '0';

        }
        else if (esc!='1') {
            printf("Escolha inválida");
            esc = '1';

        }

        else {

            char cpf[13];
            int tam;
            int a;

            printf("CPF(somente números): ");
            fgets(cpf, 13, stdin);

            tam = strlen(cpf);
            cpf[tam - 1] = '\0';

            a = verificarCpf(cpf);
            
            if (a==1) {
                printf("CPF válido");

            }

            else {
                printf("CPF inválido");

            }
        }
    }

}

int verificarCpf(char *cpf) {

    int soma = 0;
    int resto = 0;

    for (int i = 0; i < 9; i++) {
        soma = soma + ((cpf[i] - '0' ) * (i + 1));

    }

    resto = soma % 11;

    resto = (resto == 10) ? 0 : resto;

    if (resto == (cpf[9] - '0' )) {
        soma = 0;

        for (int i = 0; i < 10; i++) {
            soma = soma + ((cpf[i] - '0' ) * (i));

        }

        resto = soma % 11;

        resto = (resto == 10) ? 0 : resto;

        if (resto == (cpf[10] - '0' )) {
            return 1;

        }

        else {
            return 0;
        }

    }

    else {
        return 0;

    }

}

