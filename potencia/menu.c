#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int poten(int num, int pot);

int main(void) {
    int num;
    int num2;
    long int result;


    printf("Digite a base: ");
    scanf("%d", &num);

    printf("Digite o expoente: ");
    scanf("%d", &num2);

    result = poten(num, num2);

    printf("O resultado é: %ld", result);
    printf("\n");
}

int poten(int num, int pot) {
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