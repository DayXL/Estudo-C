#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sortear(void);

int main(void) {
    char esc;

    printf("Bem-vindo ao gerador de CPF");
    printf("\nDeseja gerar um CPF? 1 para sim, 0 para nao.");

    scanf("%c" , &esc);
    getchar();

    while (esc) {
        int cpf;
        
        cpf = gerarCpf();

    }


    sortear();

}

int sortear(void) {

    int num;
    srand(time(NULL));

    num = rand()%10;
    printf("%d\n", num);

    return 0;

}

int gerarCpf(void) {


}