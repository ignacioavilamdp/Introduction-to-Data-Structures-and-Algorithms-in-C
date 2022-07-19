#include <stdio.h>

/*
 * Shows how to use the increment operator ++ as prefix or suffix (K&R 2.8)
 *
 * The expressions x++ o ++x are equivalent to the following:
 *      1. x += 1
 *      2. x = x +1
 * That is, both have the effect of increment by 1 the value of x.
 *
 * There is however a difference in the order of evaluation when the expression is part of compound expression:
 *      1. with ++x first the value of x is incremented and then that value is used: It is called pre-increment
 *      2. with x++ first the original value of x is used and then is incremented: It is called post-increment
 *
 */


int main(){
    int a, b, x, y;

    a = 1;
    b = 1;

    x = a++;
    y = ++b;

    printf("a: %d \n", a);
    printf("b: %d \n", b);
    printf("x: %d \n", x);
    printf("y: %d \n", y);

    return 0;
}
