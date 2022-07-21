#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

void invI(char cadO[], char cadI[], int n, int i);
void invV(char cadO[], char cadI[], int n, int i);

int main(){
    char cadena[N], cadenaA[N], cadenaB[N];
    int len;

    printf("Ingrese cadena original: ");
    gets(cadena);
    len = strlen(cadena);

    invI(cadena, cadenaA, len - 1, 0);  //len - 1 es el último índice del arreglo con un caracter válido (antes del caracter nulo)
    invV(cadena, cadenaB, len - 1, 0);

    printf("La cadena invertida es: %s \n", cadenaA);
    printf("La cadena invertida es: %s \n", cadenaB);

    return 0;
}

void invI(char cadO[], char cadI[], int n, int i){
    if (i > n)
        cadI[n + 1] = '\0';
    else{
        cadI[n - i] = cadO[i];
        invI(cadO, cadI, n, i + 1);
    }
}

void invV(char cadO[], char cadI[], int n, int i){
    if (i > n)
        cadI[n + 1] = '\0';
    else{
        invV(cadO, cadI, n, i + 1);
        cadI[n - i] = cadO[i];
    }
}
