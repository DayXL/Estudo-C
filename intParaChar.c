#include <stdio.h>
#include <stdlib.h>

char* intParaChar(int num);

int main(void) {
    int dia;
    char *data

    system ( " clear||cls " );

    printf("Digite o dia (Até 31): ");
    scanf("%d", &dia);
    getchar();

    data = intParaChar(dia);

    printf("\nPrograma encerrado\n");

}

char* intParaChar(int num) {
    int i = 0;
    char* data = (char*) malloc((11)* sizeof(char));;

    while (num > 0) {
        num = num - 10;
        i = i + 1;

    }

    printf("\nValor de i: %d\n", i);

    printf("\nResta: %d\n", num);

    return data;
}

