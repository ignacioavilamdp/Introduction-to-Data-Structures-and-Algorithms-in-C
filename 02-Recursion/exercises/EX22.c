#include <stdio.h>
#include <stdlib.h>
#define N 50
#define M 50

void cargarM(int mat[][M], int* n, int* m, char* nombre);
void mostrarM(int mat[][M], int n, int m);
int min(int x, int y);
int minimoF(int A[][M], int i, int j, int n, int m);
void minimoP(int A[][M], int i, int j, int n, int m, int* res);

int main(){
    int mat[N][M], n, m, res = 999;

    cargarM(mat, &n, &m, "DATA_EX22.txt");
    mostrarM(mat, n, m);

    minimoP(mat, 0, 0, n - 1, m - 1, &res);
    printf("El minimo es: %d \n", minimoF(mat, 0, 0, n - 1, m - 1));
    printf("El minimo es: %d \n", res);

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

int min(int x, int y){
    return (x < y) ? x : y;
}

int minimoF(int A[][M], int i, int j, int n, int m){
    int minAnt;

    if (i == n && j == m)
        return A[i][j];
    else{
        if (j < m)
            minAnt = minimoF(A, i, j + 1, n, m);
        else
            minAnt = minimoF(A, i + 1, 0, n, m);

        return min(A[i][j], minAnt);
    }
}

void minimoP(int A[][M], int i, int j, int n, int m, int* res){
    if (i <= n){
        if(A[i][j] < *res)
            *res = A[i][j];

        if (j < m)
            minimoP(A, i, j + 1, n, m, res);
        else
            minimoP(A, i + 1, 0, n, m, res);
    }
}


