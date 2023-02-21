#include <stdio.h>

int isDivisibleByNine(int num);
float estimatePi(int numIterations);

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

    int numIterations;
    printf("ESTIMATE PI\n");
    printf("Enter number of iterations: ");
    scanf("%i", &numIterations);

    float estimatedPi = estimatePi(numIterations);
    printf("Estimated PI is %.6f\n", estimatedPi);
}

float estimatePi(int numIterations) {
    float sum = 0.0;

    int isEven = 1;
    for(int i = 1; i < numIterations * 2 + 1; i += 2) {
        if(isEven == 1) {
            sum += 1.0 / (float) i;
            isEven = 0;
        } else {
            sum += -1.0 * (1.0 / (float) i);
            isEven = 1;
        }

    }

    return sum * 4;
}

int isDivisibleByNine(int num) {
    int sum = 0;

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