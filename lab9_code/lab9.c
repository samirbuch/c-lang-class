#include <stdio.h>

int main(void) {
  FILE *examData;
  FILE *examReport;

  // Opening file in reading mode
  examData = fopen("/mnt/c/Users/samir/Documents/c-lang-class/lab9_code/examdata.txt", "r");
  if (examData == NULL) {
    fprintf(stderr, "Read file could not be opened \n");
    return -1;
  }

  examReport = fopen("/mnt/c/Users/samir/Documents/c-lang-class/lab9_code/results.txt", "w");
  if (examReport == NULL) {
    fprintf(stderr, "Write file could not be opened \n");
    return -1;
  }

  // Thanks! https://github.com/Back-Gammon/Lab-9/blob/main/The%20lab
  // Licensed under MIT, I can use it 😛
  int numOfQuestions;
  fscanf(examData, "%d", &numOfQuestions);

  char _space;
  fscanf(examData, "%c", &_space);

  char correctAnswers[numOfQuestions];
  int i = 0;
  while (i < numOfQuestions) {
    fscanf(examData, "%c", &correctAnswers[i]);
    i += 1;
  }

  char _newline;
  fscanf(examData, "%c", &_newline);

  fprintf(examReport, "\tExam Report \n");
  fprintf(examReport, "Question ");
  i = 1;
  while (i <= numOfQuestions) {
    fprintf(examReport, "%d ", i);
    i++;
  }
  fprintf(examReport, "\n");
  fprintf(examReport, "Answers  ");
  i = 0;
  while (i < numOfQuestions) {
    fprintf(examReport, "%c ", correctAnswers[i]);
    i += 1;
  }
  fprintf(examReport, "\n\nID: Score\n");
  char userAnswers[numOfQuestions];
  while (1) {
    int studentID;
    // scan in the user id
    fscanf(examData, "%d", &studentID);
    printf("studentID: %i\n", studentID);
    // scan in the space
    fscanf(examData, "%c", &_space);
    // scan the user's answers into the userAnswers array
    i = 0;

    while (i < numOfQuestions) {
      fscanf(examData, "%c", &userAnswers[i]);
      i++;
    }
    // iterate through the userAnswers array and compare each answer to the answers stored
    // in correctAnswers to get the number of correct answers
    int userCorrectAnswers = 0;
    for (int i = 0; i < numOfQuestions; i++) {
      if (userAnswers[i] == correctAnswers[i]) {
        userCorrectAnswers++;
      }
    }
    // compute the score and write to the file, along with a newline character
    float userScore = 100 * ((float) userCorrectAnswers / numOfQuestions);
    fprintf(examReport, "%d: %.0f%%\n", studentID, userScore);
    char _newlineOrEOF;
    _newlineOrEOF = (char) fgetc(examData);
    if (_newlineOrEOF == EOF) {
      break;
    }
  }

  fclose(examData);
  fclose(examReport);
  return 0;
}