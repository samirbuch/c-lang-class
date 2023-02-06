/* Coding Problems (25 points) */

/*
    Please write code for the two problems below.  Write the code for both
    problems in the area below designated inside of the main function.
    When completed, the main function should run the code for both problems.

    Use floating point arithmetic and print values to two decimal places.

    1. Write code that calculates mileage reimbursement for a salesperson
    at a rate of $0.655 per mile. Your program should get the mileage from
    the user in this manner:

    MILEAGE REIMBURSEMENT CALCULATOR
    Enter beginning odometer reading: <user response>
    Enter ending odometer reading: <user response>
    You traveled <value> miles. At $0.655 per mile, your reimbursement $<value>.

    2. Write code to convert a temperature in degrees Fahrenheit to
    degrees Celsius. The formula is C = (5/9)*(F - 32).  Your program should
    get the temperature Fahrenheit from the user and print the result as:

    FAHRENHEIT TO CELSIUS CALCULATOR
    Enter temperature Fahrenheit: <value>
    <value> degrees Fahrenheit is <value> degrees Celsius
*/

// Preprocessor directives
#include <stdio.h>
#include <math.h>

// Coding Problem 1
int reimbursementCalculator(int miles) {
    int reimbursement = (int) round((float) miles * 0.655); // bam plus five points :) *
    return reimbursement;

    /* * this took me way too long to figure out. i knew about the round function,
        but for some reason the linker couldn't find it? did a quick google search
        and found out that I need to *tell* the linker to link it. it isn't linked
        automatically via the include.
        $ clang -lm lab2.c -o ./dist/lab2 && ./dist/lab2;
        ---------^^
        source: https://stackoverflow.com/a/39474681
        source: https://stackoverflow.com/a/52030015

        this led me to wonder if auto linking is a thing. looks like it is, but
        it requires a #pragma directive, which is generally not portable by any
        means. dependent on compiler, OS, etc. bad idea.

        upon further investigation, i didn't need this round function. all i needed
        to do was format it in the printf statement, and it would take care of 
        rounding for me.
        oh well! now i know how to link the math lib at least
    */
}

// Coding Problem 2
float farenheitToCelsius(float farenheit) {
    return (farenheit - 32.0) * (5.0 / 9.0);
}

// Main function
int main(void) {

    int beginningOdometer, endingOdometer;

    printf("Enter beginning odometer reading: ");
    scanf("%i", &beginningOdometer);

    printf("Enter ending odometer reading: ");
    scanf("%i", &endingOdometer);

    if(beginningOdometer < 0 || endingOdometer < 0) {
        printf("Your odometer rolled over. Try again.\n");
        return 1;
    }

    int difference = endingOdometer - beginningOdometer;
    int reimbursement = reimbursementCalculator(difference);

    printf("You traveled %i miles at a rate of $0.655 per mile. Your reimbursement is: $%i.\n\n", difference, reimbursement);

    float farenheit;
    printf("Enter temperature Fahrenheit: ");
    scanf("%f", &farenheit);

    /*
        this actually led me to wonder how scanf formats things. i learned that
        it can accept a whole lot more variation than just the type of variable
        you're inputting- length of input, modifier of the type, etc.

        also learned about possible security implications.

        i hope to god i never have to do any serious programming in C.

        source: https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm#
    */

    float toCelsius = farenheitToCelsius(farenheit);
    printf("%.2f degrees Fahrenheit is %.2f degrees Celsius\n", farenheit, toCelsius);
}
// End main function

/*
    Submit a text file (use the file submission facility in the Canvas Lab
    assignment) with the code for both parts entered as above.  Also, copy
    and paste the output of a successful run as a comment below this one
*/

/* OUTPUT GOES BELOW */
