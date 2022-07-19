#include <stdio.h>

/*
 * Takes one character from the standard input (keyboard) and prints it with different formats to the standard output (screen)
 * Note that getchar() consumes the final character at the end of each linea '\n' generated with the enter key
 * The way to generate an EOF from the Windows command prompt is "Crtl + C" or "Ctrl + Z"
 */

int main(){
    char c;
    while ((c = getchar()) != EOF){
        printf("\nCharacter printed with putchar(c): ");
        putchar(c);
        printf("\nCharacter printed with printf() as char: %c", c);
        printf("\nCharacter printed with printf() as integer: %i", c);
        printf("\nCharacter printed with printf() as hex: %x", c);
        printf("\n");
    }

    return 0;
}

