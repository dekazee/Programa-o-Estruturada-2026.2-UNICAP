#include <stdio.h>
#include <string.h>

#define TAM 15

void imprimirEmOrdemAlfa2(char str1[], char str2[]);
int meuStrLen(char str[]);
void inverterString(char str1[]);

int main() {
    char string1[TAM], string2[TAM];
    printf("Digite algo: ");
    fgets(string1, TAM, stdin);
    printf("Digite algo: ");
    fgets(string2, TAM, stdin);
    imprimirEmOrdemAlfa2(string1, string2);
    inverterString(string1);
    printf("String 1 invertida: %s", string1);
    
   

}

void imprimirEmOrdemAlfa2(char str1[], char str2[]) {
    if(strcmp(str1, str2) == 0) {
        printf("As duas Strings são idênticas.");
    }
    else if(strcmp(str1,str2) < 0) {
        printf("A ordem alfabética é: \n");
        printf("%s", str1);
        printf("%s", str2);
    }
    else {
        printf("A ordem alfabética é: \n");
        printf("%s", str2);
        printf("%s", str1);
    }

}

int meuStrLen(char str[]) {
    int tam = 0;
    while(str[tam] != '\0') {
        tam += 1;
    }
    return tam;
}

void inverterString(char str1[]) {
    int aux, tam = meuStrLen(str1);

    for(int i = 0; i < tam / 2; i += 1) {
        aux = str1[i];
        str1[i] = str1[tam - 1 - i];
        str1[tam - 1 - i] = aux;
    }
}