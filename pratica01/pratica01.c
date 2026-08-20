#include <stdio.h>

#define VALORES 10

void digitacaoVetor(int v[], int n);
void imprimirVetor(int v[], int n);
int checarMaiorNumero(int v[], int n);
int numeroNoVetor(int v[], int n, int numero);

int main() {
    int digitacao[VALORES];
    int indiceMaior = 0;
    int numeroLocalizado;
    
    digitacaoVetor(digitacao, VALORES);

    
    printf("Os valores digitados foram: \n");
    
    imprimirVetor(digitacao, VALORES);

    indiceMaior = checarMaiorNumero(digitacao, VALORES);

    printf("O maior valor desse vetor é: \n");
    printf(" %d\n", digitacao[indiceMaior]);

    printf("Digite um numero para verificar se estar dentro do vetor: \n");
    scanf(" %d", &numeroLocalizado);
    printf(" %d \n",numeroNoVetor(digitacao, VALORES, numeroLocalizado));

    return 0;


}

void digitacaoVetor(int v[], int n) {
    for(int i=0; i < n; i+=1) {
        printf("Digite um número inteiro: ");
        scanf(" %d", &v[i]);
    }
}

void imprimirVetor(int v[], int n) {
    printf("{");
    if( n > 0 ) {
        printf(" %d", v[0]);
    }
    for( int i=1; i < n; i+=1){
        printf(", %d", v[i]);
    }
    printf("}\n");

}

int checarMaiorNumero(int v[], int n) {
    int maiorNumero = 0; // representa o maior índice
    for(int i=1; i < n; i+=1) {
        if(v[i] > v[maiorNumero]) {
            maiorNumero = i;
        }
    }

    return maiorNumero;
}

int numeroNoVetor(int v[], int n, int numero) {

    for(int i=0; i < n; i+=1) {
        if(numero == v[i]) {
            return i;
        }
    } 
    return -1;
    
}