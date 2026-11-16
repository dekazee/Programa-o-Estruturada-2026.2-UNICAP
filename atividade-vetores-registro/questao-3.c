#include <stdio.h>
#include <string.h>

#define TAM 255
#define QTD_CONTAS 30


struct Cadastro {
    int numConta;
    char nome[TAM];
    char cpf[TAM];
    char telefone[TAM];
    double saldo;
};


void cadastraPessoa(struct Cadastro *c);
void lerStr(char str[], int tamMax);
int posicaoCadastro(int num, struct Cadastro c[], int qtd);
void cadastraNovaConta(struct Cadastro c[], int *qtd, int nConta);

int main() {
    struct Cadastro cadastros[40];
    char nome[TAM];
    int decisao, numero, j;
    for(int i = 0; i < QTD_CONTAS; i += 1) {
        cadastraPessoa(&cadastros[i]);
        j += 1;
    }
    printf("Decida: ");
    printf("\n(digite 0 para cancelar o processo)\n");
    printf("1(a): \n 2(b): \n 3(c): \n 4(d): \n 5(e): \n");
    scanf("%d", &decisao);
    while(decisao < 0 || decisao > 5) {
        printf("Digite a decisao entre 0 a 5: ");
        scanf("%d", &decisao);
    }
    if(decisao == 1) {
        printf("Digite o numero da conta: ");
        scanf("%d", &numero);
        if(posicaoCadastro(numero, cadastros, QTD_CONTAS) == -2) {
            printf("Conta nao encontrada\n");
        } else if(posicaoCadastro(numero, cadastros, QTD_CONTAS) == -1) {
            printf("Não existe cadastros");
        } else {
            printf("Cadastro foi encontrado na posição: %d\n", 1 + posicaoCadastro(numero, cadastros, QTD_CONTAS));
        }
    }
    else if(decisao == 2) {
        printf("Digite o num da conta: ");
        scanf("%d", &numero);
        cadastraNovaConta(cadastros, &j, numero);
    } else if (decisao == 3) {
        
    }
    printf("%d", j);

    return 0;
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

int posicaoCadastro(int num, struct Cadastro c[], int qtd) {
    for(int i = 0; i < qtd; i += 1) {
        if(num == c[i].numConta) {
            return i;
        } 
    }
    if(qtd <= 0) {
        return -1;
    }
    return -2;
}

void cadastraNovaConta(struct Cadastro c[], int *qtd, int nConta) {
    if(posicaoCadastro(nConta, c, *qtd) > -1) {
        printf("Já existe uma conta com esse numero\n");
    } else {
        char temp[10];
        lerStr(temp, 10);
        printf("\ndigite o seu nome: ");
        lerStr(c[*qtd+1].nome, TAM);
        printf("\ndigite seu cpf: ");
        lerStr(c[*qtd+1].nome, TAM);
        printf("\ndigite seu telefone: ");
        lerStr(c[*qtd+1].telefone, TAM);
        printf("\ndigite o saldo: ");
        scanf("%lf", &c[*qtd+1].saldo);
        lerStr(temp, 10);
        *qtd += 1;
    }
}