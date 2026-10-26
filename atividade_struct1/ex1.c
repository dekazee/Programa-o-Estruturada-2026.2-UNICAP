#include <stdio.h>

#define TAM_COMP 50

struct Horario {
    int hora;
    int minuto; 
    int segundos;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Compromisso {
    struct Data data;
    struct Horario horario;
    char comprimisso[TAM_COMP];

};


int main() {
    return 0;
}