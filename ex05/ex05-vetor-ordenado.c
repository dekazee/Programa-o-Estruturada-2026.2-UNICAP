#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

void preencherAleatorio(double v[], int n);
void insercaoDireta (double v[], int n);
void selecaoDireta(double v[], int n);
void bubbleSort (double v[], int n);
void imprimirVetor(double v[], int n);

int main() {
    double a[TAM];
    srand(time(NULL));
    printf("RAND_MAX é %d\n", RAND_MAX);
    preencherAleatorio(a, TAM);
    imprimirVetor(a, TAM);
    insercaoDireta(a, TAM);
    imprimirVetor(a, TAM);
    return 0;
}

void preencherAleatorio(double v[], int n) {
    for (int i = 0; i < n; i +=1) {
        v[i] = rand() / 1000000;
    }

}


void insercaoDireta (double v[], int n) {
    int i,j;
    double chave;
    for (i = 1; i <= n; i++) {
        chave = v[i];
        j = i - 1;
        while( j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j+1] = chave;
    } 
}

void selecaoDireta(double v[], int n) {
    int i, j, menor;
    double aux;
    for (i=0; i < n - 2; i++) {
        menor = i;
        for (j = i + 1; j <= n - 1; j++) {
            if(v[j] < v[menor]) {
                menor = j;
            }
        }
    }
    aux = v[i];
    v[i] = v[menor];
    v[menor] = aux;
}

void bubbleSort (double v[], int n) {
    int i, fim, pos, troca;
    double chave;
    troca = 1; fim = n - 2; pos = 0;
    while (troca == 1) {
        troca = 0;
        for ( i = 0; i <= fim; i++) {
            if(v[i] > v[i+1]) {
                chave = v[i];
                v[i] = v[i+1];
                v[i+1] = chave;
                pos = i;
                troca = 1;
            }
        }
        fim = pos - 1;
    }
    
}

void imprimirVetor(double v[], int n) {
    printf("{");
    if (n > 0) {
        printf(" %7.2f", v[0]);
        for (int i = 1; i < n; i += 1) {
            printf(", %7.2f", v[i]);
        }
    }
    printf(" }\n");
}