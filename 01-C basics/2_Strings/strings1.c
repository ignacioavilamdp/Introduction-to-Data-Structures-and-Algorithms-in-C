#include <stdio.h>
#include <string.h>
#define MAX 25

/*
 * Shows how to handle strings in C.
 *
 * C programming language does not include a string data type.
 * Strings in C are implemented as single dimension arrays of characters (vectors) terminated by the null character '\0'.
 *
 * The null character is used as a sentinel value to indicate where the string ends within the array.
 * Indeed this character is typically used by standard library functions for this puorpose.
 *
 * Three important functions of the standard input/output library (stdio.h) that use this property and may be presented as example:
 *      1. printf("...%s...", array)
 *
 *          The %s format specifier inside the format string instructs printf to interpret the argument "array" as a string.
 *          I.e., printf is expecting to receive an array of char ended with '\0'.
 *          Then, printf will print each character of the array until it finds the null character '\0' (which will not be printed).
 *
 *          If the array passed is not a string, i.e. it does not have a null character in it, printf will keep printing values beyond the limits of the array until it finds a null.
 *
 *      2. scanf("...%s...", array)
 *
 *          The %s format specifier instructs scanf to interpret the characters received in the standard input as a string and to save them in the argument "array".
 *          Scanf will read each character of the input until it finds the first white space (space, new line, tab).
 *          Scanf will populate the "array" sequentially with those characters and will place a null character '\0' at the end.
 *
 *          Of course, is important to pass to scanf an array with sufficient capacity (dimension) to receive every character present at the input plus the null character.
 *          If this is not the case, no checking will be performed for us and scanf may overwrite anything located beyond the limits of the array in memory.
 *
 *      3. strlen(array)
 *          Counts how many characters are in the array until it reaches the null character '\0' (not included). Then returns that count.
 */

int main(){
    char s1[MAX];
    char s2[MAX];

    // Populates the arrays with arbitrary characters but without a null character
    for (int i = 0; i < MAX; i++)
    {
        s1[i] = 'A';
        s2[i] = 'B';
    }

    // Prints s1 y s2 as strings with printf()
    // Printf() prints every character of the array until the null character '\0' is found.
    // In this case the arrays do not have a null character '\0'.
    // It may happen that printf() prints beyond the limits of the arrays (with the associated risk of a segmentation fault)
    printf("Arrays s1 y s2 printed using printf with %%s format specifier: \n");
    printf("s1: %s \n",s1);
    printf("s2: %s \n",s2);
    printf("\n");

    /* Prompts the user to feed some string */
    printf("New value of the string s1 (max %d) : ", MAX);
    scanf("%s",s1);
    printf("\n");

    // Prints s1 y s2 as strings with printf()
    // Printf() prints every character of the array until the null character '\0' is found.
    // s1 array contains a null character placed by scanf() previously, so it will be printed correctly.
    // s2 array does not include a null character, so the complete array will be printed (and possibly some characters beyond)
    printf("Arrays s1 and s2 printed using printf with %%s format specifier: \n");
    printf("s1: %s \n",s1);
    printf("s2: %s \n",s2);
    printf("\n");

    // Prints s1 and s2 traversing the arrays until the null character is found
    // The result should be the same as using printf()
    printf("Arrays s1 and s2 printed with a loop until the null character is found: \n");
    printf("s1: ");
    for (int i = 0; s1[i] != '\0'; i++){
        putchar(s1[i]);
    }
    printf("\n");

    printf("s2: ");
    for (int i = 0; s2[i] != '\0'; i++){
        putchar(s2[i]);
    }
    printf("\n\n");

    // Prints s1 y s2 traversing every element of the array
    // s1 array contains: the entered string + a null character '\0' + a sequence of 'A'
    // So, beyond the null character the array contains whatever was on memory prior to the loading process.
    printf("Arrays s1 and s2 printed with a loop up to the last element: \n");
    printf("s1: ");
    for (int i = 0; i < MAX; i++)
    {
        putchar(s1[i]);
    }
    printf("\n");

    printf("s2: ");
    for (int i = 0; i < MAX; i++)
    {
        putchar(s2[i]);
    }
    printf("\n \n");

    // Analysis of the length of the string using strlen()
    // The strlen() function counts how many characters there are before the null character is found.
    // s1 array contains a null character placed by scanf() previously, so strlen() will correctly return is length
    // s2 array does not include a null character, so strlen() will return the complete capacity of the array (and possibly a larger value)
    printf("Length of the strings obtained using strlen(): \n");
    printf("s1 length: %d \n", strlen(s1));
    printf("s2 lenght: %d \n", strlen(s2));
    printf("\n");

    // Analysis of the capacity of the array using sizeof.
    // This is to show the difference between the capacity of the array supporting a string and the actual length of the string.
    // The sizeof operator returns the size in bytes of the operand
    // When applied to an array of characters, sizeof returns its size in bytes, which in fact matches with the amount of characters of the array.
    // This is the case because every char takes 1 byte.
    printf("Capacity of the arrays obtained using sizeof: \n");
    printf("The sizeof operator returns the size of the array in bytes which in fact matches with the amount of characters (capacity) of the array\n");
    printf("s1 capacity: %d \n", sizeof(s1));
    printf("s2 capacity: %d \n", sizeof(s2));


    return 0;
}
