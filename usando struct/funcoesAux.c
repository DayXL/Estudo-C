#include <stdio.h>
#include <stdlib.h>
#include "funcoesAux.h"

void passarEnter(void) {

    printf("Tecle ENTER para continuar");
    getchar();

}

char auxEscolha(void) {

    printf("Selecione sua opção:");
    char esc;
    scanf("%c" , &esc);
    getchar();

    return esc;

}

int validarPalavra(char *palavra) {
    
    int i = 0;

    while (palavra[i] != '\0') {   

        if (((palavra[i] >= 'a') && (palavra[i] <= 'z')) || (palavra[i] == ' ')) {
            i = i + 1;

        }

        else if ((palavra[i] >= 'A') && (palavra[i] <= 'Z')) {
            i = i + 1;

        }

        else {
            return 0;

        }

    }

    return 1;

}

int validarNumInteiro(char *numero) {
    int i = 0;

    while (numero[i] != '\0') {
        if ((numero[i] >= '0') && (numero[i] <= '9')) {
            i = i + 1;

        }

        else {
            return 0;

        }

    }

    return 1;

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

int verificarEmail(char *email, int tam) {
    int i = 0;
    int controleArroba = 0;
    int controle2 = 0;
    int controlePonto = 0;

    while (email[i] != '\0') {

        if (email[i] == '@') {

            controleArroba = i;

            i = i + 1;

            controle2 = controle2 + 1;

        }

        if ((i > controleArroba) && (email[i] == '.')) {

            controlePonto = i;

            if ((email[i + 1] == 'c') && (email[i + 2] == 'o') && (email[i + 3] == 'm') && (email[i + 4] == '\0')) {
                i = i + 1;

            }

            else {
                return 0;

            }

        }

        i = i + 1;

    }

    if ((controle2 == 0) || (controle2 > 1)) {
        return 0;
        
    }

    else if (controleArroba < 3) {
        return 0;

    }

    else if ((controlePonto - controleArroba) < 5 ) {
        return 0;

    }

    return 1;


}
