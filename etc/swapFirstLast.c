#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swapFirstLast(char string[]);

int main(void) {

    // Odd-length string (13)
    char str[] = "Hello, world!";
    printf("Old string: %s\n", str);
    swapFirstLast((char *) &str);
    printf("New string: %s\n\n", str);

    // Even-length string (12)
    char str2[] = "Hello world!";
    printf("Old string: %s\n", str2);
    swapFirstLast((char *) &str2);
    printf("New string: %s\n", str2);

    return 0;
}

void swapFirstLast(char string[]) {
    int stringLength = strlen(string);

    for (int i = 0; i < ceil(stringLength / 2); i++) {
        char temp;
        int lastCharIdx = abs(stringLength - i - 1);

        // switcheroo
        temp = string[i];
        string[i] = string[lastCharIdx];
        string[lastCharIdx] = temp;
    }
}