#include "render.h"
#include "mechanics/mechanics.h"
#include "global.h"

// default board
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
// for testing pawn promotion
// pieces board[BOARD_SIZE_Y][BOARD_SIZE_X] = {
//     {BR, BN, BB, BQ, BK, BB, BN, BR},
//     {BP, BP, BP, BP, BP, BP, BP, BP},
//     {0, 0, WP, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, BP, 0, 0, 0, 0, 0},
//     {WP, WP, WP, WP, WP, WP, WP, WP},
//     {WR, WN, WB, WQ, WK, WB, WN, WR},
// };
// for testing king check
// pieces board[BOARD_SIZE_Y][BOARD_SIZE_X] = {
//     {BR, BN, BB, BQ, BK, BB, BN, BR},
//     {BP, BP, BP, 0, 0, BP, BP, BP},
//     {0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, BP, BP, 0, 0, 0},
//     {0, 0, 0, WP, WP, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0},
//     {WP, WP, WP, 0, 0, WP, WP, WP},
//     {WR, WN, WB, WQ, WK, WB, WN, WR},
// };
Coordinate whiteKingCoor = {4, 7};
Coordinate blackKingCoor = {4, 0};
// might need the two variables below later
// pieces *whiteKingPtr;
// pieces *blackKingPtr;

piece_type activeTurn = WHITE;

int main()
{
  startupMessages();

  renderBoard();
  UserInput formattedInput;
  do
  {
    formattedInput = getUserInput();

    if (formattedInput.charCode != input_success)
      continue;

    movePieceReturn movePieceCode = movePiece(formattedInput.start, formattedInput.end);
    renderMoveOuput(movePieceCode);
  } while (formattedInput.charCode != quit);

  return 0;
}
