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
    FILE* fp;
    Cliente* clt;

    clt = (Cliente*) malloc(sizeof(Cliente));

    if (access("arqCliente.dat", F_OK) != -1) {
        
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
        printf("\nCliente j?? cadastrado! ");

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
    Cliente* clt;

    do {

        printf("CPF(somente n??meros): ");
        fgets(cpf, 30, stdin);

    } while (!verificarCpf(cpf));

    clt = acharClt(cpf);

    if (clt != NULL) {

        free(clt);
        return 1;

    }

    printf(" ");
    printf("CPF v??lido!\n");
    free(clt);
    return 0;

}

void validarNumeroCelular(char *numero) {
    int tam;

    do {

        printf("N??mero de celular(somente n??meros): ");
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
    printf("N??mero: ");
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
    printf("CPF(somente n??meros): ");
    fgets(cpf, 30, stdin);

    tam = strlen(cpf);
    cpf[tam - 1] = '\0';

    clt = acharClt(cpf);
     
    if (clt == NULL) {
        printf("Cliente n??o cadastrado! ");

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
    int achou = 0;

    printf("\n = Apagar Cliente = \n"); 
    printf("CPF(somente n??meros): ");
    fgets(cpf, 30, stdin);

    tam = strlen(cpf);
    cpf[tam - 1] = '\0';

    clt = acharClt(cpf);
     
    if (clt == NULL) {

        printf("Cliente n??o cadastrado! ");

    }

    else {

        aux = (Cliente*) malloc(sizeof(Cliente));
        fp = fopen("arqCliente.dat", "r+b");

        if (access("arqCliente.dat", F_OK) != -1) {

            if (fp == NULL) {
                printf("N??o foi poss??vel deletar!\n");

            }

            else {

                while(fread(aux, sizeof(Cliente), 1, fp) && (achou == 0)) {

                    if ((strcmp(aux->cpf, cpf) == 0) && (aux->ativo != 0)) {

                        achou = 1;
                        exibCliente(aux);

                        printf("\nDeseja realmente deletar?1 para sim, 0 para n??o.\n");
                        fgets(aux2, 20, stdin);
                        
                        tam = strlen(aux2);
                        aux2[tam - 1] = '\0';

                        if (strcmp(aux2, "1\0") == 0) {
                            aux->ativo = 0;

                            fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
                            fwrite(aux, sizeof(Cliente), 1, fp);

                            printf("\nCliente exclu??do com sucesso!\n");
                        }

                        else {
                            printf("\nCancelado!\n");

                        }

                    }

                }

            }
        }


        else {
            printf("\nErro com arquivo\n");

        }

        free(aux);
    }

    fclose(fp);
    free(clt);
}

void atlClt(void) {

    FILE* fp;
    Cliente* clt;
    Cliente* aux;
    char cpf[30];
    int tam;
    char aux2[20];
    int achou = 0;
    char nomeCliente[100];
    char numero[30];
    char email[100];
    char esc;

    printf("\n = Atualizar Cliente = \n"); 
    printf("CPF(somente n??meros): ");
    fgets(cpf, 30, stdin);

    tam = strlen(cpf);
    cpf[tam - 1] = '\0';

    clt = acharClt(cpf);
     
    if (clt == NULL) {

        printf("Cliente n??o cadastrado! ");

    }

    else {

        aux = (Cliente*) malloc(sizeof(Cliente));
        fp = fopen("arqCliente.dat", "r+b");

        if (access("arqCliente.dat", F_OK) != -1) {

            if (fp == NULL) {
                printf("N??o foi poss??vel atualizar!\n");
                
            }

            else {

                while(fread(aux, sizeof(Cliente), 1, fp) && (achou == 0)) {

                    if ((strcmp(aux->cpf, cpf) == 0) && (aux->ativo != 0)) {
                        achou = 1;
                        exibCliente(aux);

                        printf("\nDeseja realmente atualizar?1 para sim, 0 para n??o.\n");
                        fgets(aux2, 20, stdin);
                        
                        tam = strlen(aux2);
                        aux2[tam - 1] = '\0';

                        if (strcmp(aux2, "1\0") == 0) {

                            esc = telAtl();

                            while (esc!='0') {

                                if (esc=='1') {
                                    validarNomeCliente(nomeCliente);
                                    strcpy(aux->nomeDoCliente,nomeCliente);

                                }

                                else if (esc=='2') {
                                    validarNumeroCelular(numero);
                                    strcpy(aux->numero,numero);

                                }

                                else if (esc=='3') {
                                    validarEmail(email);
                                    strcpy(aux->email,email); 

                                }

                                else if (esc=='4') {
                                    validarNomeCliente(nomeCliente);

                                    validarNumeroCelular(numero);

                                    validarEmail(email);

                                    strcpy(aux->nomeDoCliente,nomeCliente);
                                    strcpy(aux->numero,numero);
                                    strcpy(aux->email,email); 
                                }

                                else {
                                    printf("Op????o inv??lida!\n");
                                
                                }

                                esc = telAtl();
                            }
  
                            fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
                            fwrite(aux, sizeof(Cliente), 1, fp);

                            printf("\nCliente atualizado com sucesso!\n");
                        }

                        else {
                            printf("\nCancelado!\n");

                        }

                    }

                }

            }
        }

        else {
            printf("\nErro com arquivo\n");

        }
        free(aux);
    }

    fclose(fp);
    free(clt);
}

char telAtl(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                 = = = = = Atualizar = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Nome                                                 ===\n");
    printf("===                 2. Telefone                                             ===\n");
    printf("===                 3. Email                                                ===\n");
    printf("===                 4. Atualizar tudo                                       ===\n");
    printf("===                 0. Sair                                                 ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}