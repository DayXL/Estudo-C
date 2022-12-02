#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct titanic Titanic;

struct Titanic {
    char id[4];
    char sobr;
    char clas;
    char nome[255];
    char sex;
    char idade[3];
    int parents;
    char bilhet[50];
    float tarifa;
    char cabine[20];
    char embarcou;

    Titanic* prox;

};

void lerArq(void);

int main(void) {
    lerArq();

    return 0;

}


void lerArq(void) {
    FILE *fp;
    char letra;

    fp = fopen("titanic.csv","rt");

    if (fp == NULL){
        printf("Erro ao abrir o arquivo\n!");

    }

    else {

        //De Flavius

        letra = fgetc(fp);
        
        char letraAnt;
        int i = 0;

        while (letra != EOF) {

            if (letra == '"') {
                i = i + 1;

            }

            else if ((letra == ',') && (i % 2 == 0)) {
                printf("\n");

            }
            else {
                printf("%c", letra);

            }

            letra = fgetc(fp);

        }

    }

}