#include <string.h>
#include <math.h>

#include "mechanics/mechanics.h"
// A B are inclusive

// false means the axis has a piece in the way. true means the axis is clear
// start and end cannot equal each otherwise there will be bugs

movePieceReturn movePiece(const LetterCoordinate start, const LetterCoordinate end, const piece_type activeTurn, pieces (*board)[BOARD_SIZE_X])
{
  Coordinate startCoordinate, endCoordinate;
  startCoordinate.x = start.x - 'a';
  endCoordinate.x = end.x - 'a';
  startCoordinate.y = BOARD_SIZE_Y - (start.y - '0');
  endCoordinate.y = BOARD_SIZE_Y - (end.y - '0');

  if (!(IN_RANGE(startCoordinate.x, 0, BOARD_SIZE_X - 1) &&
        IN_RANGE(startCoordinate.y, 0, BOARD_SIZE_Y - 1) &&
        IN_RANGE(endCoordinate.x, 0, BOARD_SIZE_X - 1) &&
        IN_RANGE(endCoordinate.y, 0, BOARD_SIZE_Y - 1)))
  {
    return move_invalidInput;
  }

  pieces *const startPiece = board[(unsigned)startCoordinate.y] + startCoordinate.x;
  pieces *const endPiece = board[(unsigned)endCoordinate.y] + endCoordinate.x;
  piece_type startPieceType = findPieceType(*startPiece);
  piece_type endPieceType = findPieceType(*endPiece);
  if (startPieceType == NO_PIECE)
    return noPiece;
  // Checks if startPiece matches with the players turn.
  else if (startPieceType != activeTurn || endPieceType == activeTurn)
    return invalidPieceMove;

  // note: changing the size of the array following will lead to bugs
  // also the following block only applies to pawns but I put it here
  // to prevent repition because there are two pawn cases (BP and WP)
  switch (*startPiece)
  {
  case BP:
  case WP:
    return movePawn(startPiece, endPiece, startCoordinate, endCoordinate, board);
    break;

  case BR:
  case WR:
    return moveRook(startPiece, endPiece, startCoordinate, endCoordinate);
    break;

  case BN:
    break;

  case WN:
    break;

  case BB:
  case WB:
    return moveBishop(startPiece, endPiece, startCoordinate, endCoordinate);
    break;

  case BQ:
  case WQ:
    return moveRook(startPiece, endPiece, startCoordinate, endCoordinate) == move_success ||
                   moveBishop(startPiece, endPiece, startCoordinate, endCoordinate) == move_success
               ? move_success
               : invalidPieceMove;
    break;

  case BK:
  case WK:
    if (abs(endCoordinate.x - startCoordinate.x) > 1 && abs(endCoordinate.y - startCoordinate.y) > 1)
      return invalidPieceMove;

    *endPiece = *startPiece;
    *startPiece = NP;
    return move_success;
    break;

  // following is only to remove warnings (if statement implementation above switch)
  case NP:
    break;
  }
  return move_invalidInput;
}
