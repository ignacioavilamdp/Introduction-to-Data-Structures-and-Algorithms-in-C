#include <stdio.h>
#include <stdlib.h>
#include "fraccion.h"

int main(){
    fraccion f1, f2, f3, f4, f5, f0;

    f1 = crear(2, 5);
    f2 = crear(7, 9);
    f3 = crear(18, 3);
    f4 = crear(1820, 231);
    f0 = crear(5, 7);

    printf("Numerador de f1  : %d \n", numerador(f1));
    printf("Denominador de f1: %d \n", denominador(f1));

    f5 = sumar(f1, f2); printf("\n");
    printf("Numerador de f5  : %d \n", numerador(f5));
    printf("Denominador de f5: %d \n", denominador(f5));

    f5 = restar(f1, f2); printf("\n");
    printf("Numerador de f5  : %d \n", numerador(f5));
    printf("Denominador de f5: %d \n", denominador(f5));

    f5 = multiplicar(f1, f2); printf("\n");
    printf("Numerador de f5  : %d \n", numerador(f5));
    printf("Denominador de f5: %d \n", denominador(f5));

    f5 = dividir(f1, f2); printf("\n");
    printf("Numerador de f5  : %d \n", numerador(f5));
    printf("Denominador de f5: %d \n", denominador(f5));

    f5 = simplificar(f3); printf("\n");
    printf("Numerador de f5  : %d \n", numerador(f5));
    printf("Denominador de f5: %d \n", denominador(f5));

    f5 = simplificar(f4); printf("\n");
    printf("Numerador de f5  : %d \n", numerador(f5));
    printf("Denominador de f5: %d \n", denominador(f5));

    f5 = simplificar(f0); printf("\n");
    printf("Numerador de f5  : %d \n", numerador(f5));
    printf("Denominador de f5: %d \n", denominador(f5));

    printf("\n");
    printf("Son iguales f1 y f2: %d \n", iguales(f1, f2));
    printf("Son iguales f2 y f2: %d \n", iguales(f2, f2));
    f5 = simplificar(f4);
    printf("Son iguales f4 y f5: %d \n", iguales(f4, f5));

    return 0;
}
