#include <stdio.h>
#include <string.h>

#define TAM 255


void lerStr(char str[], int tamMax);

int main() {
    char frase[TAM];
    int status;
    FILE *arq = fopen("teste.txt", "at");
    if(!arq) {
        printf("Erro ao abrir o arquivo!");
        return 1;
    }
    printf("Digite uma frase para ser guardada!\n");
    lerStr(frase, TAM);
    // salva a frase  digitada dentro de ASPAS
    status = fprintf(arq,"\"%s\"\n", frase);
    if(status < 0) {
        printf("Erro ao gravar a frase no arquivo\n");
    } else {
        printf("Frase salva com sucesso!\n");
    }
    status = fclose(arq);
    if(status != 0) {
        printf("Erro ao fechar o arquivo!\n");
        return 2;
    }

    
    return 0;
}



void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam -  1] == '\n') {
        str[tam - 1] = '\0';
    }
}