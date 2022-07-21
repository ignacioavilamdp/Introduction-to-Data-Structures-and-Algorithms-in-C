#include <stdio.h>
#include <stdlib.h>
#define N 50

void cargarM(int mat[][N], int* n, char* nombre);
void mostrarM(int mat[][N], int n);
int esSimetrica(int mat[][N], int i, int j, int n);

int main(){
    int matriz[N][N], n;

    cargarM(matriz, &n, "DATA_EX11_1.txt");
    mostrarM(matriz, n);
    printf("Es simetrica: %d \n\n", esSimetrica(matriz, 0, 0, n - 1));

    cargarM(matriz, &n, "DATA_EX11_2.txt");
    mostrarM(matriz, n);
    printf("Es simetrica: %d \n\n", esSimetrica(matriz, 0, 0, n - 1));

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
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int esSimetrica(int mat[][N], int i, int j, int n){
    if(i > n)
        return 1;
    else{
        if (j < n)
            return (mat[i][j] == mat[j][i]) && esSimetrica(mat, i , j + 1, n);
        else
            return (mat[i][j] == mat[j][i]) && esSimetrica(mat, i + 1, i + 1, n);   //Se recorre sólo la mitad superior de la matriz
    }
}
