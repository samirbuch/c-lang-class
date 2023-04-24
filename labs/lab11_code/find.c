#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char *str);
int findInString(char *src, char *testStr);

int main(void) {
    char srcStr[] = "concatenate";
    char testStr[] = "cat";

    printf("Source string: %s\n", srcStr);
    printf("Test string:   %s\n", testStr);

    int index = findInString(srcStr, testStr);
    if(index == -1) {
        printf("The test string did not occur in the source string.\n");
        return 0;
    }
    printf("The test string occurred in the source string at index %i (character %i)\n", index, index + 1);
}

int findInString(char *src, char *testStr) {
    char firstCharInTest = testStr[0];

    size_t srclen = strlen(src);
    size_t testlen = strlen(testStr);

    for(int i = 0; i < srclen; i++) {
        if(src[i] != firstCharInTest) {
            continue; // try to reduce that christmas tree-type indentation
        }
        for(int j = 0; j < testlen; j++) {
            if(j == testlen - 1 && src[i + j] == testStr[j]) {
                return i;
            }
        }
    }

    return -1;
}

// need to refactor this into a util header file available across all of lab11
// problem is.. dunno how.
size_t strlen(const char *str) {
    size_t length = 0;
    while(str[length] != '\0') {
        length++;
    }

    return length;
}

