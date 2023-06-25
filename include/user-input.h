#pragma once

#include "mechanics/piece_mechanics.h"

/// chess Coordinate form where a coordinate like d3 will be separented into an x and y character
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
pieces userSelectPawnPromotion();