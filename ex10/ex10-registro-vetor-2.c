#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define QTD_PESSOAS 5

struct  Pessoa {
    char nome[TAM_NOME];
    int idade;
    double peso;
    double altura;
};

void lerStr(char str[], int tamMax);
double calcularImc(struct Pessoa p);
void imprimirPessoa(struct Pessoa p);
void preencherDigitacaoPessoa(struct Pessoa *p);
void preencherDigitacaoPessoas(struct Pessoa v[], int n);
void imprimirPessoas(struct Pessoa v[], int n);
int posicaoPessoaMaisVelha(struct Pessoa v[], int n);
int buscaSequencialPorIdade(struct Pessoa v[], int n, int age);
int buscaSequencialPorNome(struct Pessoa v[], int n, char nome[]);
void bubbleSortPorIdade(struct Pessoa v[], int n);



int main() {
    char nome[TAM_NOME], temp[TAM_NOME];
    int posMaisVelha, x, busca, buscarNome;
    struct Pessoa pessoas[QTD_PESSOAS];
    printf("Digitação do vetor de pessoas:\n");
    preencherDigitacaoPessoas(&pessoas, QTD_PESSOAS);
    printf("\nImpressão do vetor de pessoas\n");
    imprimirPessoas(pessoas, QTD_PESSOAS);
    printf("\n");
    posMaisVelha = posicaoPessoaMaisVelha(pessoas, QTD_PESSOAS);
    printf("A pessoa mais velha é: %s\n", pessoas[posMaisVelha].nome);
    printf("Digite uma idade para buscar no vetor: ");
    scanf("%d", &x);
    busca = buscaSequencialPorIdade(pessoas, QTD_PESSOAS, x);
    if(busca == -1) {
        printf("Essa idade não está no vetor\n");
    } else {
        printf("Essa idade está no vetor e está na posição: %d\n", busca);
    }
    lerStr(temp, TAM_NOME);
    printf("Digite um nome: ");
    lerStr(nome, TAM_NOME);
    buscarNome = buscaSequencialPorNome(pessoas, QTD_PESSOAS, nome);
    if(buscarNome == -1) {
        printf("o nome não está no vetor\n");
    } else {
        printf("o nome está no vetor e a posição é %d\n", buscarNome);
    }
    printf("ORDENAÇÃO POR IDADE:\n");
    bubbleSortPorIdade(pessoas, QTD_PESSOAS);
    imprimirPessoas(pessoas, QTD_PESSOAS);
    return 0;
    
}

void preencherDigitacaoPessoas(struct Pessoa v[], int n) {
    for(int i = 0; i < n; i += 1) {
        printf("Dados da Pessoa[%d]: \n", i);
        preencherDigitacaoPessoa(&v[i]);
    }
}

void preencherDigitacaoPessoa(struct Pessoa *p) {
    char temp[TAM_NOME];
    printf("Digite o seu nome: ");
    lerStr(p->nome, TAM_NOME);
    printf("Digite sua idade: ");
    scanf("%d", &p->idade);
    printf("Digite o seu peso: ");
    scanf("%lf", &p->peso);
    printf("Digite a sua altura: ");
    scanf("%lf", &p->altura);
    lerStr(temp, TAM_NOME); // Limpar o ENTER que sobrou do scanf anterior
}

void imprimirPessoas(struct Pessoa v[], int n) {
    for(int i = 0; i < n; i += 1) {
        printf("\nPessoa [%d]: \n", i);
        imprimirPessoa(v[i]);
    }
}

void imprimirPessoa(struct Pessoa p) {
    double imc = calcularImc(p);

    printf("%s tem %d anos, %.1fkg, %.1fm\n e imc = %.2f", p.nome, p.idade, p.peso, p.altura, imc);

}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam -  1] == '\n') {
        str[tam - 1] = '\0';
    }
}

double calcularImc(struct Pessoa p) {
    double imc = p.peso / (p.altura * p.altura);
    return imc;
}

int posicaoPessoaMaisVelha(struct Pessoa v[], int n) {
    int pos = 0;
    for(int i = 1; i < n; i += 1) {
        if(v[i].idade > v[pos].idade) {
            pos = i;
        }
    }
    return pos;
}

int buscaSequencialPorIdade(struct Pessoa v[], int n, int age) {
    for(int i = 0; i < n; i += 1) {
        if(v[i].idade == age) {
            return i;
        }
    }
    return -1;
}

int buscaSequencialPorNome(struct Pessoa v[], int n, char nome[]) {
    for(int i = 0; i < n; i += 1) {
        if(strcmp(v[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void bubbleSortPorIdade(struct Pessoa v[], int n) {
    int i, fim, pos, troca;
    struct Pessoa chave;
    troca = 1; fim = n - 2; pos = 0;
    while (troca == 1) {
        troca = 0;
        for ( i = 0; i <= fim; i++) {
            if(v[i].idade > v[i+1].idade) {
                chave = v[i];
                v[i] = v[i+1];
                v[i+1] = chave;
                pos = i;
                troca = 1;
            }
        }
        fim = pos - 1;
    }
    
}