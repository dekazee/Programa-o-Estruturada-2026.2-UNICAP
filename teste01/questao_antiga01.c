#include <stdio.h>
#include <math.h>

int main() {
    int diametro;
    int altura;
    int quantidade;
    float pi = 3.1415;

    printf("Digite o diametro: \n");
    scanf("%d", &diametro);
    printf("Digite a altura: \n");
    scanf("%d", &altura);
    printf("Digite a quantidade: \n");
    scanf("%d", &quantidade);

    double areaTotal = 2 * (diametro/2) * pi * altura * quantidade;

    int quantidadeLata = ceil(areaTotal / 15);

    int valorTotal = quantidadeLata * 45;

    printf("A quantidade de latas necessárias será %d e o valor total a ser pago será %d", quantidadeLata, valorTotal);

    return 0;

}