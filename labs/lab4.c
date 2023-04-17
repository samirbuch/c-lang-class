#include <stdio.h>
#include <stdlib.h>

int calculateDayOfYear(int day, int month, int year);
void printSubstance(int temperature);
int withinXPercent(int substanceRef, int userInput, float threshold);

int main(void) {
  int day, month, year;
  printf("Input a date (format: MM/DD/YYYY): ");
  scanf("%i/%i/%i", &month, &day, &year);

  int dayOfYear = calculateDayOfYear(day, month, year);
  printf("Your day of the year: %i\n", dayOfYear);

  int temperature;
  printf("Enter a temperature to check the substance of: ");
  scanf("%i", &temperature);

  printSubstance(temperature);

  return 0;
}

// gross.
// TODO: multiply 31 by num instead of addition. it'll look cleaner.
// there's gotta be another way to do this
int calculateDayOfYear(int day, int month, int year) {
  int dayOfYear = 0;

  /*
    Jan = 31
    Feb = 28, 29
    Mar = 31
    Apr = 30
    May = 31
    Jun = 30
    Jul = 31
    Aug = 31
    Sep = 30
    Oct = 31
    Nov = 30
    Dec = 31
  */

  switch(month) {
    case 1: {
      dayOfYear = 0 + day;
      break;
    }
    case 2: {
      dayOfYear = 31 + day;
      break;
    }
    case 3: {
      // febuary numbers will be added later
      dayOfYear = 31 + day;
      break;
    }
    case 4: {
      dayOfYear = 31 + 31 + day;
      break;
    }
    case 5: {
      dayOfYear = 31 + 31 + 30 + day;
      break;
    }
    case 6: {
      dayOfYear = 31 + 31 + 30 + 31 + day;
      break;
    }
    case 7: {
      dayOfYear = 31 + 31 + 30 + 31 + 30 + day;
      break;
    }
    case 8: {
      dayOfYear = 31 + 31 + 30 + 31 + 30 + 31 + day;
      break;
    }
    case 9: {
      dayOfYear = 31 + 31 + 30 + 31 + 30 + 31 + 31 + day;
      break;
    }
    case 10: {
      dayOfYear = 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
      break;
    }
    case 11: {
      dayOfYear = 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
      break;
    }
    case 12: {
      dayOfYear = 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
      break;
    }
    default: {
      printf("Invalid month: `%i`. Must be from 1 to 12.\n", month);
      exit(1);
    }
  }

  int isLeapYear = 0;
  if(year % 100 == 0 && year % 400) {
    isLeapYear = 1;
  } else if (year % 4 == 0) {
    isLeapYear = 1;
  } else {
    isLeapYear = 0; // keep it at 0
    // this else block is just for completeness
  }
  if(month > 2) {
    if(isLeapYear == 0) {
      dayOfYear += 28;
    } else {
      dayOfYear += 29;
    }
  }

  return dayOfYear;
}

void printSubstance(int temperature) {

  if(withinXPercent(100, temperature, 0.05) == 1) {
    printf("Substance is Water!\n");
    exit(0);
  } else if(withinXPercent(357, temperature, 0.05) == 1) {
    printf("Substance is Mercury!\n");
    exit(0);
  } else if(withinXPercent(1187, temperature, 0.05) == 1) {
    printf("Substance is Copper!\n");
    exit(0);
  } else if(withinXPercent(2193, temperature, 0.05) == 1) {
    printf("Substance is Silver!\n");
    exit(0);
  } else if(withinXPercent(2660, temperature, 0.05) == 1) {
    printf("Substance is Gold!\n");
    exit(0);
  } else {
    printf("Unknown substance!\n");
    exit(1);
  }
  
}

int withinXPercent(int substanceRef, int userInput, float threshold) {
  float lowBound = substanceRef - (threshold * (float) substanceRef);
  float highBound = substanceRef + (threshold * (float) substanceRef);

  if(userInput >= lowBound && userInput <= highBound) {
    return 1;
  } else {
    return 0;
  }
}
