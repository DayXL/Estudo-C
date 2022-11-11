#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "modCliente.h"
#include "funcoesAux.h"

typedef struct cliente Cliente;

void salArqClt(Cliente* clt) {
    FILE *fp;

    fp = fopen("arqCliente.dat","ab");

    if (fp == NULL){

        //fp = fopen("arqCliente.dat","wb");
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

    if (access("arqCliente.dat", F_OK) != -1) {

        fp = fopen("arqCliente.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {
            clt = (Cliente*) malloc(sizeof(Cliente));

            while (fread(clt, sizeof(Cliente), 1, fp)) {

                if (clt->ativo != 0) {
                    
                    exibCliente(clt);

                }
            }

            free(clt);
        }
    }

    fclose(fp);

}

Cliente* acharClt(char *cpf) {
    printf("\n Entrei na acharClt \n");
    FILE* fp;
    Cliente* clt;

    clt = (Cliente*) malloc(sizeof(Cliente));

    if (access("arqCliente.dat", F_OK) != -1) {
        printf("\n passei pelo if do access \n");

        fp = fopen("arqCliente.dat", "rb");

        if (fp == NULL) {
            printf("Ocorreu um erro na abertura do arquivo!\n");

        }

        else {

            while(fread(clt, sizeof(Cliente), 1, fp)) {

                if ((strcmp(clt->cpf, cpf) == 0) && (clt->ativo == 1)) {

                    fclose(fp);
                    return clt;

                } 

            }

        }
    }

    else {
        fp = fopen("arqCliente.dat", "wb");

    }

    fclose(fp);
    return NULL;
}

void cadastrarCliente(void) {

    printf("\n Entrei na Cadastrar Cliente \n");

    Cliente *clt;
    clt = (Cliente*) malloc(sizeof(Cliente));

    char nomeCliente[100];
    char cpf[30];
    char numero[30];
    char email[100];
    int jaCad;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===               = = = = = Cadastrar cliente = = = = =                     ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    
    jaCad = validarCPF(cpf);
    
    if (jaCad == 1) {
        printf("\nCliente já cadastrado! ");

    }

    else {
        validarNomeCliente(nomeCliente);

        validarNumeroCelular(numero);

        validarEmail(email);

        strcpy(clt->nomeDoCliente,nomeCliente);
        strcpy(clt->cpf,cpf);
        strcpy(clt->numero,numero);
        strcpy(clt->email,email);
        clt->ativo = 1;

        salArqClt(clt);

        printf("\nCliente cadastrado com sucesso! \n");

    }
    
    printf("===============================================================================\n");
    printf("\n");

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

int validarCPF(char *cpf) {

    printf("\n Entrei na validarCPF\n");
    Cliente* clt;

    do {

        printf("CPF(somente números): ");
        fgets(cpf, 30, stdin);

    } while (!verificarCpf(cpf));

    clt = acharClt(cpf);

    if (clt != NULL) {

        free(clt);
        return 1;

    }

    printf(" ");
    printf("CPF válido!\n");
    free(clt);
    return 0;

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

void apgClt(void) {

    FILE* fp;
    Cliente* clt;
    Cliente* aux;
    char cpf[30];
    int tam;
    char aux2[20];

    printf("\n = Apagar Cliente = \n"); 
    printf("CPF(somente números): ");
    fgets(cpf, 30, stdin);

    tam = strlen(cpf);
    cpf[tam - 1] = '\0';

    clt = acharClt(cpf);
     
    if (clt == NULL) {

        free(clt);
        printf("Cliente não cadastrado! ");

    }

    else {

        aux = (Cliente*) malloc(sizeof(Cliente));
        fp = fopen("arqCliente.dat", "r+b");

        if (access("arqCliente.dat", F_OK) != -1) {

            if (fp == NULL) {
                printf("Não foi possível deletar!\n");
                
            }

            else {

                while(fread(aux, sizeof(Cliente), 1, fp)) {

                    if ((strcmp(aux->cpf, cpf) == 0) && (aux->ativo != 0)) {
                        
                        exibCliente(aux);

                        printf("\nDeseja realmente deletar?1 para sim, 0 para não.\n");
                        fgets(aux2, 20, stdin);
                        
                        tam = strlen(aux2);
                        aux2[tam - 1] = '\0';

                        if (strcmp(aux2, "1\0") == 0) {
                            aux->ativo = 0;

                            fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
                            fwrite(aux, sizeof(Cliente), 1, fp);

                            printf("\nCliente excluído com sucesso!\n");
                        }

                        else {
                            printf("\nCancelado!\n");

                        }

                    }

                }

            }
            free(aux);
        }

        else {
            printf("\nErro com arquivo\n");

        }
    }

    fclose(fp);
    free(clt);
}