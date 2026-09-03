#include <stdio.h>

#define TAM 15

void imprimirVetor(int v[], int n);
void adicionarElementoPar(int v[], int n, int num);
void preencherPrimos(int v[], int n);
void somatorio(int v1[], int v2[], int vsoma[] , int n);
int procuraBinaria(int v[], int n, int x);

int main() {
    int v1[TAM], v2[TAM], v3[TAM], vsum[TAM];

    adicionarElementoPar(v3, TAM, 102);
    imprimirVetor(v3, TAM);
    preencherPrimos(v2, TAM);
    imprimirVetor(v2, TAM);
    somatorio(v3, v2, vsum, TAM);
    imprimirVetor(vsum, TAM);
    return 0;



}


void imprimirVetor(int v[], int n) {
    printf("{");
    if (n > 0) {
        printf(" %d", v[0]);
        for (int i = 1; i < n; i += 1) {
            printf(", %d", v[i]);
        }
    }
    printf(" }\n");
}

void adicionarElementoPar(int v[], int n, int num) {
    for(int i = 0; i < TAM; i+=1) {
        v[i] = num;
        num += 2;
    }
}

int ePrimo(int v[], int n, int x) {
    for (int i = 0; i < n; i +=1) {
        if ( x % v[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void preencherPrimos(int v[], int n) {
    int tam = 1;
    int num = 3;
    v[0] = 2;
    while(tam < n) {
        if( ePrimo(v,tam, num)) {
            v[tam] = num;
            tam += 1;
        } 
        num += 1;
    }
    
}

void somatorio(int v1[], int v2[], int vsoma[] , int n) {
    int ib = n -1;
    for (int i = 0; i < n; i += 1) {
        //vsoma[i] = v1[i] + v2[n - 1 - 0];
        vsoma[i] = v1[i] + v2[ib];
        ib -= 1;      
}
}
int procuraBinaria(int v[], int n, int x) {
    int inicio, meio, fim = n;
    do {
        meio = fim / 2;
        if ( v[meio] > x ) {
            fim = meio;
        }
        else if (v[meio] < x) {
            inicio = meio;
        } else {
            return 1;
        }

    } while( v[meio] != x && inicio < fim)
}

// {2, 3, 6, 7, 9}