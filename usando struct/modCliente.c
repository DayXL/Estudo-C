#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modCliente.h"
#include "funcoesAux.h"

void cadastrarCliente(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===               = = = = = Cadastrar cliente = = = = =                     ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    
    validarNomeCliente();

    validarCPF();

    validarNumeroCelular();

    validarEmail();

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void validarNomeCliente(void) {
    int tam;
    char nomeCliente[100];

    do {

        printf("Nome do cliente: ");
        fgets(nomeCliente, 100, stdin);

        tam = strlen(nomeCliente);
        nomeCliente[tam - 1] = '\0';

    } while ((tam == 1) || !(validarPalavra(nomeCliente))); 

}

void validarCPF(void) {
    int tam;
    char cpf[30];

    do {

        do {

            printf("CPF(somente números): ");
            fgets(cpf, 30, stdin);

            tam = strlen(cpf);
            cpf[tam - 1] = '\0';

        } while ((tam != 12) || !validarNumInteiro(cpf));

    } while (!verificarCpf(cpf));

    printf(" ");
    printf("CPF válido!\n");

}

void validarNumeroCelular(void) {
    int tam;
    char numero[30];

    do {

        printf("Número de celular(somente números): ");
        fgets(numero, 30, stdin);

        tam = strlen(numero);
        numero[tam - 1] = '\0';

    } while ((tam != 12) || !validarNumInteiro(numero));

} 

void validarEmail(void) {
    int tam;
    char email[100];

    do {

        printf("Email: ");
        fgets(email, 100, stdin);

        tam = strlen(email);
        email[tam - 1] = '\0';

    } while ((tam == 1) || !verificarEmail(email, tam));

}