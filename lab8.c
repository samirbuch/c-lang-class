#include <stdio.h>
#include <stdlib.h>

void letter_grade(int points, char *letter, int *just_missed);

int main(void) {
  int points;
  printf("How many points did you get? ");
  scanf("%i", &points);

  char letter;
  int just_missed;

  letter_grade(points, &letter, &just_missed);

  printf("You got: %c! ", letter);
  if (just_missed == 1) {
    printf("You missed %c by just one point! Better luck next time 🤞", letter - 1);
  }
  printf("\n");
}

// Why can't we use structs?
void letter_grade(int points, char *letter, int *just_missed) {
  if(points < 0) {
    fprintf(stderr, "Points passed was less than zero.");
    exit(1);
  }

  if(points == 89 || points == 79 || points == 69 || points == 59) {
    *just_missed = 1;
  } else {
    *just_missed = 0;
  }

  if(points >= 90 && points <= 100) {
    *letter = 'A';
  } else if (points >= 80 && points <= 89) {
    *letter = 'B';
  } else if (points >= 70 && points <= 79) {
    *letter = 'C';
  } else if (points >= 60 && points <= 69) {
    *letter = 'D';
  } else {
    *letter = 'F';
  }
}