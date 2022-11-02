#include <stdio.h>
#include <stdlib.h>

int main(void) {

    FILE *fp;
    char linha1[20];
    char linha2[20];
    char linha3[20];

    do {
        fp = fopen("arquivo.txt","at");

        if (fp == NULL){
            printf("Erro na criacao do arquivo\n!");

        }

    } while (fp == NULL);

    printf("Digite o texto desejado para gravar ate 20 caracteres: ");

    fgets(linha1, 20, stdin);

    printf("Digite o texto desejado para gravar ate 20 caracteres: ");

    fgets(linha2, 20, stdin);

    printf("Digite o texto desejado para gravar ate 20 caracteres: ");

    fgets(linha3, 20, stdin);

    fprintf(fp,linha1, "\n");
    fprintf(fp,linha2, "\n");
    fprintf(fp,linha3, "\n");

    fclose(fp);

    return 0;
}