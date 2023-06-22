#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "mechanics/piece_mechanics.h"
#include "user-input.h"

// note: changing this macro could lead to major bugs
#define POSSIBLE_PAWN_MOVES 4

typedef struct Vector
{
  char x;
  char y;
} Vector;

static bool checkAxis(pieces *start, pieces *end, const char step)
{
  for (start += step; start < end; start += step)
  {
    if (*start != NP)
      return false;
  }
  // the * 2 accounts for countering the start += step in the loop above
  for (start -= step * 2; start > end; start -= step)
  {
    if (*start != NP)
      return false;
  }
  // end == start condition can be ignored
  // beceause where this function is being used
  // it will not be possible for that situation to happen
  // but keep that in mind when using this function
  return true;
}

piece_type findPieceType(const pieces piece)
{
  if (IN_RANGE(piece, BP, BK))
    return BLACK;
  else if (IN_RANGE(piece, WP, WK))
    return WHITE;
  else
    return NO_PIECE;
}

movePieceReturn movePawn(pieces *const startPiece, pieces *const endPiece,
                         const Coordinate startCoordinate, const Coordinate endCoordinate,
                         pieces (*board)[BOARD_SIZE_X])
{
  piece_type startPieceType = findPieceType(*startPiece);
  char operatorModifier = startPieceType == BLACK ? 1 : -1;
  char startRow = startPieceType == BLACK ? 1 : 6;

  Coordinate possiblePawnMoves[POSSIBLE_PAWN_MOVES];
  for (int i = 0; i < POSSIBLE_PAWN_MOVES; i++)
    possiblePawnMoves[i] = startCoordinate;

  if (*(startPiece + operatorModifier * BOARD_SIZE_X * 1) == NP)
  {
    possiblePawnMoves[0].y += operatorModifier;
    if (startCoordinate.y == startRow && *(startPiece + operatorModifier * BOARD_SIZE_X * 2) == NP)
      possiblePawnMoves[1].y += operatorModifier * 2;
  }
  if (startCoordinate.x > 0 && findPieceType(board[startCoordinate.y + operatorModifier][startCoordinate.x - 1]) == !(bool)startPieceType)
  {
    possiblePawnMoves[2].x -= 1;
    possiblePawnMoves[2].y += operatorModifier;
  }
  if (startCoordinate.x < BOARD_SIZE_X - 1 && findPieceType(board[startCoordinate.y + operatorModifier][startCoordinate.x + 1]) == !(bool)startPieceType)
  {
    possiblePawnMoves[3].x += 1;
    possiblePawnMoves[3].y += operatorModifier;
  }
  for (int i = 0; i < POSSIBLE_PAWN_MOVES; i++)
  {
    if (memcmp(&endCoordinate, possiblePawnMoves + i, sizeof(Coordinate)) == 0)
    {
      if (endCoordinate.y == 0 || endCoordinate.y == BOARD_SIZE_Y - 1)
      {
        pieces promotionPiece = userSelectPawnPromotion();
        if (startPieceType == WHITE)
          promotionPiece += 6;
        *endPiece = promotionPiece;
        *startPiece = NP;
        return move_success;
      }
      *endPiece = *startPiece;
      *startPiece = NP;
      return move_success;
    }
  }
  return invalidPieceMove;
}
movePieceReturn moveRook(pieces *const startPiece, pieces *const endPiece,
                         const Coordinate startCoordinate, const Coordinate endCoordinate)
{
  if (
      (startCoordinate.x == endCoordinate.x && checkAxis(startPiece, endPiece, BOARD_SIZE_X)) ||
      (startCoordinate.y == endCoordinate.y && checkAxis(startPiece, endPiece, 1)))
  {
    *endPiece = *startPiece;
    *startPiece = NP;
    return move_success;
  }
  return invalidPieceMove;
}

movePieceReturn moveBishop(pieces *const startPiece, pieces *const endPiece,
                           const Coordinate startCoordinate, const Coordinate endCoordinate)
{
  Vector pieceVector = {endCoordinate.x - startCoordinate.x, endCoordinate.y - startCoordinate.y};
  if (
      (pieceVector.x == pieceVector.y && checkAxis(startPiece, endPiece, BOARD_SIZE_X + 1)) ||
      (-pieceVector.x == pieceVector.y && checkAxis(startPiece, endPiece, BOARD_SIZE_X - 1)))
  {
    *endPiece = *startPiece;
    *startPiece = NP;
    return move_success;
  }
  return invalidPieceMove;
}

movePieceReturn moveKnight(pieces *const startPiece, pieces *const endPiece,
                           const Coordinate startCoordinate, const Coordinate endCoordinate)
{
  Vector knightAbsoluteVec = {abs(endCoordinate.x - startCoordinate.x), abs(endCoordinate.y - startCoordinate.y)};
  if ((knightAbsoluteVec.x == 1 && knightAbsoluteVec.y == 2) || (knightAbsoluteVec.x == 2 && knightAbsoluteVec.y == 1))
  {
    *endPiece = *startPiece;
    *startPiece = NP;
    return move_success;
  }
  return invalidPieceMove;
}