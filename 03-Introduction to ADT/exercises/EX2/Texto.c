#include <stdio.h>
#include <stdlib.h>
#include "Texto.h"


void imprimir(Texto t){
    int i;
    for (i = 0; i < t.longitud; i++){
        printf("%c",*(t.puntero + i));
    }
}

Texto crear(char* c){
    int contador = 0;
    Texto t;

    while(*(c + contador) != '\0'){
        contador++;
    }

    if (contador == 0){
        t.puntero = NULL;
        t.longitud = 0;
    }
    else{
        t.puntero = (char*) malloc(sizeof(char) * contador);
        t.longitud = contador;
        for(int j = 0; j < t.longitud; j++){
            *(t.puntero + j) = *(c + j);
        }
    }
    return t;
}

void destruir(Texto t){
    free(t.puntero);
}

int tamano(Texto t){
    return t.longitud;
}

char caracterEn(Texto t, int posicion){
    char c = '\0';
    if (posicion >= 0 && posicion < t.longitud)
        c = *(t.puntero + posicion);

    return c;
}

Texto concatenar(Texto t1, Texto t2){
    int i, j;
    Texto concatenado;
    concatenado.longitud = t1.longitud + t2.longitud;
    concatenado.puntero = (char*) malloc(sizeof(char) * concatenado.longitud);

    for (i = 0; i < t1.longitud; i++){
        *(concatenado.puntero + i) = *(t1.puntero + i);
    }
    for (j = 0; j < t2.longitud; j++){
        *(concatenado.puntero + i + j) = *(t2.puntero + j);
    }

    return concatenado;
}

Texto reemplazar(Texto t, char caracter, char nuevoCaracter){
    int i;
    Texto reemplazado;
    reemplazado.longitud = t.longitud;
    reemplazado.puntero = (char*) malloc(sizeof(char) * reemplazado.longitud);

    for (i = 0; i < t.longitud; i++){
        if (*(t.puntero + i) == caracter)
            *(reemplazado.puntero + i) = nuevoCaracter;
        else
            *(reemplazado.puntero + i) = *(t.puntero + i);
    }
    return reemplazado;
}

Texto subTexto(Texto t, int desde, int hasta){
    int i;
    Texto sub;
    if (desde >= 0 && hasta < t.longitud && hasta >= desde){
        sub.longitud = hasta - desde + 1;
        sub.puntero = (char*) malloc(sizeof(char) * sub.longitud);
        for (i = 0; i < sub.longitud; i++){
            *(sub.puntero + i) = *(t.puntero + i + desde);
        }
    }
    else{
        sub.puntero = NULL;
        sub.longitud = 0;
    }

    return sub;
}

int comienzaCon(Texto t, Texto prefijo){
    int i, condicion = 1;

    if (prefijo.longitud <= t.longitud){
        for (i = 0; i < prefijo.longitud && condicion; i++){
            if (*(t.puntero + i) != *(prefijo.puntero + i))
                condicion = 0;
        }
    }
    else{
        condicion = 0;
    }

    return condicion;
}

int terminaCon(Texto t, Texto sufijo){
    int i, condicion = 1;

    if (sufijo.longitud <= t.longitud){
        for (i = 0; i < sufijo.longitud && condicion; i++){
            if (*(t.puntero + i + t.longitud - sufijo.longitud) != *(sufijo.puntero + i))
                condicion = 0;
        }
    }
    else
        condicion = 0;

    return condicion;
}
