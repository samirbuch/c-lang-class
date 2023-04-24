// REFERENCES:
// [1]: https://www.gaijin.at/en/infos/ascii-ansi-character-table

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// grumble grumble forgot we can't use string.h
size_t strlen(const char *str);

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

    char s2[] = "racecar"; // odd-length palindrome
    char *p_parsedS2 = parsenstr(s2, strlen(s2));
    printf("Parsed s2: %s\n", p_parsedS2);

    int isS2Palindrome = isPalindrome(p_parsedS2, strlen(p_parsedS2));
    printf("Is s2 a palindrome? %i\n", isS2Palindrome);

    free(p_parsedS2);

    char s3[] = "hannah"; // even-length palindrome
    char *p_parsedS3 = parsenstr(s3, strlen(s3));
    printf("Parsed s3: %s\n", p_parsedS3);

    int isS3Palindrome = isPalindrome(p_parsedS3, strlen(p_parsedS3));
    printf("Is s3 a palindrome? %i\n", isS3Palindrome);

    free(p_parsedS3);

    return 0;
}

size_t strlen(const char *str) {
    size_t length = 0;
    while(str[length] != '\0') {
        length++;
    }

    return length;
}

// "char *" is a string
// (more accurately: a pointer to the first character in a character array)
char* parsenstr(const char string[], size_t n) {
    if(strlen(string) > 80) {
        fprintf(stderr, "String must not be longer than 80 characters.\n");
        exit(1);
    }

    // Initially create an array of size n in case all the input string
    // is a palindrome...
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

    // ... then shrink it down to the size of the valid characters.
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