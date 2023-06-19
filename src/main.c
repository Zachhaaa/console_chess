#include <stdio.h>

#include "render.h"
#include "mechanics/mechanics.h"

int main()
{
  startupMessages();
  pieces board[BOARD_SIZE_Y][BOARD_SIZE_X] = {
      {BR, BN, BB, BQ, BK, BB, BN, BR},
      {BP, BP, BP, BP, BP, BP, BP, BP},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {WP, WP, WP, WP, WP, WP, WP, WP},
      {WR, WN, WB, WQ, WK, WB, WN, WR},
  };
  renderBoard(board);
  UserInput formattedInput;
  piece_type activeTurn = WHITE;
  do
  {
    printf("%s's move:\n", activeTurn == WHITE ? "white" : "black");
    formattedInput = getUserInput();

    if (formattedInput.charCode != input_success)
      continue;

    movePieceReturn movePieceCode = movePiece(formattedInput.start, formattedInput.end, activeTurn, board);
    switch (movePieceCode)
    {
    case move_invalidInput:
      printf("invalid input\n");
      break;

    case noPiece:
      printf("No piece seleted\n");
      break;

    case wrongTeam:
      printf("wrong team's piece\n");
      break;

    case invalidPieceMove:
      printf("invalid piece move\n");
      break;

    case move_success:
      renderBoard(board);
      activeTurn = activeTurn == WHITE ? BLACK : WHITE;
      break;
    }
  } while (formattedInput.charCode != quit);

  return 0;
}