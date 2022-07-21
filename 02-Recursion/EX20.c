#include <stdio.h>
#include <stdlib.h>
#define N 50
#define M 50

void cargarM(int mat[][M], int* n, int* m, char* nombre);
void mostrarM(int mat[][M], int n, int m);
int cantidadPares(int mat[][M], int i, int j, int n, int m);

int main(){
    int mat[N][M], n, m;

    cargarM(mat, &n, &m, "DATA_EX20.txt");
    mostrarM(mat, n, m);
    printf("Columnas pares: %d\n", cantidadPares(mat, 0, 0, n - 1, m - 1));

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

int cantidadPares(int mat[][M], int i, int j, int n, int m){
    if (j > m)
        return 0;
    else if (i != n){    //i no es la última fila de la columna j
        if (mat[i][j] % 2 == 0)
            return cantidadPares(mat, i + 1, j, n, m);  //Avanza a la siguiente fila manteniendose en la misma columna
        else
            return cantidadPares(mat, 0, j + 1, n, m);  //Avanza a la siguiente columna. Se encontró un elemento que no es par, se abandona la columna actual.
    }
    else{               //i es la última fila de la columna j
        if (mat[i][j] % 2 == 0)                         //Avanza a la siguiente columna. Todos los elementos previos de esta columna y el actual son pares, por tanto se suma 1.
            return 1 + cantidadPares(mat, 0, j + 1, n, m);
        else
            return cantidadPares(mat, 0, j + 1, n, m);  //Avanza a la siguiente columan. Todos los elementos previos de esta columna son pares, pero el actual no, por tanto no suma nada.
    }
}
