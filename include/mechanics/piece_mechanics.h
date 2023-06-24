#pragma once

#include <stdbool.h>

#define IN_RANGE(VAR, A, B) (VAR >= A && VAR <= B)

// converts any black piece to a white piece
#define TO_WHITE(PIECE) (PIECE += 6)

typedef enum pieces
{
  NP, // no piece
  BP,
  BR,
  BN,
  BB,
  BQ,
  BK,
  WP,
  WR,
  WN,
  WB,
  WQ,
  WK,
} pieces;

typedef struct Coordinate
{
  char x;
  char y;
} Coordinate;

typedef enum piece_type
{
  WHITE = 1,
  BLACK = -1,
  NO_PIECE = 0,
} piece_type;
// the number assignments are so you can cast to a bool
// and use the ! operator to convert BLACK to WHITE and vice versa

typedef enum movePieceReturn
{
  move_invalidInput,
  noPiece,
  wrongTeam,
  invalidPieceMove,
  move_success,
  kingDanger,
} movePieceReturn;

piece_type findPieceType(const pieces piece);

movePieceReturn movePawn(pieces *const startPiece, pieces *const endPiece,
                         const Coordinate startCoordinate, const Coordinate endCoordinate);
movePieceReturn moveRook(pieces *const startPiece, pieces *const endPiece,
                         const Coordinate startCoordinate, const Coordinate endCoordinate);
movePieceReturn moveBishop(pieces *const startPiece, pieces *const endPiece,
                           const Coordinate startCoordinate, const Coordinate endCoordinate);
movePieceReturn moveKnight(pieces *const startPiece, pieces *const endPiece,
                           const Coordinate startCoordinate, const Coordinate endCoordinate);
bool kingCheck(piece_type kingColor); // checks if the king is in check
movePieceReturn executeMove(pieces *const startPiece, pieces *const endPiece);