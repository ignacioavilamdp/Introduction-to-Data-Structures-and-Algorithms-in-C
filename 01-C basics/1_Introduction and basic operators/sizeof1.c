#include <stdio.h>

/*
 * Shows how to use sizeof operator.
 * Sizeof returns the size in bytes of an specific variable or data type.
 * Values obtained are machine dependent (K&R Chap 2.2)
 */

int main (){
    int a = 0;
    long b = 0;
    short c =0;
    unsigned d = 0;
    char f = 'd';
    float g = 1.1;
    double h = 1.3;
    long double i = 1.4;

    printf("sizeof(int) = %d \n", sizeof(a));
    printf("sizeof(long) = %d \n", sizeof(b));
    printf("sizeof(short) = %d \n", sizeof(c));
    printf("sizeof(unsigned) = %d \n", sizeof(b));
    printf("sizeof(char) = %d \n", sizeof(f));
    printf("sizeof(float) = %d \n", sizeof(g));
    printf("sizeof(double) = %d \n", sizeof(h));
    printf("sizeof(long double) = %d \n", sizeof(i));

    return 0;
}
