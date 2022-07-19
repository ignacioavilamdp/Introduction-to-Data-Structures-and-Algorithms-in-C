#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Prints the limits of the different data type based on the symbolic constants defined in <limits.h> y <float.h>
 * Of course, the values obtained are machine dependent.
 */

int main(){
    /* CHAR */
    printf("CHAR\n");
    printf("Number of bits of char: %d \n\n", CHAR_BIT);

    printf("Min value of char: %d \n", CHAR_MIN);
    printf("Max value of char: %d \n\n", CHAR_MAX);

    printf("Min value of signed char: %d \n",SCHAR_MIN);
    printf("Max value of signed char: %d \n\n", SCHAR_MAX);

    printf("Min value of unsigned char: %d \n",0);
    printf("Max value of unsigned char: %d \n\n\n\n", UCHAR_MAX);


    /* SHORT (INT) */
    printf("SHORT (INT)\n");
    printf("Number of bits of short: %d \n\n", CHAR_BIT*2);
    printf("Min value of short: %d \n", SHRT_MIN);
    printf("Max value of short: %d \n\n", SHRT_MAX);

    printf("Min value of signed short: %d \n",SHRT_MIN);
    printf("Max value of signed short: %d \n\n", SHRT_MAX);

    printf("Min value of unsigned short: %d \n",0);
    printf("Max value of unsigned short: %d \n\n\n\n", USHRT_MAX);


    /* INT */
    printf("INT\n");
    printf("Number of bits of int: %d \n\n", CHAR_BIT*4);
    printf("Min value of int: %d \n", INT_MIN);
    printf("Max value of int: %d \n\n", INT_MAX);

    printf("Min value of signed int: %d \n",INT_MIN);
    printf("Max value of signed int: %d \n\n", INT_MAX);

    printf("Min value of unsigned int: %d \n",0);
    printf("Max value of unsigned int: %u \n\n\n\n", UINT_MAX);


    /* LONG (INT) */
    printf("LONG (INT)\n");
    printf("Number of bits of long: %d \n\n", CHAR_BIT*4);
    printf("Min value of long: %d \n", LONG_MIN);
    printf("Max value of long: %d \n\n", LONG_MAX);

    printf("Min value of signed long: %d \n",LONG_MIN);
    printf("Max value of signed long: %d \n\n", LONG_MAX);

    printf("Min value of unsigned long: %d \n",0);
    printf("Max value of unsigned long: %u \n\n\n\n", ULONG_MAX);


    /* FLOAT */
    printf("FLOAT\n");
    printf("Min value of float: %g \n", FLT_MIN);
    printf("Max value of float: %g \n\n\n\n", FLT_MAX);

    /* DOUBLE */
    printf("DOUBLE\n");
    printf("Min value of float: %g \n", DBL_MIN);
    printf("Max value of float: %g \n\n\n\n", DBL_MAX);

    return 0;
}
