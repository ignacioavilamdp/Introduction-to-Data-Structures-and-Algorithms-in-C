#include <stdio.h>
#include <stdlib.h>

/*
    Con funci�n se utiliza el valor retornado como medio de comunicaci�n entre las llamadas. El valor devuelto pasa el resultado parcial a la funcion llamadora (a la vuelta de la recursi�n).
    Con procedimiento se utiliza un par�metro por referencia como medio de comunicaci�n entre llamadas. All� se almacenar�n los resultados parciales y el resultado final.

    Con procedimiento se resuelve de 2 formas:
        Cuando se resuelve "a la vuelta" no es necesario "inicializar" el resultado ya que el �ltimo paso de la recursi�n asignar� el valor 1.
        Cuando se resuelve "a la ida" es necesario "inicializar" el resultado en 1 en forma externa, previo a la invocaci�n.
*/

float potenciaF(int a, int b);
void potenciaPV(int a, int b, float* res);
void potenciaPI(int a, int b, float* res);

int main(){
    int a, b;
    float resI, resV;

    printf("Base: "); scanf("%d", &a);
    printf("Exponente: "); scanf("%d", &b);

    resI = 1;
    potenciaPV(a, b, &resV);
    potenciaPI(a, b, &resI);
    printf("%d^%d: %g \n", a, b, potenciaF(a, b));
    printf("%d^%d: %g \n", a, b, resV);
    printf("%d^%d: %g \n", a, b, resI);

    return 0;
}

float potenciaF(int a, int b){
    if (b == 0)
        return 1;
    else if (b < 0)
        return (1.0 / a) * potenciaF(a, b + 1);
    else
        return a * potenciaF(a, b - 1);
}

void potenciaPV(int a, int b, float* res){
    if (b == 0)
        *res = 1;
    else if (b > 0){
        potenciaPV(a, b - 1, res);
        *res *= a;
    }
    else{
        potenciaPV(a, b + 1, res);
        *res *= 1.0/a;
    }
}

void potenciaPI(int a, int b, float* res){
    if(b > 0){
        *res *= a;
        potenciaPI(a, b - 1, res);
    }
    else if (b < 0){
        *res *= 1.0/a;
        potenciaPI(a, b + 1, res);
    }
}
