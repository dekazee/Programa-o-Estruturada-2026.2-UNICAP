#include <stdio.h>
#include <string.h>

#define TAM_NOME 50

struct Pessoa {
    char nome[TAM_NOME];
    int idade;
    char endereco[TAM_NOME];
};


void lerStr(char nome[], int tamMax);
void preencherStruct(struct Pessoa *p);
void imprimirStruct(struct Pessoa p);

int main() {
    struct Pessoa pessoa1;
    preencherStruct(&pessoa1);
    imprimirStruct(pessoa1);

    return 0;

}

void preencherStruct(struct Pessoa *p) {
    printf("Digite seu nome: ");
    lerStr(p->nome, TAM_NOME);
    printf("Digite sua idade: ");
    scanf("%d", &p->idade);
    while(p->idade >= 130 || p->idade < 0) {
        printf("Digite a idade correta: ");
        scanf("%d", &p->idade);
    }
    while (getchar() != '\n'); // Serve para consumir o \n
    printf("Digite seu endereco: ");
    lerStr(p->endereco, TAM_NOME);
}

void imprimirStruct(struct Pessoa p) {
    printf("Seu nome é: %s\n", p.nome);
    printf("Sua idade é: %d\n", p.idade);
    printf("Seu endereco é: %s\n", p.endereco);

}




void lerStr(char nome[], int tamMax) {
    fgets(nome, tamMax, stdin);
    int tam = strlen(nome);
    if(tam > 0 && nome[tam-1] == '\n') {
        nome[tam-1] = '\0';
    }
}