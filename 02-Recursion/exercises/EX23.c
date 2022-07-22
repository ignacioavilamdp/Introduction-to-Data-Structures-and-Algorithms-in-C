#include <stdio.h>
#include <stdlib.h>
#define N 8
#define M 8

/*
    Dada una matriz de NxM caracteres, obtener y mostrar la cantidad de vocales por columna
*/

void mostrarM(char mat[][M], int n, int m);
void mostrarV(int vec[], int n);
int esVocal(char x);
void vocales(char mat[][M], int i, int j, int n, int m, int vec[]);

int main(){
    char mat[N][M] = {{'a', 'b', 'c', 'd', 'e'},{'e', 'b', 'o', 'u', 'a'}, {'x', 'y', 'p', 'i', 'o'}, {'1', '2', '3', '4', 'u'}};
    int vec[M] = {0};
    int n = 4, m = 5;

    printf("Matriz de caracteres: \n");
    mostrarM(mat, n, m);
    vocales(mat, 0, 0, n - 1, m - 1, vec);
    printf("Vector de cantidad de vocales: \n");
    mostrarV(vec, m);

    return 0;
}

void vocales(char mat[][M], int i, int j, int n, int m, int vec[]){
    if (j <= m){
        if (esVocal(mat[i][j]))
            vec[j]++;
        if (i < n)      //No llegó a la última fila de la columna actual
            vocales(mat, i + 1, j, n, m, vec);
        else            //Llegó a la última fila de la columna actual
            vocales(mat, 0, j + 1, n, m, vec);
    }
}

int esVocal(char x){
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return 1;
    else
        return 0;
}

void mostrarM(char mat[][M], int n, int m){
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%2c ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
}

void mostrarV(int vec[], int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%2d ", vec[i]);
    printf("\n\n");
}
