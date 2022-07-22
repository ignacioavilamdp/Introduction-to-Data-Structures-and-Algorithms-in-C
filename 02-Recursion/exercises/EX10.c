#include <stdio.h>
#include <stdlib.h>
#define N 50
#define M 50

void cargarM(float mat[][M], int* n, int* m, char* nombre);
void mostrarM(float mat[][M], int n, int m);
int contarF(float mat[][M], int i, int j, int n, int m, float x);
void contarP(float mat[][M], int i, int j, int n, int m, float x, int* res);

int main(){
    float matriz[N][M], x;
    int n, m, cant;

    cargarM(matriz, &n, &m, "DATA_EX10.txt");
    mostrarM(matriz, n, m);

    printf("\nIngrese el valor buscado: "); scanf("%f", &x);
    contarP(matriz, 0, 0, n - 1, m - 1, x, &cant);
    printf("\n");
    printf("Aparece %d veces - Funcion \n", contarF(matriz, 0, 0, n - 1, m - 1, x));
    printf("Aparece %d veces - Procedimiento \n", cant);

    return 0;
}

void cargarM(float mat[][M], int* n, int* m, char* nombre){
    FILE* arch;
    int i, j;

    *n = 0;
    *m = 0;
    arch = fopen(nombre, "rt");
    if (arch){
        fscanf(arch, "%d %d", n, m);
        for (i = 0; i < (*n); i++)
            for (j = 0; j < (*m); j++)
                fscanf(arch, "%f", &(mat[i][j]));
        fclose(arch);
    }
}

void mostrarM(float mat[][M], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%4g ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int contarF(float mat[][M], int i, int j, int n, int m, float x){
    int suma;
    if (i > n)
        return 0;
    else{
        suma = (mat[i][j] == x) ? 1 : 0;
        if (j != m)
            return suma + contarF(mat, i, j + 1, n, m, x);
        else
            return suma + contarF(mat, i + 1, 0, n, m, x);
    }
}

void contarP(float mat[][M], int i, int j, int n, int m, float x, int* res){
    if (i <= n){
        if (mat[i][j] == x)
            (*res)++;
        if (j != m)
            contarP(mat, i, j + 1, n, m, x, res);
        else
            contarP(mat, i + 1, 0, n, m, x, res);
    }
}
