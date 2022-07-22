#include <stdio.h>
#include <stdlib.h>
#include "Texto.h"

int main(){
    char cadena1[] = "Hola Pepito Gonzalez?";
    char cadena2[] = "Biennnnnn!";
    Texto texto1, texto2, texto3, texto4, texto5;

    texto1 = crear(cadena1);
    texto2 = crear(cadena2);
    printf("Analisis del texto1\n");
    printf("Texto1: "); imprimir(texto1); printf("\n");
    printf("Tamanio de texto1: %d \n", tamano(texto1));
    printf("Caracter en posicion -1: %c \n", caracterEn(texto1, -1));
    printf("Caracter en posicion 0: %c \n", caracterEn(texto1, 0));
    printf("Caracter en posicion 8: %c \n", caracterEn(texto1, 8));
    printf("Caracter en posicion 20: %c \n", caracterEn(texto1, 20));
    printf("Caracter en posicion 21: %c \n", caracterEn(texto1, 21));

    printf("\n\n");
    printf("Prueba de concatenacion: \n");
    texto3 = concatenar(texto1, texto2);
    printf("Texto1: "); imprimir(texto1); printf("\n");
    printf("Texto2: "); imprimir(texto2); printf("\n");
    printf("Texto3: "); imprimir(texto3); printf("\n");

    printf("\n\n");
    printf("Reemplzando las 'a' por 'e' \n");
    texto4 = reemplazar(texto1, 'a', 'e');
    printf("Texto4: "); imprimir(texto4); printf("\n");

    printf("\n\n");
    printf("Diferentes subtextos\n");
    texto5 = subTexto(texto1, 3, 9);
    printf("Texto5: "); imprimir(texto5); printf("\n");
    texto5 = subTexto(texto1, 0, tamano(texto1) - 1);
    printf("Texto5: "); imprimir(texto5); printf("\n");
    texto5 = subTexto(texto1, 10, 5);
    printf("Texto5: "); imprimir(texto5); printf("\n");

    printf("\n\n");
    printf("Pruebas de empieza y termina con: \n");
    printf("Comienza con: %d \n", comienzaCon(texto3, texto1));
    printf("Comienza con: %d \n", comienzaCon(texto1, texto3));
    printf("Comienza con: %d \n", comienzaCon(texto1, texto2));
    printf("Termina con: %d \n", terminaCon(texto3, texto2));
    printf("Termina con: %d \n", terminaCon(texto2, texto3));
    printf("Termina con: %d \n", terminaCon(texto1, texto2));


    destruir(texto1);
    destruir(texto2);
    destruir(texto3);
    destruir(texto4);
    destruir(texto5);
    return 0;
}
