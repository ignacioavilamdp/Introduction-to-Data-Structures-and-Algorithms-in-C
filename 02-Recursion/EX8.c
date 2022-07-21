#include <stdio.h>
#include <stdlib.h>
#define N 50

void cargarV(int V[], int* n, char* nombre);
void mostrarV(int V[], int n);
void mezclar(int A[], int B[], int i, int j, int n, int m, int C[], int* z);

int main(){
    int arreglo1[N], arreglo2[N], combinado[N], n, m, z;

    cargarV(arreglo1, &n, "DATA_EX8_1.txt");
    cargarV(arreglo2, &m, "DATA_EX8_2.txt");
    mostrarV(arreglo1, n);
    mostrarV(arreglo2, m);

    z = 0;
    mezclar(arreglo1, arreglo2, 0, 0, n - 1, m - 1, combinado, &z);
    mostrarV(combinado, z);

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

void mezclar(int A[], int B[], int i, int j, int n, int m, int C[], int* z){

    if (i <= n && j <= m){
        if (A[i] == B[j]){
            C[(*z)++] = A[i];
            mezclar(A, B, i + 1, j + 1, n, m, C, z);
        }
        else if (A[i] < B[j]){
            C[(*z)++] = A[i];
            mezclar(A, B, i + 1, j, n, m, C, z);
        }
        else{
            C[(*z)++] = B[j];
            mezclar(A, B, i, j + 1, n, m, C, z);
        }
    }
    else if (i <= n){
        C[(*z)++] = A[i];
        mezclar(A, B, i + 1, j, n, m, C, z);
    }
    else if (j <= m){
        C[(*z)++] = B[j];
        mezclar(A, B, i, j + 1, n, m, C, z);
    }
}
