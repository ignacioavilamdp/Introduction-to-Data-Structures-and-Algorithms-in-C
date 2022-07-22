#include <stdio.h>
#include <stdlib.h>
#define N 50

void cargarV(int V[], int* n, char* nombre);
void mostrarV(int V[], int n);
void mostrarVI(int V[], int n);
int sumarV(int V[], int n);

int main(){
    int vector[N], n;

    cargarV(vector, &n, "DATA_EX4.txt");
    mostrarV(vector, n - 1); printf("\n");
    mostrarVI(vector, n - 1); printf("\n");
    printf("La suma de elementos es: %d \n", sumarV(vector, n - 1));

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

void mostrarV(int V[], int n){
    if (n >= 0){
        mostrarV(V, n - 1);
        printf("%d ", V[n]);
    }
}

void mostrarVI(int V[], int n){
    if (n >= 0){
        printf("%d ", V[n]);
        mostrarVI(V, n - 1);
    }
}

int sumarV(int V[], int n){
    if (n == 0)
        return V[0];
    else
        return V[n] + sumarV(V, n - 1);
}

