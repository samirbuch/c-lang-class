// REFERENCES:
// [1]: https://www.gaijin.at/en/infos/ascii-ansi-character-table

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Following in C's naming convention lol
char* parsenstr(const char string[], size_t n);
int isPalindrome(const char *string, size_t n);

int main(void) {

    char s1[] = "Is This A Palindrome?";
    char *p_parsedS1 = parsenstr(s1, strlen(s1));
    printf("Parsed s1: %s\n", p_parsedS1);

    int isS1Palindrome = isPalindrome(p_parsedS1, strlen(p_parsedS1));
    printf("Is s1 a palindrome? %i\n", isS1Palindrome);

    free(p_parsedS1);

    char s2[] = "hannah";
    char *p_parsedS2 = parsenstr(s2, strlen(s2));
    printf("Parsed s2: %s\n", p_parsedS2);

    int isS2Palindrome = isPalindrome(p_parsedS2, strlen(p_parsedS2));
    printf("Is s2 a palindrome? %i\n", isS2Palindrome);

    free(p_parsedS2);

    return 0;
}

// "char *" is a string
// (more accurately: a pointer to the first character in a character array)
char* parsenstr(const char string[], size_t n) {
    if(strlen(string) > 80) {
        fprintf(stderr, "String must not be longer than 80 characters.\n");
        exit(1);
    }

    char *out = calloc(n, sizeof(char));
    if(out == NULL) {
        fprintf(stderr, "Failed to allocate and initialize memory of size %lu\n", n * sizeof(char));
        exit(1);
    }

    int idx = 0;
    for(int i = 0; i < (int) n; i++) {
        char c = toupper(string[i]);
        if((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) { // 0-9, A-Z
            out[idx++] = c;
        } // REF: [1]
    }

    out = reallocarray(out, idx + 1, sizeof(char));

    return out;
}

int isPalindrome(const char *string, size_t n) {
    for(int i = 0; i < ceil(n / 2); i++) {
        char firstChar = string[i];
        char lastChar = string[n - 1 - i];

        if(firstChar != lastChar) {
            return 0;
        }
    }

    return 1;
}