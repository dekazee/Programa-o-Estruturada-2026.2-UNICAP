#include <stdio.h>
#include <math.h>

struct Polar {
    double raio;
    double amplitude;
};

struct Cartesiano {
    double x;
    double y;
};

void converterPolarParaCartesiano(struct Cartesiano *c, struct Polar p);
void preencherCoord(struct Polar *p);
void imprimirCoordCartesiana(struct Cartesiano c);

int main() {
    struct Cartesiano c1;
    struct Polar p1;
    printf("Digite as coordenadas Polares\n");
    preencherCoord(&p1);
    converterPolarParaCartesiano(&c1, p1);
    printf("CONVERSAO DE POLAR PARA CARTESIANO\n");
    imprimirCoordCartesiana(c1);
    return 0;

}

void converterPolarParaCartesiano(struct Cartesiano *c, struct Polar p) {
    double radianos = p.amplitude * 3.141592653589793 / 180.0;
    c->x = p.raio * cos(radianos);
    c->y = p.raio * sin(radianos);
}

void preencherCoord(struct Polar *p) {
    printf("Digite um valor para r: ");
    scanf("%lf", &p->raio);
    printf("Digite um valor para amplitude: ");
    scanf("%lf", &p->amplitude);
}

void imprimirCoordCartesiana(struct Cartesiano c) {
    printf("x: %.2lf\n", c.x);
    printf("y: %.2lf\n", c.y);
}