#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modCliente.h"
#include "funcoesAux.h"

DadosCliente clt;

void cadastrarCliente(void) {

    char nomeCliente[100];
    char cpf[30];
    char numero[30];
    char email[100];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===               = = = = = Cadastrar cliente = = = = =                     ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    
    validarNomeCliente(nomeCliente);

    validarCPF(cpf);

    validarNumeroCelular(numero);

    validarEmail(email);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    strcpy(clt.nomeDoCliente,nomeCliente);
    strcpy(clt.cpf,cpf);
    strcpy(clt.numero,numero);
    strcpy(clt.email,email);

}

void validarNomeCliente(char *nome) {
    int tam;

    do {

        printf("Nome do cliente: ");
        fgets(nome, 100, stdin);

        tam = strlen(nome);
        nome[tam - 1] = '\0';

    } while ((tam == 1) || !(validarPalavra(nome))); 

}

void validarCPF(char *cpf) {
    int tam;

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

void validarNumeroCelular(char *numero) {
    int tam;

    do {

        printf("Número de celular(somente números): ");
        fgets(numero, 30, stdin);

        tam = strlen(numero);
        numero[tam - 1] = '\0';

    } while ((tam != 12) || !validarNumInteiro(numero));

} 

void validarEmail(char *email) {
    int tam;

    do {

        printf("Email: ");
        fgets(email, 100, stdin);

        tam = strlen(email);
        email[tam - 1] = '\0';

    } while ((tam == 1) || !verificarEmail(email, tam));

}

void verCliente(void) {

    printf("%s" ,clt.nomeDoCliente);
    printf("\n");
    printf("%s" ,clt.cpf);
    printf("\n");
    printf("%s" ,clt.numero);
    printf("\n");
    printf("%s" ,clt.email);
    printf("\n");

}