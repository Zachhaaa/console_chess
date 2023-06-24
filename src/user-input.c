#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "user-input.h"
#include "global.h"
#define INPUT_BUFFER_SIZE 16

static inline void tolowerstr(char *str)
{
  for (; *str != '\0'; str++)
    *str = tolower(*str);
}

static inline void removeWhiteSpace(char *str)
{
  unsigned spaceCount = 0;
  for (; *str != '\0'; str += 1)
  {
    if (*str == ' ')
      spaceCount++;
    else
      *(str - spaceCount) = *str;
  }
  *(str - spaceCount) = '\0';
}

UserInput getUserInput()
{
  UserInput returnVar;
  char input[INPUT_BUFFER_SIZE];

  printf("%s's move:\n", activeTurn == WHITE ? "white" : "black");
  fgets(input, INPUT_BUFFER_SIZE, stdin); // fgets also inserts a newline character before the NULL char

  removeWhiteSpace(input);
  tolowerstr(input);

  returnVar.start.x = input[0];
  returnVar.start.y = input[1];
  unsigned char strSize = strlen(input);
  if (strcmp(input, "quit\n") == 0) // the newline character accounts for the comment above
  {
    printf("quitting...\n");
    returnVar.charCode = quit;
  }
  else if (input[2] == '>' && strSize == 6) // 6 because of accounting for the newline
  {
    returnVar.end.x = input[3];
    returnVar.end.y = input[4];
    returnVar.charCode = input_success;
  }
  else if (input[2] == 't' && input[3] == 'o' && strSize == 7) // also accounts for the newline
  {
    returnVar.end.x = input[4];
    returnVar.end.y = input[5];
    returnVar.charCode = input_success;
  }
  else
  {
    printf("invalid input\n");
    returnVar.charCode = input_invalidInput;
  }
  return returnVar;
}
pieces userSelectPawnPromotion()
{
  printf("type either \"queen\", \"rook\", \"bishop\", \"knight\"\n");
  printf("to promote to that piece:\n");
  char input[INPUT_BUFFER_SIZE];
  while (1)
  {
    fgets(input, INPUT_BUFFER_SIZE, stdin);

    removeWhiteSpace(input);
    tolowerstr(input);
    if (strcmp(input, "queen\n") == 0)
      return BQ;
    else if (strcmp(input, "rook\n") == 0)
      return BR;
    else if (strcmp(input, "bishop\n") == 0)
      return BB;
    else if (strcmp(input, "knight\n") == 0)
      return BN;
    else
    {
      printf("invalid option\n");
    }
  }
}