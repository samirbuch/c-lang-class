// I used a lot of reference websites on this lab. Pointers, malloc, etc
// were all things I had to look up, mostly so that I could dynamically
// resize the string that accepted the batting.

// Every comment you see that is marked with "// REF:" corresponds to
// a source at the bottom of this code.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isNumber(char c);

int main(void)
{
  FILE *ptr;
  char ch;

  char fileToOpen[] = "batting.txt";
  ptr = fopen(fileToOpen, "r"); // Open the file

  // Initialize the player data
  int playerNumber[2] = {0, 0}; // playerNumber[0] = 10s; playerNumber[1] = 1s
  int atBats = 0;
  int hits = 0;

  if (ptr == NULL)
  {
    fprintf(stderr, "File \"%s\" cannot be opened. Are you sure you spelt it right?\n", fileToOpen);
    return 1;
  }

  while(1)  // always loop! we'll add a break in the loop.
  {
    ch = fgetc(ptr); // REF: [2]

    if ((int)ch == 32)
    {
//      printf("space\n");
      continue; // space. continue to next loop.
    }
    if (ch == '\n' || ch == EOF) // check for newline or EOF, at which point we can exit.
    {

      printf("PLAYER NUMBER: %i\n", playerNumber[0] * 10 + playerNumber[1]);
      printf("* Official at-bats: %i\n", atBats);
      printf("* Hits: %i\n", hits);
      printf("* Batting Average: %.3f\n", (float) hits / (float) atBats);

      if(ch == EOF) {
          break; // STOP THE COUNT
      }

      // Clear the playerNumber data. We're reading a new player.
      playerNumber[0] = 0;
      playerNumber[1] = 0;

      continue;
    }

    if (isNumber(ch) == 1)
    {
      if (playerNumber[1] != 0)
      {
        playerNumber[0] = playerNumber[1];
        playerNumber[1] = atoi(&ch); // REF: [0]
        continue;
      }
      else
      {
        playerNumber[0] = 0;
        playerNumber[1] = atoi(&ch); // REF: [0]
        continue;
      }
    }

    switch (ch) // H, O, W, S, P
    {
        // Hit the ball!
        case 'H':
        {
            hits++;
            atBats++;
            break;
        }
        // Three strikes!
        case 'O':
        {
            atBats++;
            break;
        }
        // Everything else-- walks, sacrifices, hit-by-pitcher-- are ignored.
        default:
        {
            break; // do nothing...
        }
    }

  }

  // C has so many globals.. i'm not used to it.
  // "stderr", "EOF", in most other languages, these are all things
  // you'd have to import or define yourself.

  // close the FD!
  fclose(ptr); // REF: [2]

  return 0;
}

// literally just googled an ASCII table to see what the values of 0-9 are.
int isNumber(char c)
{
    // if the int value of c is between 48 ("0") and 57 ("9"), return true.
    return c >= 48 && c <= 57
             ? 1
             : 0;
  // ✨ ternary operators ✨
  // learned this one from javascript 😌
}

// christ. i honestly would have used dynamic string reallocation but i simply
// do not know how it's done.
// oddly, reading the file is the easier solution to me.

// REFERENCES:
// [0]: https://www.educative.io/answers/how-to-convert-a-string-to-an-integer-in-c
// [1]: https://www.tutorialspoint.com/cprogramming/c_pointers.htm
// [2]: https://templeu.instructure.com/courses/122785/pages/powerpoints-including-sample-codes-from-3-slash-16-slash-23
// [3]: https://www.geeksforgeeks.org/difference-between-malloc-and-calloc-with-examples/
// [4]: https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm
// [5]: https://www.programiz.com/c-programming/library-function/string.h/strcpy
// [6]: https://www.tutorialspoint.com/c_standard_library/c_function_realloc.htm
// [7]: https://stackoverflow.com/questions/8164000/how-to-dynamically-allocate-memory-space-for-a-string-and-get-that-string-from-u