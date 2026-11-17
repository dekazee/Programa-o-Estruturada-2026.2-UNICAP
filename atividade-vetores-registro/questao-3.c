#include <stdio.h>
#include <string.h>

#define TAM 255
#define QTD_CONTAS 100


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
void consultarSaldo(struct Cadastro c[], int nConta);
void depositarConta(struct Cadastro c[], int nConta);
void sacarConta(struct Cadastro c[], int nConta);
void imprimirContas(struct Cadastro c[], int tam);
void imprimirUmaConta(struct Cadastro c);

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
    printf("1(a): \n 2(b): \n 3(c): \n 4(d): \n 5(e): \n 6(f) \n");
    scanf("%d", &decisao);
    while(decisao < 0 || decisao > 6) {
        printf("Digite a decisao entre 0 a 6: ");
        scanf("%d", &decisao);
    } // aqui seria melhor usar um switch case, mas agora já é tarde
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
        printf("Digite o num da conta: ");
        scanf("%d", &numero);
        consultarSaldo(cadastros, numero);
    } else if(decisao == 4) {
        printf("Digite o num da conta: ");
        scanf("%d", &numero);
        depositarConta(cadastros, numero);
    } else if(decisao == 5) {
        printf("Digite o num da conta: ");
        scanf("%d", &numero);
        sacarConta(cadastros, numero);
    } else {
        imprimirContas(cadastros, QTD_CONTAS);
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

void consultarSaldo(struct Cadastro c[], int nConta) {
    int i = posicaoCadastro(nConta, c, QTD_CONTAS);
    if(i > -1) {
        printf("Saldo é de: %lf\n", c[i].saldo);
    } else {
        printf("Numero da Conta não existe\n");
    }
}

void depositarConta(struct Cadastro c[], int nConta) {
    int i = posicaoCadastro(nConta, c, QTD_CONTAS);
    double valor;
    if(i > -1) {
        printf("Qual valor deseja depositar?\n");
        scanf("%lf", &valor);
        printf("Saldo anterior ao deposito: %lf\n", c[i].saldo);
        c[i].saldo += valor;
        printf("Saldo atual: %lf\n", c[i].saldo);
    } else {
        printf("Numero da Conta não existe\n");
    }

}

void sacarConta(struct Cadastro c[], int nConta) {
    int i = posicaoCadastro(nConta, c, QTD_CONTAS);
    double saque;
    if(i > -1) {
        printf("Qual valor deseja sacar?\n");
        scanf("%lf", &saque);
        if(c[i].saldo >= saque) {
        printf("Saldo anterior ao saque: %lf\n", c[i].saldo);
        c[i].saldo -= saque;
        printf("Saldo atual: %lf\n", c[i].saldo);
        } else {
            printf("Saldo insuficiente.\n");
        }
    } else {
        printf("Numero da Conta não existe\n");
    }

}

void imprimirContas(struct Cadastro c[], int tam) {
    for (int i = 0; i < tam; i += 1) {
        imprimirUmaConta(c[i]);
        printf("\n=========================\n");
    }
}

void imprimirUmaConta(struct Cadastro c) {
    printf("Nome: %s\n", c.nome);
    printf("CPF: %s\n", c.cpf);
    printf("Numero da Conta: %s\n", c.numConta);
    printf("Saldo: %.2lf\n", c.saldo);
    printf("Telefone: %s\n", c.telefone);
}