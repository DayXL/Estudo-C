#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int charParaInt(char *num);
long int poten(int num, int pot);

int main(void) {
    char num[20];
    int tam;
    long int result;

    printf("Bem-vindo ao char para long int\n");

    printf("Digite o número: ");
    fgets(num, 20, stdin);

    tam = strlen(num);
    num[tam - 1] = '\0';

    result = charParaInt(num);

    printf("\nResultado em long int: %ld", result);

    result = result + 10;

    printf("\nSomando dez : %ld", result);
}

long int charParaInt(char *num) {
    long int soma = 0;
    int tam = strlen(num);
    int aux = tam - 1; 

    if (tam == 1) {
        return num[0] - '0';

    }

    for (int i = 0; i <= tam - 1; i++) {
        
        soma = soma + ((num[i] - '0') * poten(10, aux));

        aux = aux - 1;

    }

    return soma;

}

long int poten(int num, int pot) {
    long int soma = num;

    if (pot == 0) {
        return 1;
    }

    else if (pot == 1) {
        return num;
    }

    for (int i = 2; i <= pot; i++ ) {
        soma = soma * num;
        
    }

    return soma;

}