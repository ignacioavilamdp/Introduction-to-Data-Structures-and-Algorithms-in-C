#include <stdio.h>

/*
 * Prints the value of EOF defined in the standard library.
 * Typically EOF is defined in stdio.h as a symbolic constant of value -1.
 * For greater detail please inspect stdio.h
 * When the functions getchar() or getc() (for example) return -1, this is way to indicate the End Of File, i.e. there are not more characters to read.
 * EOF is not a character, it is a symbolic constant of value -1. This value is returned by the OS during the reading process to indicate the end of the file.
 * Namely, EOF is not a character (located at the end of the file as one may think) but a result returned by the OS when the end of the file is reached.
 * So, in general, files do not have a sentinel character located a the end. It is the OS file system who knows where the files begin and finish.
 */

void main(){
    printf("EOF es igual a : %i", EOF);
}
