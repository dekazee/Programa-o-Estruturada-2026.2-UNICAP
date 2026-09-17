#include <stdio.h>


void troca(int *a, int *b);

int main() {
    int numero1 = 10, numero2 = 20;
    printf("numero1 = %d e numero2 = %d\n", numero1,numero2);
    troca(&numero1,&numero2);
    printf("numero1 = %d e numero2 = %d\n", numero1, numero2);

}

void troca(int *a, int *b) {
    printf("*a = %d e *b = %d\n", *a, *b);
    int aux = *a;
    *a = *b;
    *b = aux;
    printf("*a = %d e *b = %d\n", *a, *b);
    
}