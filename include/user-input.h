#pragma once

typedef struct LetterCoordinate
{
  char x;
  char y;
} LetterCoordinate;

typedef enum InputReturn
{
  quit,
  input_invalidInput,
  input_success
} InputReturn;

typedef struct UserInput
{
  InputReturn charCode;
  LetterCoordinate start;
  LetterCoordinate end;
} UserInput;

UserInput getUserInput();