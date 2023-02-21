#include <stdio.h>

int isDivisibleByNine(int num);

int main(void) {
    int num;
    printf("IS IT DIVISIBLE BY 9\n");
    printf("Enter a positive number: ");
    scanf("%i", &num);

    int divisibleByNine = isDivisibleByNine(num);
    if(divisibleByNine == 1) {
        printf("%i IS divisible by 9.\n", num);
    } else {
        printf("%i IS NOT divisible by 9.\n", num);
    }
}

int isDivisibleByNine(int num) {
    int sum = 0;

    /*********************
     * ================= *
     * THIS BREAKS CLION *
     * ================= *
     ********************/
     // NORMAL TERMINAL WORKS FINE!
    while(num != 0) {
        // get the right-most digit and add it to the sum
        int rightMost = num % 10;
        sum += rightMost;

        // discard the right-most digit
        num = num / 10;
    }

    if(sum % 9 == 0) {
        return 1;
    } else {
        return 0;
    }
}