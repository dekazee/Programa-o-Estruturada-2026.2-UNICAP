#include <stdio.h>

#define QTD_ALUNO 30

double calcularMediaAluno(double n1, double n2);
double calcularMediaTurma(double v[], int n);
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
    media[i] = calcularMediaAluno(nota1[i], nota2[i]);
  }


  printf("Media da Turma: %lf\n", calcularMediaTurma(media, QTD_ALUNO));
  
  
  printf("notas 1: \n");
  imprimirElementos(nota1, QTD_ALUNO);
  printf("notas 2: \n");
  imprimirElementos(nota2, QTD_ALUNO);
  printf("media: \n");
  imprimirElementos(media, QTD_ALUNO);
  
  
  
  
  
  
  return 0;
}

double calcularMediaAluno(double n1, double n2) {
  double media;
  media = (n1*2 + n2*3) / 5;
  return media;
}

double calcularMediaTurma(double v[], int n) {
  double soma, media;
  for (int i=0; i < n; i+=1) {
    soma += v[i];
  }
  media = soma / n;
  return media;
}

void imprimirElementos(double v[], int n) {
  printf("{ %lf", v[0]);
  for (int i = 1; i < n; i+=1) {
    printf(", %lf", v[i]);
  }
  printf(" }\n");
}
