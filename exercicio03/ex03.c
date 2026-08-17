#include <stdio.h>

#define QTD_MAX_VALORES 5

int main() {
    int num, soma = 0, qtd = 0, qtdMedia = 0;
    int numeros[QTD_MAX_VALORES];
    double media;
    printf("Digite um valor: ");
    scanf(" %d", &num);

    while (num > 0)
    {
       numeros[qtd] = num; 
       soma += num;
       qtd += 1;
       if(qtd >= QTD_MAX_VALORES) {
        printf("Quantidade máxima de valores atingida");
        break;
       }
       printf("Digite u, valor inteiro positivo (<= 0 finaliza o looping): ");
       scanf(" %d", &num);
    }
    if(qtd > 0) {
        media = (double) soma / (double) qtd;
        printf("Foram digitados %d numeros e a media foi %lf.\n", qtd, media);
        printf("Todos os numeros digitados:\n");
        for ( int i = 0; i < qtd; i += 1) {
            printf("numeros[%d], %d\n", i+1, numeros[i]);
            if( numeros[i] > media) {
                qtdMedia += 1;
            } 
        }
        printf("Quantidade de numeros acima da media %d\n", qtdMedia);
        for ( int i = 0; i < qtd; i += 1) {
            if( numeros[i] > media) {
                printf("numeros[%d], %d\n", i+1, numeros[i]);
            }
        }

    } else {
        printf("Nenhum número válido digitidado!\n");
    }
    return 0;
}