#include <stdio.h>
#include <stdlib.h>
#define N 50
#define INF 9999

void cargarM(int mat[][N], int* n, char* nombre);
void mostrarM(int mat[][N], int n);
int minimo(int mat[][N], int i, int j, int n);
int minimoBis(int mat[][N], int i, int j, int n);

int main(){
    int matriz[N][N], n;

    cargarM(matriz, &n, "DATA_EX6.txt");
    mostrarM(matriz, n);
    printf("El minimo es: %d\n", minimo(matriz, 0, 0, n - 1));
    printf("El minimo es: %d\n", minimoBis(matriz, 0, 0, n - 1));

    return 0;
}

void cargarM(int mat[][N], int* n, char* nombre){
    FILE* arch;
    int i, j;

    *n = 0;
    arch = fopen(nombre, "rt");
    if (arch){
        fscanf(arch, "%d", n);
        for (i = 0; i < (*n); i++)
            for (j = 0; j < (*n); j++)
                fscanf(arch, "%d", &(mat[i][j]));
        fclose(arch);
    }
}

void mostrarM(int mat[][N], int n){
    int i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            printf("%4d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

int minimo(int mat[][N], int i, int j, int n){
    int minAnt;

    if (i == n && j == n)
        return mat[i][j];
    else{
        if (i < n)
            minAnt = minimo(mat, i + 1, j, n);
        else
            minAnt = minimo(mat, 0, j + 1, n);

        return (mat[i][j] < minAnt) ? (mat[i][j]) : (minAnt);
    }
}

int minimoBis(int mat[][N], int i, int j, int n){
    int minAnt;

    if (j > n)
        return INF;
    else{
        if (i < n)
            minAnt = minimoBis(mat, i + 1, j, n);
        else
            minAnt = minimoBis(mat, 0, j + 1, n);

        return (mat[i][j] < minAnt) ? mat[i][j] : minAnt;
    }
}
