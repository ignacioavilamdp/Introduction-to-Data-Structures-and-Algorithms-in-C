#include <stdio.h>
#include <stdlib.h>

void divisionEntera(int a, int b, int* cociente, int* resto);

int main(){
    int a, b, cociente, resto;

    printf("Dividendo: "); scanf("%d", &a);
    printf("Divisor: "); scanf("%d", &b);
    divisionEntera(a, b, &cociente, &resto);
    printf("%d / %d = %d con resto %d \n", a, b, cociente, resto);

    return 0;
}

void divisionEntera(int a, int b, int* cociente, int* resto){
    if (a < b)
        *resto = a;
    else{
        (*cociente)++;
        divisionEntera(a - b, b, cociente, resto);
    }
}
