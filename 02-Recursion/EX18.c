#include <stdio.h>
#include <stdlib.h>
#define N 30

void cargarV(int V[], int* pn);
void sumaV(int V[], int n, int* res);
void sumaVC(int V[], int n, int* res);
void sumaVI(int V[], int n, int* res);
void sumaVIC(int V[], int n, int* res);

int main(){
    int arreglo[N], n, resV, resVC, resVI = 0, resVIC = 0;

    cargarV(arreglo, &n);
    sumaV(arreglo, n - 1, &resV);
    sumaVC(arreglo, n - 1, &resVC);
    sumaVI(arreglo, n - 1, &resVI);
    sumaVIC(arreglo, n - 1, &resVIC);

    printf("\n");
    printf("La suma es: %d \n", resV);
    printf("La suma es: %d \n", resVC);
    printf("La suma es: %d \n", resVI);
    printf("La suma es: %d \n", resVIC);

    return 0;
}

void cargarV(int V[], int* n){
    int i = 0, num = 0;

    *n = 0;
    printf("Ingrese un numero o 0 para terminar: ");
    scanf("%d", &num);
    while(num != 0){
        V[(*n)++] = num;
        printf("Ingrese un numero o 0 para terminar: ");
        scanf("%d", &num);
    }
}

void sumaV(int V[], int n, int* res){
    if (n == 0)
        *res = V[n];
    else{
        sumaV(V, n - 1, res);
        *res += V[n];
    }
}

void sumaVC(int V[], int n, int* res){
    if (n < 0)
        *res = 0;
    else{
        sumaVC(V, n - 1, res);
        *res += V[n];
    }
}

void sumaVI(int V[], int n, int* res){
    if (n == 0)
        *res += V[n];
    else{
        *res += V[n];
        sumaVI(V, n - 1, res);
    }
}

void sumaVIC(int V[], int n, int* res){
    if (n >= 0){
        *res += V[n];
        sumaVIC(V, n - 1, res);
    }
}
