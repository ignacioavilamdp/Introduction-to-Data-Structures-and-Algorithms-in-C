#include <stdio.h>
#include <stdlib.h>

int fibI(int n);
int fibF(int n);
void fibP(int n, int* fn, int* fn1, int* fn2);

int contI, contF = 0, contP = 0; //Variables globales para contar la cantidad de invocaciones o ciclos. Sólo a los fines de comparar la performance.

int main(){
    int i, fn, fn1, fn2;

    printf("Fibonacci interativo \n");
    for(i = 0; i < 10; i++){
        printf("fib(%d): %d \n", i, fibI(i));
    }
    printf("\n");

    printf("Fibonacci recursivo con funcion\n");
    for(i = 0; i < 10; i++){
        printf("fib(%d): %d \n", i, fibF(i));
    }
    printf("\n");

    printf("Fibonacci recursivo con procedimiento\n");
    for(i = 0; i < 10; i++){
        fibP(i, &fn, &fn1, &fn2);
        printf("fib(%d): %d \n", i, fn);
    }
    printf("\n");

    printf("Contador interativo: %d\n", contI);
    printf("Contador recursivo - procedimiento: %d\n", contP);
    printf("Contador recursivo - funcion: %d\n", contF);

    return 0;
}

int fibI(int n){
    int fn, fn1, fn2, i;
    contI++;
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else{
        fn2 = 0;        // f0 = 0
        fn1 = 1;        // f1 = 1
        fn = fn1 + fn2; // f2 = 2
        for(i = 3; i <= n; i++){
            contI++;
            fn2 = fn1;
            fn1 = fn;
            fn = fn1 + fn2;
        }
        return fn;
    }
}

int fibF(int n){
    contF++;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibF(n - 1) + fibF(n - 2);
}

void fibP(int n, int* fn, int* fn1, int* fn2){
    contP++;
    if (n == 0)
        *fn = 0;
    else if (n == 1)
        *fn = 1;
    else if (n == 2){
        *fn2 = 0;
        *fn1 = 1;
        *fn = *fn1 + *fn2;
    }
    else{
        fibP(n - 1, fn, fn1, fn2);
        *fn2 = *fn1;
        *fn1 = *fn;
        *fn = *fn1 + *fn2;
    }
}
