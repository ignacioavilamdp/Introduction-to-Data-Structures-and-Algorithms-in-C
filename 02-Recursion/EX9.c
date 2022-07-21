#include <stdio.h>
#include <stdlib.h>
#define N 50

void cargarV(int V[], int* n, char* nombre);
void mostrarV(int V[], int n);
void calcularPromedio(int V[], int i, int n, int suma, int contador, float* promedio);

int main(){
    int arreglo[N], n;
    float prom;

    cargarV(arreglo, &n, "DATA_EX9.txt");
    mostrarV(arreglo, n);
    calcularPromedio(arreglo, 0, n - 1, 0, 0, &prom);
    printf("El promedio es: %g \n", prom);

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
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", V[i]);
    printf("\n\n");
}

void calcularPromedio(int V[], int i, int n, int suma, int contador, float* promedio){
    if (i > n){
        *promedio = (float) suma / contador;
    }
    else{
        contador++;
        suma += V[i];
        calcularPromedio(V, i + 1, n, suma, contador, promedio);
    }
}
