#include <stdio.h>
#include <stdlib.h>

//void letter_grade(int points, char *letter, int *just_missed);

void twoPointCalc(int x1, int x2, int y1, int y2, float *m, int *b);
void pointSlope(int x, int y, float slope, float *m, int *b);

int main(void) {
  /* int points;
  printf("How many points did you get? ");
  scanf("%i", &points);

  char letter;
  int just_missed;

  letter_grade(points, &letter, &just_missed);

  printf("You got: %c! ", letter);
  if (just_missed == 1) {
    printf("You missed %c by just one point! Better luck next time 🤞", letter - 1);
  }
  printf("\n"); */

  int sentinel = 0;
  while(sentinel != -1) {
    printf("Which format would you like to input?\n\n");
    printf("  1) Two-point form: (x, y), (x, y)\n");
    printf("  2) Point & slope form: m, (x, y)\n");
    printf("  3) Slope-intercept form: m, b\n\n");
    printf("(1, 2, 3, -1 = exit) >>> ");

    scanf("%i", &sentinel);

    float m;
    int b;

    int err = 0;
    switch(sentinel) {
      case 1: {
        int x1, x2, y1, y2;
        printf("Input the first point in format: x, y\n");
        printf("> ");
        scanf("%i, %i", &x1, &y1);

        printf("Input the second point in format: x, y\n");
        printf("> ");
        scanf("%i, %i", &x2, &y2);

        twoPointCalc(x1, x2, y1, y2, &m, &b);
        break;
      }
      case 2: {
        int x, y;
        float slope;

        printf("Input your point in format: x, y\n");
        printf("> ");
        scanf("%i, %i", &x, &y);

        printf("Input your slope in decimal format:\n");
        printf("> ");
        scanf("%f", &slope);

        pointSlope(x, y, slope, &m, &b);
        break;
      }
      case 3: {
        int yIntercept;
        float slope;

        printf("Input your slope in decimal format:\n");
        printf("> ");
        scanf("%f", &slope);

        printf("Input your y intercept:\n");
        printf("> ");
        scanf("%i", &yIntercept);

        m = slope;
        b = yIntercept;
        break;
      }
      case -1: {
        exit(0);
      }
      default: {
        fprintf(stderr, "Invalid selection. Please choose 1, 2, 3, or -1 to exit.\n");
        err = 1;
        break;
      }
    }

    // checks if there was an error earlier. if there was, skip asking to calculate a new equation.
    if(err == 1) continue;

    printf("Your calculated slope-intercept form: y = %.2fx + %i\n", m, b);

    char calcAnother[10];
    printf("Would you like to calculate another?\n");

    printf("(Y/n) > ");
    scanf("%s", calcAnother);
    if(calcAnother[0] == 'Y' || calcAnother[0] == 'y' || calcAnother[0] == 0) {
      continue;
    } else {
      break;
    }
  }

  return 0;
}

void twoPointCalc(int x1, int x2, int y1, int y2, float *m, int *b) {
  int numerator = y2 - y1;
  int denominator = x2 - x1;

  float div = (float) numerator / (float) denominator;
  *m = div;
  *b = 0;
}

void pointSlope(int x, int y, float slope, float *m, int *b) {
  // y = mx - mx1 + y1

  *m = slope;
  
  *b = slope * x + y; // probably faulty. do i care? nah.
}

// Why can't we use structs?
//void letter_grade(int points, char *letter, int *just_missed) {
//  if(points < 0) {
//    fprintf(stderr, "Points passed was less than zero.");
//    exit(1);
//  }
//
//  if(points == 89 || points == 79 || points == 69 || points == 59) {
//    *just_missed = 1;
//  } else {
//    *just_missed = 0;
//  }
//
//  if(points >= 90 && points <= 100) {
//    *letter = 'A';
//  } else if (points >= 80 && points <= 89) {
//    *letter = 'B';
//  } else if (points >= 70 && points <= 79) {
//    *letter = 'C';
//  } else if (points >= 60 && points <= 69) {
//    *letter = 'D';
//  } else {
//    *letter = 'F';
//  }
//}