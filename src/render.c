#include <stdio.h>
#include <string.h>
#include "mechanics/piece_mechanics.h"

// this is the width is characters
#define BOARD_UNIT_WIDTH 2

// I know encoding the pieces like this sucks for code readability and
// sustainability, but I wanted to unnecessarily optimize this so here it is
// this coresponds to the order in enum pieces declared in "mechanics.h"
const char pieceEncode[13][BOARD_UNIT_WIDTH] = {
    {' ', ' '},
    {'B', 'P'},
    {'B', 'R'},
    {'B', 'N'},
    {'B', 'B'},
    {'B', 'Q'},
    {'B', 'K'},
    {'W', 'P'},
    {'W', 'R'},
    {'W', 'N'},
    {'W', 'B'},
    {'W', 'Q'},
    {'W', 'K'},
};
void startupMessages()
{
  printf("===============================================================================\n\n");

  printf("\nWelcome to Console Chess!\n\n");

  printf("To play, use the pieces starting coordinate, and followed by \"to\" or \">\"\n");
  printf("followed by the ending coordinate to make a move.\n\n");
  printf("Ex. e2 to e4 or e2 > 24\n\n");

  printf("All whitespaces are ignored. For example:\n");
  printf("e2 to e4 = e2toe4\n");
  printf("e2 > e4 = e2>e4\n\n");

  printf("type \"quit\" to quit the app.\n\n");

  printf("===============================================================================\n\n");
}
void renderBoard(const pieces (*board)[BOARD_SIZE_X])
{

  for (unsigned char y = 0; y < BOARD_SIZE_Y; y += 2)
  {
    char firstLine[] = "==    ==    ==    ==   ";
    char secondLine[] = "   ==    ==    ==    ==";
    for (unsigned char x = 0; x < BOARD_SIZE_X; x++)
    {
      pieces piece;
      if ((piece = board[y][x]) != NP)
        memcpy(firstLine + 3 * x, pieceEncode + piece, BOARD_UNIT_WIDTH);
      if ((piece = board[y + 1][x]) != NP)
        memcpy(secondLine + 3 * x, pieceEncode + piece, BOARD_UNIT_WIDTH);
    }
    printf("%u %s\n", BOARD_SIZE_Y - y, firstLine);
    printf("%u %s\n", BOARD_SIZE_Y - 1 - y, secondLine);
  }
  printf("  a  b  c  d  e  f  g  h \n");
}