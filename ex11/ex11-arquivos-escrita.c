#include <stdio.h>


int main() {
    FILE *arq;
    int status;
    double numeros[] = {3.14, 2.71, 1.618};
    arq = fopen("teste.bin","ab");
    if (arq == NULL) {
        printf("Não foi possível criar o arquivo.\n");
        return 1;
    } else {
        printf("Arquivo criado\n");
    }

    status = fwrite(numeros, sizeof(double), 3, arq);

    if(status == 3) {
        printf("Numeros gravados com sucesso!\n");
    } else {
        printf("Erro ao gravar os numeros\n");
        printf("Somente %d gravados\n", status);
    }

    status = fclose(arq);
    if( status == 0 ) {
        printf("Arquivo fechado com sucesso\n");
    } else {
        printf("Arquivo não pode ser fechado. Código: %d\n", status);
    }
    return 0;
}