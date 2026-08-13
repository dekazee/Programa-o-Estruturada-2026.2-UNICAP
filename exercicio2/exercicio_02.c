#include <stdio.h>

#define QUANTIDADE_VEZES 50
#define VALOR_INCREMENTO 1
#define VALOR_INICIAL 1

int main() {

    for(int i=VALOR_INICIAL; i<=QUANTIDADE_VEZES; i+=VALOR_INCREMENTO) {


        if( i % 3 == 0 ||  i % 10 == 3) {
            printf("PI");
        
        } else {
            printf("%d", i);
        }
        if ( i < QUANTIDADE_VEZES) {
                printf(", ");
            }

    }
    printf("\n");
    return 0;
}