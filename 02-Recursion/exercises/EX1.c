#include <stdio.h>
#include <stdlib.h>

int producto(int a, int b);

int main(){
    int a, b;

    printf("Operando 1: "); scanf("%d", &a);
    printf("Operando 2: "); scanf("%d", &b);
    printf("%d x %d = %d", a, b, producto(a, b));

    return 0;
}

int producto(int a, int b){
    if (b == 1)
        return a;
    else
        return (a + producto(a, b - 1));
}
