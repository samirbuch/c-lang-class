/* Coding Problems (25 points) */

/*
    Please write code for the two problems below.  Write the code for both
    problems in the area below designated inside of the main function.
    When completed, the main function should run the code for both problems.

    Use floating point arithmetic and print values to two decimal places.

    1. Write code that calculates mileage reimbursement for a salesperson
    at a rate of $0.54 per mile. Your program should get the mileage from
    the user in this manner:

    MILEAGE REIMBURSEMENT CALCULATOR
    Enter beginning odometer reading: <user response>
    Enter ending odometer reading: <user response>
    You traveled <value> miles. At $0.54 per mile, your reimbursement $<value>.

    2. Write code to convert a temperature in degrees Fahrenheit to
    degrees Celsius. The formula is C = (5/9)*(F - 32).  Your program should
    get the temperature Fahrenheit from the user and print the result as:

    FAHRENHEIT TO CELSIUS CALCULATOR
    Enter temperature Fahrenheit: <value>
    <value> degrees Fahrenheit is <value> degrees Celsius
*/

// Preprocessor directives
#include <stdio.h>

// Coding Problem 1
int reimbursementCalculator(int miles) {
    return miles * 0.54;
}

// Coding Problem 2
int farenheitToCelsius(int farenheit) {
    return (farenheit - 32) * (5.0 / 9.0);
    // due to some int-y float-y screwy-ness, we need to do some float
    // operations first before implicitly converting back to an int.
    // grumble grumble type coersion grumble

    // TODO: round this instead of flooring it
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
    if(difference <= 0) {
        printf("You didn't go anywhere. Try again.\n");
        return 1;
    }

    int reimbursement = reimbursementCalculator(difference);

    printf("You traveled %i miles at a rate of $0.54 per mile. Your reimbursement is: $%i.\n\n", difference, reimbursement);

    int farenheit;
    printf("Enter temperature Fahrenheit: ");
    scanf("%i", &farenheit);

    int toCelsius = farenheitToCelsius(farenheit);
    printf("%i degrees Fahrenheit is %i degrees Celsius\n", farenheit, toCelsius);
}
// End main function

/*
    Submit a text file (use the file submission facility in the Canvas Lab
    assignment) with the code for both parts entered as above.  Also, copy
    and paste the output of a successful run as a comment below this one
*/

/* OUTPUT GOES BELOW */
