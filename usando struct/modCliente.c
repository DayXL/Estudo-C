#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modCliente.h"
#include "funcoesAux.h"

typedef struct cliente Cliente;

void salArqClt(Cliente* clt) {
    FILE *fp;

    fp = fopen("arqCliente.dat","ab");

    if (fp == NULL){

      fp = fopen("arqCliente.dat","wb");
      printf("Arquivo inexistente!\n");
      printf("Criando novo arquivo!");

      if (fp == NULL) {
        printf("Erro com arquivo!");

      }

      else {
        fwrite(clt, sizeof(Cliente), 1, fp);

      }

    }

    else {
        fwrite(clt, sizeof(Cliente), 1, fp);

    }

    fclose(fp);

}

void lerArqClt(void) {

    FILE *fp;
    Cliente *clt;
    clt = (Cliente*) malloc(sizeof(Cliente));

    fp = fopen("arqCliente.dat","rb");

    if (fp == NULL) {
        printf("Erro com arquivo!");

    }

    else {

        while (fread(clt, sizeof(Cliente), 1, fp)) {

            if (clt->ativo != 0) {
                fread(clt, sizeof(Cliente), 1, fp);
                
                exibCliente(clt);

                free(clt);

            }
        }
    }

    fclose(fp);

}

Cliente* acharClt(char *cpf) {
    FILE* fp;
    Cliente* clt;

    clt = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("arqCliente.dat", "rb");

    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo!\n");

    }


    else {

        while(!feof(fp)) {
            fread(clt, sizeof(Cliente), 1, fp);

            if (strcmp(clt->cpf, cpf) == 0) {

                if (clt->ativo != 0) {
                    fclose(fp);
                    return clt;
                }

                else {
                    fclose(fp);
                    return NULL;
                }

            } 

        }

    }

    fclose(fp);
    return NULL;
}

void cadastrarCliente(void) {

    Cliente *clt;
    clt = (Cliente*) malloc(sizeof(Cliente));

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

    strcpy(clt->nomeDoCliente,nomeCliente);
    strcpy(clt->cpf,cpf);
    strcpy(clt->numero,numero);
    strcpy(clt->email,email);
    clt->ativo = 1;

    salArqClt(clt);

    free(clt);

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

void exibCliente(Cliente *clt) {

    printf("\n");
    printf("Nome do Cliente: ");
    printf("%s" ,clt->nomeDoCliente);
    printf("\n");
    printf("CPF: ");
    printf("%s" ,clt->cpf);
    printf("\n");
    printf("Número: ");
    printf("%s" ,clt->numero);
    printf("\n");
    printf("Email: ");
    printf("%s" ,clt->email);
    printf("\n");

}

void pesqClt(void) {
    Cliente* clt;
    char cpf[30];
    int tam;

    printf("\n = Pesquisar Cliente = \n"); 
    printf("CPF(somente números): ");
    fgets(cpf, 30, stdin);

    tam = strlen(cpf);
    cpf[tam - 1] = '\0';

    clt = acharClt(cpf);
     
    if (clt == NULL) {
        printf("Cliente não cadastrado! ");

    }

    else {
        exibCliente(clt);

    }

    free(clt);
}