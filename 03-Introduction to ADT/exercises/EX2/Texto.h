#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char* puntero;
    int longitud;
} Texto;

Texto crear(char* c);
void destruir(Texto t);
int tamano(Texto t);
char caracterEn(Texto t, int posicion);
Texto concatenar(Texto t1, Texto t2);
Texto reemplazar(Texto t, char caracter, char nuevoCaracter);
Texto subTexto(Texto t, int desde, int hasta);
int comienzaCon(Texto t, Texto prefijo);
int terminaCon(Texto t, Texto sufijo);
void imprimir(Texto t);
