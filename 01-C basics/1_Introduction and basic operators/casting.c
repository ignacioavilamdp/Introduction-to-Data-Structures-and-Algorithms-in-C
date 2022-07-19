#include <stdio.h>

/* Some examples of explicit type conversion (casting)*/

int main(){
    int x = 7;
    int y = 5;

    printf("x %% y = %d  The modulo operator %%  provides the remainder of the integer division -- just with integer operands --\n", x % y);
    printf("x / y = %d   The division operator / provides the quotient of the integer division  -- just with integer operands --\n", 7 / 5);
    printf("\n");
    printf("(float) x / y = %.1f  The division operator / provides the quotient of the real division  -- just with floating point operands -- \n\n", (float) x / y);
    printf("The expression (float) x indicates an explicit convertion of x to float. Being the first operand of type float, the second operand is Para poder realizar la division el segundo operando y es promovido automaticamente a float \n");

    return 0;
}
