#include <stdio.h>
#include <string.h>

#define TAM_NOME 50

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


int main() {
    struct Pessoa pessoa;
    preencherDigitacaoPessoa(&pessoa);
    imprimirPessoa(pessoa);
    double imc = calcularImc(pessoa);
    printf("O IMC de %s é %.2f", pessoa.nome, imc);

    return 0;
    
}

void preencherDigitacaoPessoa(struct Pessoa *p) {
    printf("Digite o seu nome: ");
    lerStr(p->nome, TAM_NOME);
    printf("Digite sua idade: ");
    scanf("%d", &p->idade);
    printf("Digite o seu peso: ");
    scanf("%lf", &p->peso);
    printf("Digite a sua altura: ");
    scanf("%lf", &p->altura);
    
}
/*
void preencherDigitacaoPessoa(struct Pessoa *p) {
    printf("Digite o seu nome: ");
    lerStr((*p).nome, TAM_NOME);
    printf("Digite sua idade: ");
    scanf("%d", &(*p).idade);
    printf("Digite o seu peso: ");
    scanf("%lf", &(*p).peso);
    printf("Digite a sua altura: ");
    scanf("%lf", &(*p).altura);
    
}*/

void imprimirPessoa(struct Pessoa p) {

    printf("%s tem %d anos, %.1fkg e %.1fm\n", p.nome, p.idade, p.peso, p.altura);

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