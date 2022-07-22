#include <stdio.h>
#include <stdlib.h>
#define N 50
#define M 50

void cargarM(int mat[][M], int* n, int* m, char* nombre);
void mostrarM(int mat[][M], int n, int m);
int esta(int mat[][M], int i, int j, int n, int m, int x);
int estaCay(int mat[][M], int i, int j, int n, int m, int x);

int main(){
    int mat[N][M], n, m, x;

    cargarM(mat, &n, &m, "DATA_EX21.txt");
    mostrarM(mat, n, m);
    printf("Ingrese numero: "); scanf("%d", &x);
    printf("%d esta en la matriz: %d \n", x, esta(mat, 0, 0, n - 1, m - 1, x));
    printf("%d esta en la matriz: %d \n", x, estaCay(mat, 0, 0, n - 1, m - 1, x));

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

int estaCay(int mat[][M], int i, int j, int n, int m, int x){
    if(i > n)
        return 0;
    else if (mat[i][j] == x)
        return 1;
    else {
        if (j != m)
            return estaCay(mat, i, j + 1, n, m, x);
        else
            return estaCay(mat, i + 1, 0, n, m, x);
    }
}

int esta(int mat[][M], int i, int j, int n, int m, int x){
    if (mat[i][j] == x)
        return 1;
    else if (i == n && j == m)
        return 0;
    else{
        if (j != m)
            return esta(mat, i, j + 1, n, m, x);
        else
            return esta(mat, i + 1, 0, n, m, x);
    }
}
