#include <stdio.h>
#include <stdlib.h>
#define N 50

void cargarV(int V[], int* n, char* nombre);
void mostrarV(int V[], int i, int n);
int busLineal(int V[], int i, int n, int x);
int busBinaria(int V[], int i, int, int x);

int main(){
    int vector[N], n, pos, x;

    cargarV(vector, &n, "DATA_EX5.txt");
    mostrarV(vector, 0, n - 1);

    printf("\n\nIngrese el valor a buscar: ");
    scanf("%d", &x); printf("\n");
    printf("%Posicion - Busqueda lineal: %d \n", busLineal(vector, 0, n - 1, x));
    printf("%Posicion - Busqueda binaria: %d \n", busBinaria(vector, 0, n - 1, x));

    return 0;
}

void cargarV(int V[], int* n, char* nombre){
    FILE* arch;
    int num;

    *n = 0;
    arch = fopen(nombre, "rt");
    if (arch){
        while (fscanf(arch, "%d", &num) == 1){
            V[(*n)++] = num;
        }
        fclose(arch);
    }
}

void mostrarV(int V[], int i, int n){
    if (i <= n){
        printf("%d ", *(V + i));
        mostrarV(V, i + 1, n);
    }
}

int busLineal(int V[], int i, int n, int x){
    if (i > n)
        return -1;
    else{
        if (V[i] == x)
            return i;
        else
            return busLineal(V, i + 1, n, x);
    }
}

int busBinaria(int V[], int i, int n, int x){
    int medio = (i + n) / 2;

    if (i > n)
        return -1;
    else{
        if (V[medio] == x)
            return medio;
        else if (x < V[medio])
            return busBinaria(V, i, medio - 1, x);
        else
            return busBinaria(V, medio + 1, n, x);
    }
}
