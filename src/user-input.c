#include <stdio.h>
#include <string.h>
#include "user-input.h"
#include <ctype.h>
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

  fgets(input, INPUT_BUFFER_SIZE, stdin); // fgets also inserts a newline character before the NULL char

  removeWhiteSpace(input);
  tolowerstr(input);

  returnVar.start.x = input[0];
  returnVar.start.y = input[1];
  if (strcmp(input, "quit\n") == 0) // the newline character accounts for the comment above
  {
    printf("quitting...\n");
    returnVar.charCode = quit;
  }
  else if (input[2] == '>')
  {
    returnVar.end.x = input[3];
    returnVar.end.y = input[4];
    returnVar.charCode = input_success;
  }
  else if (input[2] == 't' && input[3] == 'o')
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