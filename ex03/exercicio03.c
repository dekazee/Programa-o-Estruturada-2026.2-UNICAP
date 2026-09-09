#include <stdio.h>

#define TAM 7

void preencherOrdenacao(int v[], int n);
void inserirOrdenado(int v[], int n, int x);
void imprimirVetor(int v[], int n);
void adicionarElementoPar(int v[], int n, int num);
void preencherPrimos(int v[], int n);
void somatorio(int v1[], int v2[], int vsoma[] , int n);
int procuraBinaria(int v[], int n, int x);

int main() {
    int v1[TAM], v2[TAM], v3[TAM], vsum[TAM], continua;

    preencherOrdenacao(v1, TAM);
    imprimirVetor(v1, TAM);
    
    while( continua == 0 ) {
        printf("Você deseja fazer uma procura binária?\n");
        printf("Aperte 1 para procurar um numero");
        scanf("%d", &continua);
    }
    
    return 0;



}

void preencherOrdenacao(int v[], int n) {
    int num;
    for (int i = 0; i < n; i+=1) {
        printf("Digite um numero: ");
        scanf(" %d", &num);
        inserirOrdenado(v, i, num);
    }
}

void inserirOrdenado(int v[], int n, int x) {
    int i;
    i = n - 1;
    while(i >= 0 && v[i] > x) {
        v[i+1] = v[i];
        i -=1;
    }
    v[i+1] = x;

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

    } while( v[meio] != x && inicio < fim);
}

// {2, 3, 6, 7, 9}