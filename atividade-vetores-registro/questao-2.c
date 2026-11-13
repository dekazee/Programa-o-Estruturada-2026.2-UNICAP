#include <stdio.h>

#define TAM_STRING 255
#define QTD_PRODUTO 40

struct Produto {
    int codigo;
    char descricao[TAM_STRING];
    double valorUnitario;
    int qtd_estoque;
};

void cadastrarProduto(struct Produto *p);
void mostrarProdutos(struct Produto p[], int qtd);
void mudarValorPorCod(struct Produto p[], int qtd, int cod);
int encontrarValorPorCod(struct Produto p[], int qtd, int cod);
int encontrarQtdPorCod(struct Produto p[], int qtd, int cod);
void venderProdutoPorCod(struct Produto p[], int qtd, int cod, int qtd_comprada);
void mudarQtdPorCod(struct Produto p[], int qtd, int cod);
void mostrarCodDesc(struct Produto p[], int qtd);
void mostrarCodDescEstoqueZero(struct Produto p[], int qtd);

int main() {
    struct Produto produtos[QTD_PRODUTO];
    int codigo, qtd_desejada;
    char temp[10];
    for(int i = 0; i < QTD_PRODUTO; i += 1) {
        printf("\nProduto %d\n", i+1);
        cadastrarProduto(&produtos[i]);
    }
    mostrarProdutos(produtos, QTD_PRODUTO);
    printf("Digite um codigo: ");
    scanf("%d", &codigo);
    fgets(temp, 10, stdin);
    mudarValorPorCod(produtos, QTD_PRODUTO, codigo);
    mostrarProdutos(produtos, QTD_PRODUTO);
    printf("Digite outro codigo: ");
    scanf("%d", &codigo);
    if(encontrarValorPorCod(produtos, QTD_PRODUTO, codigo)) {
        printf("Produto: %s\n", produtos[encontrarValorPorCod(produtos, QTD_PRODUTO, codigo)].descricao);
        printf("Valor Unitario: %.2lf\n", produtos[encontrarValorPorCod(produtos, QTD_PRODUTO, codigo)].valorUnitario);
    } else {
        printf("Codigo nao encontrado\n");
    }

    printf("Digite outro codigo: ");
    scanf("%d", &codigo);

    if(encontrarQtdPorCod(produtos, QTD_PRODUTO, codigo)) {
        printf("Produto: %s\n", produtos[encontrarValorPorCod(produtos, QTD_PRODUTO, codigo)].descricao);
        printf("Quantidade no estoque: %d\n", produtos[encontrarValorPorCod(produtos, QTD_PRODUTO, codigo)].qtd_estoque);
    } else {
        printf("Codigo nao encontrado\n");
    }

    printf("Digite outro codigo: \n");
    scanf("%d", &codigo);
    if(!encontrarQtdPorCod(produtos, QTD_PRODUTO, codigo)) {
        printf("Codigo não encontrado.\n");
    } else{
        printf("Qual a quantidade deseja comprar desse produto?\n");
        scanf("%d", &qtd_desejada);
        venderProdutoPorCod(produtos, QTD_PRODUTO, codigo, qtd_desejada);
        mostrarProdutos(produtos, QTD_PRODUTO);
    }
    

    printf("Digite outro codigo: \n");
    scanf("%d", &codigo);

    mudarQtdPorCod(produtos, QTD_PRODUTO, codigo);
    mostrarProdutos(produtos, QTD_PRODUTO);
    printf("\n ==== Produtos somente com Código e Descrição ==== \n");
    mostrarCodDesc(produtos, QTD_PRODUTO);
    printf("\n ==== Produtos somente com Código e Descrição(Estoque ZERADO) ==== \n");
    mostrarCodDescEstoqueZero(produtos, QTD_PRODUTO);

    return 0;
}

void cadastrarProduto(struct Produto *p) {
    char temp[10];
    
    printf("Digite o codigo do produto: ");
    scanf("%d", &p->codigo);
    fgets(temp, 10, stdin);
    printf("Digite a descricao do produto: ");
    fgets(p->descricao, TAM_STRING, stdin);
    printf("Digite o valor unitario do produto: ");
    scanf("%lf", &p->valorUnitario);
    printf("Digite a quantidade desse produto: ");
    scanf("%d", &p->qtd_estoque);
    fgets(temp, 10, stdin);

}

void mostrarProdutos(struct Produto p[], int qtd) {
    for(int i = 0; i < qtd; i += 1) {
        printf("Produto %d\n", i+1);
        printf("Codigo: %d\n", p[i].codigo);
        printf("Descricao: %s\n", p[i].descricao);
        printf("Valor Unitario: %.2lf", p[i].valorUnitario);
        printf("\nQuantidade do Produto: %d", p[i].qtd_estoque);
        printf("\n===================\n");
    }
    printf("Fim dos produtos\n");
}

void mudarValorPorCod(struct Produto p[], int qtd, int cod) {
    int i;
    for(i = 0; i < qtd; i += 1) {
        if(p[i].codigo == cod) {
            printf("Produto: %s\n", p[i].descricao);
            printf("Digite o novo valor unitario: ");
            scanf("%lf", &p[i].valorUnitario);
            break;
        }
    }
    if(p[i].codigo != cod) {
        printf("Codigo nao encontrado.\n");
    }
}

int encontrarValorPorCod(struct Produto p[], int qtd, int cod) {
    int i;
    for(i = 0; i < qtd; i += 1) {
        if(p[i].codigo == cod) {
            return i;
        }
    }
    return 0;
}
// O encontrar Qtd é a mesma coisa do encontrar Valor
int encontrarQtdPorCod(struct Produto p[], int qtd, int cod) {
    int i;
    for(i = 0; i < qtd; i += 1) {
        if(p[i].codigo == cod) {
            return i;
        }
    }
    return 0;
}

void venderProdutoPorCod(struct Produto p[], int qtd, int cod, int qtd_comprada) {
    int indice = encontrarQtdPorCod(p, qtd, cod), escolha;
    if(indice != 0) {
        if(p[indice].qtd_estoque == 0) {
            printf("Não temos estoque desse produto.");
            return;
        } else if(p[indice].qtd_estoque < qtd_comprada) {
            printf("O estoque é: %d\n", p[indice].qtd_estoque);
            printf("Deseja comprar todo o estoque?\n");
            printf("Digite 1 para sim e 0 para nao\n");
            scanf("%d", &escolha);
            while(escolha < 0 || escolha > 1) {
                printf("Digite apenas 0 ou 1\n");
                scanf("%d", &escolha);
            }
            if(escolha == 1) {
                p[indice].qtd_estoque = 0;
                printf("Compra concluída\n");
            } else {
                printf ("Compra cancelada\n");
            }
            

        } else {
            p[indice].qtd_estoque = p[indice].qtd_estoque - qtd_comprada;
            printf("Compra concluída\n");
        }
    } else {
        printf("Produto nao encontrado\n");
    }
}

void mudarQtdPorCod(struct Produto p[], int qtd, int cod) {
    int indice = encontrarQtdPorCod(p, qtd, cod), qtd_nova;
    if(indice) {
        printf("Digite a nova quantidade desse produto: ");
        scanf("%d", &qtd_nova);
        while(qtd_nova < 0) {
            printf("Digite um valor maior ou igual a zero: ");
            scanf("%d", &qtd_nova);
        }
        p[indice].qtd_estoque = qtd_nova;
        printf("Mudança concluída!\n");
        printf("Quantidade nova: %d\n", p[indice].qtd_estoque);
    } else {
        printf("Produto nao encontrado\n");
    }
}


void mostrarCodDesc(struct Produto p[], int qtd) {
    for(int i = 0; i < qtd; i += 1) {
        printf("Produto %d\n", i+1);
        printf("Codigo: %d\n", p[i].codigo);
        printf("Descricao: %s\n", p[i].descricao);
        printf("\n===================\n");
    }
    printf("Fim dos produtos\n");
}

void mostrarCodDescEstoqueZero(struct Produto p[], int qtd) {
    for(int i = 0; i < qtd; i += 1) {
        if(p[i].qtd_estoque == 0) {
        printf("Produto %d\n", i+1);
        printf("Codigo: %d\n", p[i].codigo);
        printf("Descricao: %s\n", p[i].descricao);
        printf("\n===================\n");
        }
    }
    printf("Fim dos produtos\n");
}