#include <stdio.h>
#include <string.h>

#define TAM 255


int lerStr(char str[], int tamMax, FILE *arq);

int main() {
    char frase[TAM];
    int status, numLinha = 1;
    FILE *arq = fopen("teste.txt", "rt");
    if(!arq) {
        printf("Erro ao abrir o arquivo!");
        return 1;
    }

    status = lerStr(frase, TAM, arq);
    while(!feof(arq) && status == 0) {
        printf("%2d: %s\n", numLinha, frase);
        numLinha += 1;
        status = lerStr(frase, TAM, arq);

    }


    if(status != 0 && numLinha == 0) {
        printf("Erro ao ler linha do arquivo!\n");
        return 2;
    }
    status = fclose(arq);
    if(status != 0) {
        printf("Erro ao fechar o arquivo\n");
    }
    return 0;
}



int lerStr(char str[], int tamMax, FILE *arq) {
    char *status = fgets(str, tamMax, arq);
    int tam = strlen(str);
    if(tam > 0 && str[tam -  1] == '\n') {
        str[tam - 1] = '\0';
    }
    return status != str;
}