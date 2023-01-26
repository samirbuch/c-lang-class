#include <stdio.h>
#include <math.h>

int denominations[] = { 2000, 1000, 500, 100, 25, 10, 5, 1 };

int main(void) {
  float cost = 2.75; // scanf eventually
  float input = 20.00; // scanf eventually

  if(cost > input) {
    printf("Insufficient input.\n");
    return 1;
  }

  int costInPennies = cost * 100;
  int inputInPennies = input * 100;

  int change = inputInPennies - costInPennies;
  // https://stackoverflow.com/a/10349610
  for(int i = 0; i < (sizeof(denominations) / sizeof(denominations[0])); i++) { 
    int denomination = denominations[i];

    //printf("%i\n", denomination);

    int div = change / denomination;
    change = change % denomination;

    printf("%i: %i. Remaining change: %.2f\n", denomination / 100, div, (float) change / 100);

    if(change == 0) {
      break;
    }
  }
}