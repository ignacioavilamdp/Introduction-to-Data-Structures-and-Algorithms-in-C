#include <stdio.h>

/*
 * C does not include a primitive "boolean" data type. "Int" type is used for such purposes.
 * In C a logical expression is considered to be false if it is evaluated to 0 and true in any other case.
 * So, "true" equals "not zero" (K&R Chap 2.7)
 */

int main(){

    if(-2)
        printf("This is to show that ""-2"" is considered true \n");

    if(-1)
        printf("This is to show that ""-1"" is considered true \n");

    if(0)
        printf("This is to show that ""0"" is considered false \n");

    if(1)
        printf("This is to show that ""1"" is considered true \n");

    if(2)
        printf("This is to show that ""2"" is considered true \n");

    return 0;
}
