#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {

    int num;
    srand(time(NULL));

    num = rand()%10;
    printf("%d\n", num);

    return 0;

}
