// REFERENCES
// [1]: https://stackoverflow.com/a/10349610/8916706

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getPolynomial(const int *degree, int *polynomialArray, int *constant);
double evaluatePolynomial(const int *degree, const int *polynomialArray, const int *constant, const int *x);

int main(void) {
  int degree;
  printf("What is the degree of this polynomial?\n(What's the highest exponent?)\n> ");
  scanf("%i", &degree);

  if(degree <= 0) {
    fprintf(stderr, "The degree of the polynomial cannot be less than or equal to 0.\n");
    exit(1);
  }

  // The array of equation coefficients, from highest degree to lowest.
  int polynomialArray[degree];
  // When you create an array, C (under the hood) creates a pointer to the first element in the array.
  // So every time you get/set an array value, it just takes the pointer and adds x (arr[x]).

  // Constant at the end of the polynomial
  int constant;

  // The function prototype specifies type int* for the polynomialArray, but we don't have to
  // put the & symbol here to indicate the address of because `polynomialArray` is already
  // technically a pointer ;)
  getPolynomial(&degree, polynomialArray, &constant);

  int x;
  printf("\nNow we'll actually evaluate your polynomial expression.\nWhat should x be?\n> ");
  scanf("%i", &x);

  double result = evaluatePolynomial(&degree, polynomialArray, &constant, &x);
  printf("Your evaluated polynomial: %.1f\n", result);

}

void getPolynomial(const int *degree, int *polynomialArray, int *constant) {
  printf("Great! We have a polynomial of degree %i\n", *degree);

  printf("We're gonna start from the highest-most degree and work backwards.\n\n");

  for(int i = *degree; i > 0; i--) {
    printf("What's the coefficient for the variable raised to the exponent of %i?\n> ", i);
    scanf("%i", &polynomialArray[i]);
  }

  printf("And finally, what is the constant? (ax2 + ax1 + ax + constant)\n> ");
  scanf("%i", constant);

  printf("\nYour completed polynomial:\n");

  // Degree here is being used as the length of the array.
  for(int power = 0; power < *degree - 1; power++) { // - 1 here for pretty formatting
    printf("%ix^%i + ", polynomialArray[abs(power - *degree)], abs(power - *degree));
    // because the polynomialArray is structured so that the highest degree is at the lowest index,
    // we need to actually start from the highest index, which is equal to the array's length.
  }
  printf("%ix^%i + %i\n", polynomialArray[1], 1, *constant); // (the pretty formatting in question)
}

double evaluatePolynomial(const int *degree, const int *polynomialArray, const int *constant, const int *x) {
  double result = 1.0;

  // High to low, again, since polynomialArray has the highest coefficient at its lowest index.
  for(int power = *degree; power > 0; power--) {
    int coefficient = polynomialArray[abs(power - *degree)];
    result += (double) coefficient * pow(*x, power);
  }

  result += (double) *constant;

  return result;
}