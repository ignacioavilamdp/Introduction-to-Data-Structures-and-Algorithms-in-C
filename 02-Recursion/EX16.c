#include <stdio.h>
#include <stdlib.h>
#define N 30

void cargarV(int V[], int* n);
int sumaV(int V[], int i, int n);        //Suma a la vuelta
int sumaVC(int V[], int i, int n);       //Suma a la vuelta "cayendose" del arreglo

int main(){
    int vector[N], n, suma, sumaC;

    cargarV(vector, &n);
    suma = sumaV(vector, 0, n - 1);      //n - 1 es la posición (índice) del último elemento del arreglo
    sumaC = sumaVC(vector, 0, n - 1);

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

int sumaV(int A[], int i, int n){
    if (i == n)
        return A[i];
    else
        return A[i] + sumaV(A, i + 1, n);
}

int sumaVC(int A[], int i, int n){
    if (i > n)
        return 0;
    else
        return A[i] + sumaVC(A, i + 1, n);
}
