#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// https://stackoverflow.com/a/9653083/8916706
// Result of a quadratic equation computation
struct quadraticResult
{
  int isComplex; // 0 = not complex, 1 = complex
  double x1;
  double x2;
  double complexPortion;
};

struct quadraticResult factorPolynomial(int a, int b, int c);

int main(void)
{

  int largestNum = 0;
  int smallestNum = 0;
  // average calculations
  int avgAdded = 0;
  int avgCount = 0;
  float avg;

  while (1)
  { // always loop. we add an exit check *inside* the loop.
    int num;
    printf("Input a number greater than zero, or -1 to exit: ");
    scanf("%i", &num);

    if (num == -1)
    {
      printf("Exiting... \n");
      break;
    }

    if (num <= 0)
    {
      printf("Number must be greater than zero.\n");
      continue;
    }

    if (smallestNum == 0)
    {
      smallestNum = num; // first-time-run check.
    }

    if (num > largestNum)
    {
      largestNum = num;
    }
    if (num < smallestNum)
    {
      smallestNum = num;
    }

    avgAdded += num;
    avgCount++;
    avg = (float)avgAdded / (float)avgCount;

    printf("Current values:\n\t* Highest Number: %i\n\t* Lowest Number: %i\n\t* Average: %0.3f\n\n", largestNum, smallestNum, avg);
  }

  while (1)
  {
    int a, b, c;
    printf("Solving a quadratic equation: ax² ± bx ± c\n");
    printf("Input a: ");
    scanf("%i", &a);
    printf("Input b: ");
    scanf("%i", &b);
    printf("Input c: ");
    scanf("%i", &c);
    // this would be a lot easier if C supported regex natively. 🙄

    struct quadraticResult result = factorPolynomial(a, b, c);
    if (result.isComplex == 1)
    {
      printf("Result:\n* x1 = %.5f + %.5fi\n* x2 = %.5f - %.5fi\n",
             result.x1, result.complexPortion, result.x2, result.complexPortion);
    }
    else
    {
      printf("Result:\n* x1 = %.5f\n* x2 = %.5f\n", result.x1, result.x2);
    }

    int yesOrNo;
    printf("Would you like to solve another equation? [1/0] ");
    scanf("%i", &yesOrNo);
    if(yesOrNo == 1) {
      continue;
    } else if (yesOrNo == 0) {
      printf("Exiting...\n");
      break;
    }
  }

  return 0;
}

// This function returns a struct with data in it
struct quadraticResult factorPolynomial(int a, int b, int c)
{

  int isComplex = 0;
  double x1;
  double x2;

  int discriminant = pow(b, 2) - (4 * a * c);

  if (discriminant < 0) // Imaginary
  {
    isComplex = 1;
    discriminant = abs(discriminant);

    double complexPortion = sqrt(discriminant) / (2 * a);

    x1 = (-1 * (double)b) / (2 * (double)a); // coersion fuckery
    x2 = x1;

    struct quadraticResult result = {isComplex, x1, x2, complexPortion};
    return result;
  }
  else
  {
    // I tried to separate them out into their own fractions,
    // but for whatever reason the math was not mathing. So I choose
    // to do this instead. In my head, this is actually easier to
    // track.
    int posNumerator = (-1 * b) + sqrt(discriminant);
    int negNumerator = (-1 * b) - sqrt(discriminant);

    x1 = posNumerator / (2 * a);
    x2 = negNumerator / (2 * a);

    struct quadraticResult result = {isComplex, x1, x2, 0.0};
    return result;
  }
}
