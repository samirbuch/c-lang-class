#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char *str);
int findInString(char *src, char *testStr);

int main(void) {
    char srcStr[] = "concatenate";
    char testStr[] = "cat";

    printf("Source string: %s\n", srcStr);
    printf("Test   string: %s\n", testStr);

    int index = findInString(srcStr, testStr);
    printf("%i\n", index);
}

int findInString(char *src, char *testStr) {
    int idx = 0;
    char firstCharInTest = testStr[0];

    size_t srclen = strlen(src);
    size_t testlen = strlen(testStr);

    for(int i = 0; i < srclen; i++) {
        if(src[i] != firstCharInTest) {
            continue; // try to reduce that christmas tree-type indentation
        }
        for(int j = 0; j < testlen; j++) {
            if(j == testlen - 1 && src[i + j] == testStr[j]) {
                idx = i;
                return idx;
            }
        }
    }

    return idx;
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

