#include <stdio.h>
#include <stdlib.h>
#define N 50
#define M 50
#define MIN -9999

void cargarM(int mat[][M], int* n, int* m, char* nombre);
void mostrarM(int mat[][M], int n, int m);
void inicializarV(int vec[], int n);
void mostrarV(int vec[], int n);
void obtenerMax(int mat[][M], int i, int j, int n, int m, int max[], int maximo);
void obtenerMaxBis(int mat[][M], int i, int j, int n, int m, int max[]);

int main(){
    int matriz[N][M], maximos[N], n, m;

    cargarM(matriz, &n, &m, "DATA_EX7.txt");
    mostrarM(matriz, n, m);

    obtenerMax(matriz, 0, 0, n - 1, m - 1, maximos, MIN);
    printf("Maximos \n");
    mostrarV(maximos, n);

    inicializarV(maximos, n);
    obtenerMaxBis(matriz, 0, 0, n - 1, m - 1, maximos);
    printf("\nMaximos bis \n");
    mostrarV(maximos, n);

    return 0;
}

void cargarM(int mat[][M], int* n, int* m, char* nombre){
    FILE* arch;
    int i, j;

    *n = 0;
    *m = 0;
    arch = fopen(nombre, "rt");
    if (arch){
        fscanf(arch, "%d %d", n, m);
        for (i = 0; i < (*n); i++)
            for (j = 0; j < (*m); j++)
                fscanf(arch, "%d", &(mat[i][j]));
        fclose(arch);
    }
}

void mostrarM(int mat[][M], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void inicializarV(int vec[], int n){
    int i;

    for (i = 0; i < n; i++){
        vec[i] = MIN;
    }
}

void mostrarV(int vec[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%d\n", vec[i]);
    printf("\n");
}

void obtenerMax(int mat[][M], int i, int j, int n, int m, int max[], int maximo){
    /*  Esta versión utiliza un parámetro máximo que va llevando el máximo de cada fila.
     *  Al llegar a la última columna de una fila, guarda el máximo encontrado en la posición correspondiente del arreglo de máximos
     */

    if (i <= n){
        if (mat[i][j] > maximo)
            maximo = mat[i][j];
        if (j != m)
            obtenerMax(mat, i, j + 1, n, m, max, maximo);
        else{
            max[i] = maximo;
            obtenerMax(mat, i + 1, 0, n, m, max, MIN);
        }
    }
}

void obtenerMaxBis(int mat[][M], int i, int j, int n, int m, int max[]){
    /*  Esta versión no utiliza un parámetro adicional máximo para ir llevando el máximo encontrado en cada fila.
     *  En cambio, utiliza el mismo arreglo de máximos para ir guardando los máximos parciales.
     *  Requiere que el vector de máximos esté inicializado con valores negativos muy grandes
     */

    if (i <= n) {
        if (mat[i][j] > max[i])
            max[i] = mat[i][j];
        if (j != m)
            obtenerMaxBis(mat, i, j + 1, n, m, max);
        else
            obtenerMaxBis(mat, i + 1, 0, n, m, max);
    }
}
