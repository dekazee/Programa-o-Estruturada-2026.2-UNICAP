#include <stdio.h>

#define QTD_LINHAS 4
#define QTD_COLUNA 3

void preencherMatriz(int m[][QTD_COLUNA], int lins, int cols);
void imprimirMatriz(int m[][QTD_COLUNA], int lins, int cols);
void imprimirMaiorValorMatriz(int m[][QTD_COLUNA], int lins, int cols);

int main() {
    int matriz[QTD_LINHAS][QTD_COLUNA];

    preencherMatriz(matriz, QTD_LINHAS, QTD_COLUNA);

    printf("\nImpressão Matriz\n");

    imprimirMatriz(matriz, QTD_LINHAS, QTD_COLUNA);
    imprimirMaiorValorMatriz(matriz, QTD_LINHAS, QTD_COLUNA);
    
    return 0;
}

void preencherMatriz(int m[][QTD_COLUNA], int lins, int cols) {
    for(int i = 0; i < lins; i += 1) {
        for(int j = 0; j < cols; j += 1) {
            printf("Digite o valor de m[%d][%d]\n", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void imprimirMatriz(int m[][QTD_COLUNA], int lins, int cols) {
    for(int i = 0; i < lins; i += 1) {
        for(int j = 0; j < cols; j += 1) {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }

}

void imprimirMaiorValorMatriz(int m[][QTD_COLUNA], int lins, int cols) {
    int iMaior = 0, jMaior = 0;
    for(int i = 0; i < lins; i += 1) {
        for(int j = 0; j < cols; j += 1) {
            if(m[i][j] > m[iMaior][jMaior]) {
                iMaior = i;
                jMaior = j;
            }
        }
    }
    printf("O maior valor é %d e está na posição (%d, %d)", m[iMaior][jMaior], iMaior+1, jMaior+1);
}
