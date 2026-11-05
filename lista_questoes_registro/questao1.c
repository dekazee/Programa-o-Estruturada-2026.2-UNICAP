#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define QTD_ESTADO 26

struct Estado {
    char nomeEstado[50];
    int numeroVeiculo;
    int numeroAcidentes;
};
struct MaiorMenor {
    int maior;
    int menor;
};

void preencherEstado(struct Estado *e);
void lerStr(char nome[], int tam);
void quantidadeAcidentes(struct MaiorMenor *m, struct Estado *e);
int buscaMaiorAcidentes(struct Estado *e[]);
int buscaMenorAcidentes(struct Estado *e[]);

int main() {
    struct Estado estados[QTD_ESTADO];
    struct MaiorMenor indice;
    for(int i = 0; i < QTD_ESTADO; i += 1) {
        preencherEstado(&estados[i]);
    }
    printf("\n");
    for(int i = 0; i < QTD_ESTADO; i += 1) {
        printf("Estado %d\n", i + 1);
        printf("%s\n", estados[i].nomeEstado);
        printf("Numero de Veiculos circulantes: %d\n", estados[i].numeroVeiculo);
        printf("Numero de Acidentes registrados: %d\n", estados[i].numeroAcidentes);
    }
    quantidadeAcidentes(&indice, &estados);
    printf("O estado com mais acidentes é %s", estados[indice.maior].nomeEstado);
    printf("O estado com menos acidentes é %s", estados[indice.maior].nomeEstado);
}

void preencherEstado(struct Estado *e) {
    char teste[10];
    printf("Digite o nome do estado: ");
    lerStr(e->nomeEstado, TAM_NOME);
    printf("Digite a quantidade de veiculos que circulam nesse estado: ");
    scanf("%d", &e->numeroVeiculo);
    printf("Digite a quantidade de acidentes de veiculos nesse estado: ");
    scanf("%d", &e->numeroAcidentes);
    lerStr(teste, 10);
}


void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam -  1] == '\n') {
        str[tam - 1] = '\0';
    }
}

void quantidadeAcidentes(struct MaiorMenor *m, struct Estado *e) {
    m->maior = buscaMaiorAcidentes(&e);
    m->menor = buscaMenorAcidentes(&e);
    
}

int buscaMaiorAcidentes(struct Estado *e[]) {
    int maior = 0, indice;
    for(int i = 0; i < QTD_ESTADO; i += 1) {
        if (e[i]->numeroAcidentes > maior) {
            maior = e[i]->numeroAcidentes;
            indice = i;
        }
    }
    return indice;
}

int buscaMenorAcidentes(struct Estado *e[]) {
    int menor, indice;
    menor = e[0]->numeroAcidentes;
    for(int i = 1; i < QTD_ESTADO; i += 1) {
        if (e[i]->numeroAcidentes < menor) {
            menor = e[i]->numeroAcidentes;
            indice = i;
        }
    }
    return indice;
}