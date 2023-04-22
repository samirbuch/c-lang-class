// REFERENCES:
// [1]: https://www.gaijin.at/en/infos/ascii-ansi-character-table

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Following in C's naming convention lol
void parsenstr(const char string[], size_t n, char *out);

int main(void) {

    char str[] = "Is This A Palindrome?";
    if(strlen(str) > 80) {
        fprintf(stderr, "String must not be longer than 80 characters.\n");
        exit(1);
    }

    char *p = calloc(strlen(str), sizeof(char));
    parsenstr(str, strlen(str), p);

    printf("parsed string: %s\n", p);

    free(p);

    return 0;
}

// "char *" is a string
// (more accurately: a pointer to the first character in a character array)
void parsenstr(const char string[], size_t n, char *out) {
    int idx = 0;
    for(int i = 0; i < (int) n; i++) {
        char c = toupper(string[i]);
        if((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) { // 0-9, A-Z
            out[idx++] = c;
        } // REF: [1]
    }
}

int isPalidrome(char string[]) {

}