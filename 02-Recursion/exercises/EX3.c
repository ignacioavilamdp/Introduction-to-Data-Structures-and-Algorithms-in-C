#include <stdio.h>
#include <stdlib.h>
#define N 50

void cargarV(int V[], int* n, char* nombre);
void mostrarV(int V[], int n);
void maximoP(int V[], int n, int* res);
int maximoF(int V[], int n);

int main(){
    int vector[N], n, res;

    cargarV(vector, &n, "DATA_EX3.txt");
    mostrarV(vector, n);
    maximoP(vector, n - 1, &res);
    printf("Maximo - Funcion: %d \n", maximoF(vector, n - 1));
    printf("Maximo - Procedimiento: %d \n", res);

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
    printf("\n");
}

void maximoP(int V[], int n, int* res){
    if (n == 0)
        *res = V[0];
    else{
        maximoP(V, n - 1, res);
        if (V[n] > *res)
            *res = V[n];
    }
}

int maximoF(int V[], int n){
    int maxAnt;

    if (n == 0)
        return V[0];
    else{
        maxAnt = maximoF(V, n - 1);
        if (V[n] > maxAnt)
            return V[n];
        else
            return maxAnt;
    }
}

