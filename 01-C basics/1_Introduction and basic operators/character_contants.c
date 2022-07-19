#include <stdio.h>
#include <stdbool.h>

/* Prints some typical character constants */

void main(){
    printf("Some characters of the character set of the machine: \n");
    printf("The character constant %i represents the character ' ': White space \n", ' ');
    printf("The character constant %i represents the character 0: Number zero \n", '0');
    printf("The character constant %i represents the character a: Letter a \n\n\n", 'a');

    printf("Some escape sequences (these are characters with a special purpose and cannot be written normaly): \n");
    printf("The character constant %i represents the escape sequence \\0: Null character \n", '\0');
    printf("The character constant %i represents the escape sequence \\t: Tab \n", '\t');
    printf("The character constant %i represents the escape sequence \\n: New line \n\n\n", '\n');

    printf("Some symbolic constants defined in the standard library: \n");
    printf("The symbolic constant EOF represents %i (defined in stdio.h) \n", EOF);
    printf("The symbolic constant true represents %i (definided in stdbool.h) \n", true);
    printf("The symbolic constant false represents %i (definided in stdbool.h) \n", false);
}
