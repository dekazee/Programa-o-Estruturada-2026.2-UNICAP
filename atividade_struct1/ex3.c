#include <stdio.h>

struct Vetor {
    double x;
    double y;
    double z;
};
void preencherVetorR3(struct Vetor *v);
void somar_vetores(struct Vetor v1, struct Vetor v2, struct Vetor *v3);
void imprimirVetorR3(struct Vetor v);

int main() {
    struct Vetor v1,v2, soma;
    printf("Digite as coordenadas para o Vetor 1: \n");
    preencherVetorR3(&v1);
    printf("Digite as coordenadas para o Vetor 2: \n");
    preencherVetorR3(&v2);
    somar_vetores(v1,v2,&soma);
    imprimirVetorR3(soma);

}

void preencherVetorR3(struct Vetor *v) {
    printf("Digite o valor para x: ");
    scanf("%lf", &v->x);
    printf("Digite o valor para y: ");
    scanf("%lf", &v->y);
    printf("Digite o valor para z: ");
    scanf("%lf", &v->z);
}

void somar_vetores(struct Vetor v1, struct Vetor v2, struct Vetor *v3) {
    v3->x = v2.x + v1.x;
    v3->y = v2.y + v1.y;
    v3->z = v2.z + v1.z;
}

void imprimirVetorR3(struct Vetor v) {
    printf("x: %.2lf", v.x);
    printf("x: %.2lf", v.y);
    printf("x: %.2lf", v.z);
}