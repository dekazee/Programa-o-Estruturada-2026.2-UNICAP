#include <stdio.h>


int main() {
    FILE *arq;
    int status;
    double numeros[3];
    arq = fopen("teste.bin","rb");
    if (arq == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso\n");
    }


    status = fread(numeros, sizeof(double), 3, arq);
    if ( status == 3 ) {
        printf("Os numeros lidos foram: %lf - %lf - %lf\n", numeros[0], numeros[1], numeros[2]);
    } else {
        printf("Erro ao ler os numeros\n");
    }

    status = fclose(arq);
    if( status == 0 ) {
        printf("Arquivo fechado com sucesso\n");
    } else {
        printf("Arquivo não pode ser fechado. Código: %d\n", status);
    }
    return 0;
}