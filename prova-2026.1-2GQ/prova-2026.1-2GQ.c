#include <stdio.h>
#include <string.h>

#define TAM_CONTAS 50
#define TAM_OPERACOES 10000

struct Conta {
    int id;
    char cliente[40];
    double saldo;
    double limite;
};

struct Operacao {
    int id;
    int idConta;
    char tipo;
    double valor;
};

/* FUNÇÃO AUXILIAR: BUSCA PELO ID */
int buscaId(struct Conta v[], int tam, int x) {
    int i;

    for (i = 0; i < tam; i++) {
        if (v[i].id == x) {
            return i;
        }
    }

    return -1;
}

/* FUNÇÃO AUXILIAR: IDENTIFICA CRÉDITO OU DÉBITO */
char indicador(double valor) {
    if (valor >= 0) {
        return 'C';
    }

    return 'D';
}

/* QUESTÃO 1 - CADASTRAR CONTA */
void cadastraConta(struct Conta v[], int *tam) {
    int id;
    char nome[40];
    double limite;

    if (*tam >= TAM_CONTAS) {
        printf("Vetor de contas cheio!\n");
        return;
    }

    printf("Digite o ID da conta: ");
    scanf("%d", &id);

    if (buscaId(v, *tam, id) != -1) {
        printf("Esse ID ja esta cadastrado!\n");
        return;
    }

    printf("Digite o nome do cliente: ");
    scanf(" %39[^\n]", nome);

    printf("Digite o limite da conta: ");
    scanf("%lf", &limite);

    if (limite < 0) {
        printf("O limite nao pode ser negativo!\n");
        return;
    }

    v[*tam].id = id;
    strcpy(v[*tam].cliente, nome);
    v[*tam].saldo = 0;
    v[*tam].limite = limite;

    (*tam)++;

    printf("Conta cadastrada com sucesso!\n");
}

/* QUESTÃO 2 - BUSCA BINÁRIA PELO NOME */
int buscaBinariaNome(struct Conta v[], int tam, char x[]) {
    int inicio = 0;
    int fim = tam - 1;
    int meio;
    int resultado;

    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;

        resultado = strcmp(v[meio].cliente, x);

        if (resultado == 0) {
            return meio;
        }
        else if (resultado > 0) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }

    return -1;
}

/* QUESTÃO 3 - FILTRAR DEVEDORES */
void filtraDevedores(struct Conta vContas[], int tamConta,
                     struct Conta vDevedores[], int *tamDevedores) {
    int i;

    *tamDevedores = 0;

    for (i = 0; i < tamConta; i++) {
        if (vContas[i].saldo < 0) {
            vDevedores[*tamDevedores] = vContas[i];

            (*tamDevedores)++;
        }
    }
}

/* QUESTÃO 4 - REALIZAR SAQUE */
int realizarSaque(struct Conta vContas[], int tamConta,
                  struct Operacao vOp[], int *tamOp) {
    int idConta;
    int posicao;
    double valor;

    if (*tamOp >= TAM_OPERACOES) {
        printf("Vetor de operacoes cheio!\n");
        return 0;
    }

    printf("Digite o ID da conta: ");
    scanf("%d", &idConta);

    posicao = buscaId(vContas, tamConta, idConta);

    if (posicao == -1) {
        printf("Conta nao encontrada!\n");
        return 0;
    }

    printf("Digite o valor do saque: ");
    scanf("%lf", &valor);

    if (valor <= 0) {
        printf("Valor de saque invalido!\n");
        return 0;
    }

    if (vContas[posicao].saldo + vContas[posicao].limite < valor) {
        printf("Saldo insuficiente!\n");
        return 0;
    }

    /* Atualiza o saldo da conta */
    vContas[posicao].saldo -= valor;

    /* Registra a operacao */
    vOp[*tamOp].id = *tamOp + 1;
    vOp[*tamOp].idConta = idConta;
    vOp[*tamOp].tipo = 'S';
    vOp[*tamOp].valor = -valor;

    (*tamOp)++;

    printf("Saque realizado com sucesso!\n");

    return 1;
}

/* FUNÇÃO AUXILIAR PARA DESCREVER A OPERAÇÃO */
const char *descricaoOperacao(char tipo) {
    switch (tipo) {
        case 'D':
            return "Deposito";

        case 'S':
            return "Saque";

        case 'T':
            return "Transferencia";

        default:
            return "Desconhecida";
    }
}

/* QUESTÃO 5 - EXTRATO BANCÁRIO */
void extrato(struct Conta vContas[], int tamConta,
             struct Operacao vOp[], int *tamOp) {
    int idConta;
    int posicao;
    int ultimas[5];
    int qtd = 0;
    int i, j;
    int indiceAntigo;

    double saldoAnterior = 0;
    double valorAbsoluto;

    printf("Digite o ID da conta: ");
    scanf("%d", &idConta);

    posicao = buscaId(vContas, tamConta, idConta);

    if (posicao == -1) {
        printf("Conta nao encontrada!\n");
        return;
    }

    /* Procura as cinco ultimas operacoes da conta */
    for (i = *tamOp - 1; i >= 0 && qtd < 5; i--) {
        if (vOp[i].idConta == idConta) {
            ultimas[qtd] = i;
            qtd++;
        }
    }

    /* Calcula o saldo anterior a essas operacoes */
    if (qtd > 0) {
        indiceAntigo = ultimas[qtd - 1];

        for (i = 0; i < indiceAntigo; i++) {
            if (vOp[i].idConta == idConta) {
                saldoAnterior += vOp[i].valor;
            }
        }
    }

    /* Imprime o cabecalho */
    printf("\n========================================\n");
    printf("             CONTA N.%03d\n", vContas[posicao].id);
    printf("========================================\n");

    printf("CLIENTE: %s\n", vContas[posicao].cliente);

    printf("-----------------------------------------------\n");
    printf("ID   | OPERACAO       | VALOR       | SALDO\n");
    printf("-----------------------------------------------\n");

    /* Imprime o saldo anterior */
    printf("     | Saldo Anterior |             | %.2f%c\n",
           saldoAnterior, indicador(saldoAnterior));

    /* Imprime as operacoes em ordem cronologica */
    for (j = qtd - 1; j >= 0; j--) {
        i = ultimas[j];

        saldoAnterior += vOp[i].valor;

        valorAbsoluto = vOp[i].valor;

        if (valorAbsoluto < 0) {
            valorAbsoluto = -valorAbsoluto;
        }

        printf("%04d | %-14s | %8.2f%c | %8.2f%c\n",
               vOp[i].id,
               descricaoOperacao(vOp[i].tipo),
               valorAbsoluto,
               indicador(vOp[i].valor),
               saldoAnterior,
               indicador(saldoAnterior));
    }

    printf("-----------------------------------------------\n");

    /* Imprime o saldo atual registrado na conta */
    printf("Saldo Atual: %.2f%c\n",
           vContas[posicao].saldo,
           indicador(vContas[posicao].saldo));

    printf("===============================================\n");
}