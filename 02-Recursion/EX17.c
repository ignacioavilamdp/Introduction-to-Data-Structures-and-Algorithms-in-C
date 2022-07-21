#include <stdio.h>
#include <stdlib.h>
#define N 30

void cargarV(int V[], int* n);
int sumaV(int V[], int n);
int sumaVC(int V[], int n);

int main(){
    int vector[N], n, suma, sumaC;

    cargarV(vector, &n);
    suma = sumaV(vector, n - 1);   //n - 1 es la posición (índice) del último elemento del arreglo
    sumaC = sumaVC(vector, n - 1);

    printf("\n");
    printf("La suma es: %d \n", suma);
    printf("La suma es: %d \n", sumaC);
    return 0;
}

void cargarV(int V[], int* n){
    int num;

    *n = 0;
    printf("Ingrese un numero o 0 para terminar: ");
    scanf("%d", &num);
    while(num != 0){
        V[(*n)++] = num;
        printf("Ingrese un numero o 0 para terminar: ");
        scanf("%d", &num);
    }
}

int sumaV(int V[], int n){
    if (n == 0)
        return V[n];
    else
        return V[n] + sumaV(V, n - 1);
}

int sumaVC(int V[], int n){
    if (n < 0)
        return 0;
    else
        return V[n] + sumaVC(V, n - 1);
}
