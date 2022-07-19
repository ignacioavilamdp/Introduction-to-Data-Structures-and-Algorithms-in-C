#include <stdio.h>

/*
 * Shows how to use the conditional operator ?
 * The expression: (condition) ? (exp1):(exp2) evaluates to exp1 if the condition is true or to exp2 if it is false
 */


int main (){
    int x, y, max;

    printf("Number x: ");
    scanf("%d", &x);
    printf("Number y: ");
    scanf("%d", &y);

    max = (x >= y) ? x : y;
    printf("\n");
    printf("The larger number is %c being %d\n", (x == max) ? 'x':'y', max);

    return 0;
}
