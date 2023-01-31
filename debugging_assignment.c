#include <stdio.h>
/* Set constants = number of pennies in each type of bill or coin */
#define TWENTY 2000 // pennies in $20 and so forth
#define TEN 1000
#define FIVE 500
#define SINGLE 100 // pennies in a dollar
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1 // pennies in a penny

void main(void) {
  int change, // to be paid, in cents
      twenties, tens, fives, singles, quarters, dimes, nickels, pennies;
  // bills and coins used
  double cost,                                   // item cost, in dollars and cents
      paid;                                      // amount paid, in dollars and cents

  // Ask for cost
  printf("Enter amount cost ($): ");
  scanf("%lf", &cost);
  // Ask for amount paid
  printf("Enter amount tendered ($): ");
  scanf("%lf", &paid);

  change = (int)(((paid - cost) * 100.0) + 0.5); // converts change to pennies

  // Calculations
  twenties = (change / TWENTY);
  change = (change % TWENTY);
  tens = (change / TEN);
  change = (change % TEN);
  fives = (change / FIVE);
  change = (change % FIVE);
  singles = (change / SINGLE);
  change = (change % SINGLE);
  // Change list
  printf("Change is: %d\n", change);
  printf("$20 bills: %d\n", twenties);
  printf("$10 bills: %d\n", tens);
  printf("$5 bills: %d\n", fives);
  printf("$1 bills: %d\n", singles);
  printf("Quarters: %d\n", quarters);
  printf("Dimes: %d\n", dimes);
  printf("Nickels: %d\n", nickels);
  printf("Pennies: %d\n", pennies);

}