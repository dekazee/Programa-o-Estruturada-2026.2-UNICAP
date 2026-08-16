#include <stdio.h>



double convMm(double m) {
    double convertido;
    convertido = m * 1000;
    return convertido;
}
double convDm(double m){
    double convertido;
    convertido = m * 100;
    return convertido;
}
double convCm(double m){
    double convertido;
    convertido = m * 10;
    return convertido;
}
double convDam(double m){
    double convertido;
    convertido = m / 10;
    return convertido;
}
double convHm(double m){
    double convertido;
    convertido = m / 100;
    return convertido;
}
double convKm(double m){
    double convertido;
    convertido = m / 1000;
    return convertido;
}


void mostrarMenu() {
    printf("Escolha de 0 ate 5 para converter os metros\n");
    printf("0 - milimetros\n 1 - decimetros\n 2 - centimetros\n 3 - decametros \n 4 - hectometros\n 5 - quilometros\n");
}



int main() {
    int decisao;
    double metros, resposta;
    printf("Digite um valor em metros\n");
    scanf(" %lf", &metros);
    mostrarMenu();
    scanf(" %d", &decisao);

    while(decisao < 0 || decisao > 5) {
        printf("Digita essa bomba dnv ai irmao: ");
        scanf(" %d", &decisao);
    }

    if(decisao == 0) {
        resposta = convMm(metros);
    }
    else if(decisao == 1) {
        resposta = convDm(metros);
    }
    else if(decisao == 2) {
        resposta = convCm(metros);
    }
    else if(decisao == 1) {
        resposta = convDam(metros);
    }
    else if(decisao == 1) {
        resposta = convHm(metros);
    }
    else {
        resposta = convKm(metros);
    }

    printf("Conversão: %f\n", resposta);



    return 0;
}