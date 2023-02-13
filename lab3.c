#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MATH_E 2.718281827
#define MATH_PI 3.14159265

float calculateMonthlyPayment(float principle, float monthlyInterest, int numPayments);
float gospersFactorial(int num);

int main(void) 
{
    // Simple flags to not run all three exercises in one lab
    int doLoanPayment = 0;
    if (doLoanPayment == 1)
    {
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
    }

    int doFactorial = 0;
    if (doFactorial == 1)
    {
        int num;
        printf("Enter a number to approximate a factorial for: ");
        scanf("%i", &num);

        float factorial = gospersFactorial(num);
        printf("Gosper\'s approximate factorial: %f\n", factorial);
    }

    return 0;
}

float calculateMonthlyPayment(float principle, float monthlyInterest, int numPayments)
{
    float numerator = monthlyInterest * powf((1 + monthlyInterest), (float)numPayments);
    float denominator = powf((1 + monthlyInterest), (float)numPayments) - 1;
    float fraction = numerator / denominator;
    float pmt = principle * fraction;

    return pmt;
}

float gospersFactorial(int num)
{
    if (num < 0)
    {
        printf("Num must not be less than zero.");
        exit(1);
    }

    float factorial = powf((num / MATH_E), (float)num) * sqrtf(MATH_PI * (2.0 * num + (1.0 / 3.0)));
    return factorial;
}