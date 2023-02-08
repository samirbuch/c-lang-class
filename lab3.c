#include <stdio.h>
#include <math.h>

float calculateMonthlyPayment(float principle, float monthlyInterest, int numPayments);

int main(void) {
    printf("\tCALCULATE LOAN PAYMENT\n");

    float costOfCar;
    printf("Enter the cost of the car: ");
    scanf("%f", &costOfCar);

    float downPayment;
    printf("Enter your down payment: ");
    scanf("%f", &downPayment);

    float APR;
    printf("Enter the APR (e.g. 6%% -> 0.06): ");
    scanf("%f", &APR);

    int payments;
    printf("Enter the number of monthly payments: ");
    scanf("%i", &payments);

    float monthlyPayment = calculateMonthlyPayment(costOfCar - downPayment, APR / 12, payments);
    printf("Your monthly payment is: $%.2f", monthlyPayment);

    return 0;
}

float calculateMonthlyPayment(float principle, float monthlyInterest, int numPayments) {
    float numerator = monthlyInterest * powf((1 + monthlyInterest), (float) numPayments);

    float denominator = powf((1 + monthlyInterest), (float) numPayments) - 1;

    float fraction = numerator / denominator;
    float pmt = principle * fraction;

    return pmt;
}