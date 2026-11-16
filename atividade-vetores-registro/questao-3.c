#include <stdio.h>

#define TAM 255
#define QTD_CONTAS 30

struct Cadastro {
    int numConta;
    char nome[TAM];
    char cpf[TAM];
    char telefone[TAM];
    double saldo;
};

void lerStr(char str[], int tamMax);

int main() {
    struct Cadastro cadastros[QTD_CONTAS];
    char decisao[4];
    for(int i = 0; i < QTD_CONTAS; i += 1) {
        cadastraPessoa(&cadastros[i]);
    }
    printf("Decida: ");
    printf("\n(digite n para cancelar o processo)\n");
    printf("a: \n b: \n c: \n d: \n e: \n");
    scanf("%s", &decisao);
    while

}

void cadastraPessoa(struct Cadastro *c) {
    char temp[10];
    printf("Digite seu nome: ");
    lerStr(c->nome, TAM);
    printf("Digite seu cpf: ");
    lerStr(c->cpf, TAM);
    printf("Digite o numero da conta: ");
    scanf("%d", &c->numConta);
    lerStr(temp, 10);
    printf("Digite seu telefone: ");
    lerStr(c->telefone, TAM);
    printf("Digite seu saldo atual: ");
    scanf("%lf", &c->saldo);
    lerStr(temp, 10);
    
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam -  1] == '\n') {
        str[tam - 1] = '\0';
    }
}