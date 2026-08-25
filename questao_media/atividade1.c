#include <stdio.h>

#define QTD_ALUNO 30

double calcularMedia(double n1, double n2);
void imprimirElementos(double v[], int n);

int main() {
  double nota1[QTD_ALUNO], nota2[QTD_ALUNO], media[QTD_ALUNO];
  
  for (int i = 0; i < QTD_ALUNO; i+=1) {
    printf("Digite a nota 1: \n");
    scanf(" %lf", &nota1[i]);
    while (nota1[i] > 10 || nota1[i] < 0)
    {
      printf("Digite apenas notas entre 0 e 10: \n");
      scanf(" %lf", &nota1[i]);
    }
    
    printf("Digite a nota 2: \n");
    scanf(" %lf", &nota2[i]);
    while (nota2[i] > 10 || nota2[i] < 0)
    {
      printf("Digite apenas notas entre 0 e 10: \n");
      scanf(" %lf", &nota2[i]);
    }
  }
  
  for (int i = 0; i < QTD_ALUNO; i+=1) {
    media[i] = calcularMedia(nota1[i], nota2[i]);
  }
  
  printf("notas 1: \n");
  imprimirElementos(nota1, QTD_ALUNO);
  printf("notas 2: \n");
  imprimirElementos(nota2, QTD_ALUNO);
  printf("media: \n");
  imprimirElementos(media, QTD_ALUNO);
  
  
  
  
  
  
  return 0;
}

double calcularMedia(double n1, double n2) {
  double media;
  media = (n1 + n2) / 2;
  return media;
}

void imprimirElementos(double v[], int n) {
  printf("{ %lf", v[0]);
  for (int i = 1; i < n; i+=1) {
    printf(", %lf", v[i]);
  }
  printf(" }\n");
}