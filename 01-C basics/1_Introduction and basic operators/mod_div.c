#include <stdio.h>

/* Shows how to use the modulo operator % and the division operator / (K&R Chap 2.7) */

int main(){
    printf("7 %% 5: %d    (mod operator -- only applicable to integer operands -- returns the reminder of the integer division)\n", 7 % 5);
    printf("7 / 5: %d    (div operator -- applied to integer operands -- returns the quotient of the integer division)\n", 7 / 5);
    printf("7./ 5: %.1f  (div operator -- applied to floating point operands -- returns the quotient of the real division)\n\n", 7.0 / 5);
    printf("If any of the operands is the floating point family, the other operand is promoted to floating point (if not already fp) in order to perform a real division \n");

    // printf("7. %% 5: %d   (mod operator cannot be applied to real operators \n", 7. % 5);

    return 0;
}
