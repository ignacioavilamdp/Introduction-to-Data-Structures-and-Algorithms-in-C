#include <stdio.h>
#include <stdlib.h>
#define N 50
#define M 50

void cargarM(int mat[][M], int* n, int* m, char* nombre);
void mostrarM(int mat[][M], int n, int m);
int esMayor(int mat[][M], int i, int j, int n, int m, int sumaFilaAnterior, int sumaFilaActual);

int main(){
    int matriz[N][M], n, m;

    cargarM(matriz, &n, &m, "DATA_EX12_1.txt");
    mostrarM(matriz, n, m);
    printf("Cumple: %d \n\n", esMayor(matriz, 0, 0, n - 1, m - 1, 0, 0));

    cargarM(matriz, &n, &m, "DATA_EX12_2.txt");
    mostrarM(matriz, n, m);
    printf("Cumple: %d \n\n", esMayor(matriz, 0, 0, n - 1, m - 1, 0, 0));

    cargarM(matriz, &n, &m, "DATA_EX12_3.txt");
    mostrarM(matriz, n, m);
    printf("Cumple: %d \n\n", esMayor(matriz, 0, 0, n - 1, m - 1, 0, 0));

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
}

int esMayor(int mat[][M], int i, int j, int n, int m, int sumaFilaAnterior, int sumaFilaActual){
    sumaFilaActual += mat[i][j];

    if(i == n && j == m)
        return (sumaFilaActual > sumaFilaAnterior);
    else{
        if (j != m)     //Todavia no llegó al final de la final
            return esMayor(mat, i, j + 1, n, m, sumaFilaAnterior, sumaFilaActual);
        else{           //LLegó al final de la fila
            if (i == 0){
                if (sumaFilaActual % 2 == 0)
                    return esMayor(mat, i + 1, 0, n, m, sumaFilaActual, 0);
                else
                    return 0;
            }
            else if (sumaFilaActual > sumaFilaAnterior)
                return esMayor(mat, i + 1, 0, n, m, sumaFilaActual, 0);
            else
                return 0;
        }
    }
}

