#include <stdio.h>
#include <string.h>
#define MAX 40

/*
 *  Shows different ways of creating strings.
 *  Recall that C programming language does not include a string primitive data type.
 *  Strings in C are implemented as arrays of characters ended with a null character.
 */

int main(){
    char s0[MAX];                           //Array of MAX elements. Uninitialized.
    char s1[MAX];                           //Array of MAX elements. Uninitialized.
    char s2[MAX] = "EXAMPLE STRING S2";     //Array of MAX elements. Initialized with a string literal.
    char s3[] = "EXAMPLE STRING S3";        //Array without explicit dimension indication. Initialized with a string. The dimension is defined by the compiler as the length of the literal string plus 1 (null character).
    char s4[MAX] = "";                      //Array of MAX elements. Initialized with an empty string.
    char s5[] = "";                         //Array without explicit dimension indication. Initialized with an empty string. The dimension is defined by the compiler as the length of the literal string plus 1 (null character).

    // An string may be assigned to an array using scanf() function with %s format specifier.
    printf("Enter a string s0: ");
    scanf("%s",s0);
    printf("\n");

    // To assign some string to an array the following expression is not valid: s1 = "example". Of course the assignment must be performed element by element, including the null character.
    s1[0] = 'E';
    s1[1] = 'J';
    s1[2] = 'E';
    s1[3] = 'M';
    s1[4] = 'P';
    s1[5] = 'L';
    s1[6] = 'O';
    s1[7] = '\0';

    // Printing the strings
    printf("s0: %s \n", s0);
    printf("s1: %s \n", s1);
    printf("s2: %s \n", s2);
    printf("s3: %s \n", s3);
    printf("s4: %s \n", s4);
    printf("s5: %s \n", s5);
    printf("\n");

    // Length of the strings using strlen()
    printf("Length of s0: %d \n", strlen(s0));
    printf("Length of s1: %d \n", strlen(s1));
    printf("Length of s2: %d \n", strlen(s2));
    printf("Length of s3: %d \n", strlen(s3));
    printf("Length of s4: %d \n", strlen(s4));
    printf("Length of s5: %d \n", strlen(s5));
    printf("\n");

    // Size of the arrays using sizeof (it may be think as the size in bytes or the amount of chars)
    printf("Capacity of s0: %d \n", sizeof(s0));
    printf("Capacity of s1: %d \n", sizeof(s1));
    printf("Capacity of s2: %d \n", sizeof(s2));
    printf("Capacity of s3: %d \n", sizeof(s3));
    printf("Capacity of s4: %d \n", sizeof(s4));
    printf("Capacity of s5: %d \n", sizeof(s5));

    return 0;
}
