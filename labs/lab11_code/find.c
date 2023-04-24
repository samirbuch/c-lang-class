#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char *str);

int findOneInString(char *src, char *testStr);

int *findAllInString(char *src, char *testStr);

void replaceAll(char *src, char *testStr, char *replaceWith);

int main(void) {
    char srcStr[] = "concatenate";
    char testStr[] = "cat";

    printf("Source string: %s\n", srcStr);
    printf("Test string:   %s\n", testStr);

    int index = findOneInString(srcStr, testStr);
    if (index == -1) {
        printf("The test string did not occur in the source string.\n");
        return 0;
    }
    printf("The test string occurred in the source string at index %i (character %i)\n", index, index + 1);

    char srcMultStr[] = "catcatcarcat";
    printf("Source string: %s\n", srcMultStr);
    printf("Test string:   %s\n", testStr);

    int *indices = findAllInString(srcMultStr, testStr);
    printf("%i, %i, %i\n",
           indices[0], indices[1], indices[2]);

    printf("Old string: %s\n", srcMultStr);
    replaceAll(srcMultStr, "cat", "dog");
    printf("New string: %s\n", srcMultStr);

    free(indices);
}

/**
 * Find first occurrence of testStr in src
 * @param src Source string
 * @param testStr String to find in src
 * @return Integer denoting the index of testStr in src
 */
int findOneInString(char *src, char *testStr) {
    char firstCharInTest = testStr[0];

    size_t srclen = strlen(src);
    size_t testlen = strlen(testStr);

    for (int i = 0; i < srclen; i++) {
        if (src[i] != firstCharInTest) {
            continue; // try to reduce that christmas tree-type indentation
        }
        for (int j = 0; j < testlen; j++) {
            if (j == testlen - 1 && src[i + j] == testStr[j]) {
                return i;
            }
        }
    }

    return -1;
}

/**
 * Find all occurrences of testStr in src
 * @param src Source string
 * @param testStr String to find in src
 * @return Array of integers denoting the indexes of testStr in src
 */
int *findAllInString(char *src, char *testStr) {
    if (strlen(testStr) > strlen(src)) {
        return NULL;
    }

    // Allocate at most strlen(src) elements. Cannot possibly be more than.
    int *positions = calloc(strlen(src), sizeof(int));
    if (positions == NULL) {
        fprintf(stderr, "Failed to allocate and initialize memory of size %lu\n", strlen(src) * sizeof(char));
        exit(1);
    }
    int positionsIdx = 0;

    char firstCharInTest = testStr[0];

    size_t srclen = strlen(src);
    size_t testlen = strlen(testStr);

    for (int i = 0; i < srclen; i++) {
        if (src[i] != firstCharInTest) {
            continue; // try to reduce that christmas tree-type indentation
        }
        for (int j = 0; j < testlen; j++) {
            if (j == testlen - 1 && src[i + j] == testStr[j]) {
                positions[positionsIdx++] = i;
            }
        }
    }

    // This denotes the end of the array, regardless of how many more bytes we allocated.
    // When reading the positions array, the user should check for a value of -1 to mark
    // the end of the array.
    positions[positionsIdx++] = -1;

    // TODO: loop through array later to clean up memory
    // (check for -1, reallocarray).

    return positions;
}

/**
 * Destructively replaces all occurrences of replaceWith in src
 * @param src Source string
 * @param testStr String to find in src
 * @param replaceWith String to replace all occurrences of testStr in src
 */
void replaceAll(char *src, char *testStr, char *replaceWith) {
    int *allIndexes = findAllInString(src, testStr);

//    // Test for the difference between the length of the string we're replacing with
//    // and the length of the string we're testing for.
//    // This prevents "index drift," where, without this calculation, we'll be writing to
//    // the wrong src string indexes (by a "drift" of the string length differences).
//    int drift = 0;
//    if(strlen(replaceWith) > strlen(testStr)) {
//        drift = strlen(replaceWith) - strlen(testStr);
//    }
// TODO: account for index drift
    if (strlen(testStr) != strlen(replaceWith)) {
        fprintf(stderr, "Error: Correction for mismatched string length not implemented.\n");
        exit(1);
    }

    int idx = 0;
    while (allIndexes[idx] != -1) {
        for (int i = 0; i < strlen(replaceWith); i++) {
            src[allIndexes[idx] + i] = replaceWith[i];
        }

        idx++;
    }

    free(allIndexes);
}

// need to refactor this into a util header file available across all of lab11
// problem is.. dunno how.
size_t strlen(const char *str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

