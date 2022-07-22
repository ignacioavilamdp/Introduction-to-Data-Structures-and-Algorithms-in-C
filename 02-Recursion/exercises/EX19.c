#include <stdio.h>
#include <stdlib.h>
#define N 50
#define M 50

void cargarM(int mat[][M], int* n, int* m, char* nombre);
void mostrarM(int mat[][M], int n, int m);
int sumarM(int mat[][M], int i, int j, int n, int m);   //Por filas de izquierda a derecha, de arriba hacia abajo
int sumarMod(int mat[][M], int i, int j, int n, int m); //Por filas de derecha a izquierda, de abajo hacia arriba

int main(){
    int mat[N][M], n, m;

    cargarM(mat, &n, &m, "DATA_EX19.txt");
    mostrarM(mat, n, m);

    printf("La suma es: %d \n", sumarM(mat, 0, 0, n - 1, m - 1));
    printf("La suma es: %d \n", sumarMod(mat, n - 1, m - 1, n - 1, m - 1));

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

int sumarM(int mat[][M], int i, int j, int n, int m){
    if (i == n && j == m)
        return mat[i][j];
    else{
        if (j != m)
            return mat[i][j] + sumarM(mat, i, j + 1, n, m);
        else
            return mat[i][j] + sumarM(mat, i + 1, 0, n, m);
    }
}

int sumarMod(int mat[][M], int i, int j, int n, int m){
    if (i == 0 && j == 0)
        return mat[i][j];
    else{
        if (j != 0)
            return mat[i][j] + sumarMod(mat, i, j - 1, n, m);
        else
            return mat[i][j] + sumarMod(mat, i - 1, m, n, m);
    }
}
