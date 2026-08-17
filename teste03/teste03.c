#include <stdio.h>

double nomeFuncao(double parametro, int parametro02) {
    double teste;
    teste = parametro + parametro02;
    return teste;
}

int main(){
    double legal;
    int diferente;
    legal = 67.32;
    diferente = 42;

    printf("%f",nomeFuncao(legal, diferente));

    return 0;

}