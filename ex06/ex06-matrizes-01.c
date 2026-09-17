#include <stdio.h>

#define QTD_LINHAS 4
#define QTD_COLUNA 4

void preencherMatriz(int m[][QTD_COLUNA], int lins, int cols);
void imprimirMatriz(int m[][QTD_COLUNA], int lins, int cols);
void maiorValorMatriz(int m[][QTD_COLUNA], int lins, int cols, int *posI, int *posJ);
int buscarMatriz(int m[][QTD_COLUNA], int lins, int cols, int x, int *posI, int *posJ);
void somatorioLinhas(int m[][QTD_COLUNA], int lins, int cols, int soma[]);
void somatorioColunas(int m[][QTD_COLUNA], int lins, int cols, int soma[]);
void zerarAbaixoDiagonalPrincipal(int m[][QTD_COLUNA], int lins, int cols);

int main() {
    int matriz[QTD_LINHAS][QTD_COLUNA];
    int soma[QTD_LINHAS];
    int somac[QTD_COLUNA];
    int iMaior, jMaior;

    preencherMatriz(matriz, QTD_LINHAS, QTD_COLUNA);

    printf("\nImpressão Matriz\n");
    // A matriz já é um ponteiro
    imprimirMatriz(matriz, QTD_LINHAS, QTD_COLUNA);
    maiorValorMatriz(matriz, QTD_LINHAS, QTD_COLUNA, &iMaior, &jMaior);
    printf("O maior valor é %d e está na posição (%d, %d)\n", matriz[iMaior][jMaior], iMaior+1, jMaior+1);
    if(buscarMatriz(matriz, QTD_LINHAS, QTD_COLUNA, 12, &iMaior, &jMaior)) {
        printf("o numero %d está na matriz\n", matriz[iMaior][jMaior]);
    } else {
        printf("o numero não está na matriz\n");
    }
    somatorioLinhas(matriz, QTD_LINHAS, QTD_COLUNA, soma);
    for (int i = 0; i < QTD_LINHAS; i += 1) {
        printf("Soma da %d linha: %d\n", i+1 , soma[i]);
    }
    somatorioColunas(matriz, QTD_LINHAS, QTD_COLUNA, somac);
    for (int i = 0; i < QTD_COLUNA; i += 1) {
        printf("Soma da %d coluna: %d\n", i+1 , somac[i]);
    }
    imprimirMatriz(matriz, QTD_LINHAS, QTD_COLUNA);
    zerarAbaixoDiagonalPrincipal(matriz, QTD_LINHAS, QTD_COLUNA);
    imprimirMatriz(matriz, QTD_LINHAS, QTD_COLUNA);
    

    

    
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

void maiorValorMatriz(int m[][QTD_COLUNA], int lins, int cols, int *posI, int *posJ) {
    int iMaior = 0, jMaior = 0;
    for(int i = 0; i < lins; i += 1) {
        for(int j = 0; j < cols; j += 1) {
            if(m[i][j] > m[iMaior][jMaior]) {
                iMaior = i;
                jMaior = j;
            }
        }
    }
    *posI = iMaior;
    *posJ = jMaior;
}

int buscarMatriz(int m[][QTD_COLUNA], int lins, int cols, int x, int *posI, int *posJ) {
    for ( int i = 0; i < lins; i += 1) {
        for(int j = 0; j < cols; j += 1) {
            if( m[i][j] == x) {
                *posI = i;
                *posJ = j;
                return 1;
            }
        }
    }
    return 0;
}

void somatorioLinhas(int m[][QTD_COLUNA], int lins, int cols, int soma[]) {
    for( int i = 0; i < lins; i += 1) {
        soma[i] = 0;
        for ( int j = 0; j < cols; j += 1) {
            soma[i] += m[i][j];
        }
    }
}

void somatorioColunas(int m[][QTD_COLUNA], int lins, int cols, int soma[]) {
    for( int j = 0; j < cols; j += 1) {
        soma[j] = 0;
        for ( int i = 0; i < lins; i += 1) {
            soma[j] += m[i][j];
        }
    }
}

void zerarAbaixoDiagonalPrincipal(int m[][QTD_COLUNA], int lins, int cols) {
    if (lins == cols) {
        for (int i = 1; i < lins; i += 1) {
            for (int j = 0; j < i; j += 1) {
                m[i][j] = 0;
            }
        }
    } else {
        printf("Essa matriz não tem diagonal principal");
    }

}
/*
void zerarAcimaDiagonalPrincipal(int m[][QTD_COLUNA], int lins, int cols) {
    if ( lins != cols) {
        printf("Essa matriz não tem diagonal principal");
        return;
    }
    for (int i = 0; i < lins; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            if ( j > i ) {
                m[i][j] = 0;
            }
        }
    }

}
    */
void zerarAcimaDiagonalPrincipal(int m[][QTD_COLUNA], int lins, int cols) {
    if ( lins != cols) {
        printf("Essa matriz não tem diagonal principal");
        return;
    }
    for (int i = 0; i < lins - 1; i += 1) {
        for (int j = 1; j < cols - 1; j += 1) {
            m[i][j] = 0;
        }
    }

    imprimirMatriz(m, lins, cols);

}

/*


void zerarAbaixoDiagonalPrincipal(int m[][QTD_COLUNA], int lins, int cols) {
    if (lins == cols) {
        for (int i = 0; i < lins; i += 1) {
            for (int j = 0; j < cols; j += 1) {
                if ( i > j ) {
                    m[i][j] = 0;
                }
            }
        }
    } else {
        printf("Essa matriz não tem diagonal principal");
    }

}
    */