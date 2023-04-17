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

    int denom = 1;
    float sign = 1.0;

    while(denom <= numIterations) {
        sum += sign/denom;
        sign *= -1;
        denom += 2;
    }

    return sum * 4;
}

int isDivisibleByNine(int num) { // because num % 9 wasn't enough
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