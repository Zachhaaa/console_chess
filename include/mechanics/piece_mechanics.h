#pragma once

#define BOARD_SIZE_X 8
#define BOARD_SIZE_Y 8

#define IN_RANGE(VAR, A, B) (VAR >= A && VAR <= B)

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
  NO_PIECE = -1,
  WHITE = 0,
  BLACK = 1,
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
} movePieceReturn;

piece_type findPieceType(const pieces piece);

movePieceReturn movePawn(pieces *const startPiece, pieces *const endPiece,
                         const Coordinate startCoordinate, const Coordinate endCoordinate,
                         pieces (*board)[BOARD_SIZE_X]);
movePieceReturn moveRook(pieces *const startPiece, pieces *const endPiece,
                         const Coordinate startCoordinate, const Coordinate endCoordinate);
movePieceReturn moveBishop(pieces *const startPiece, pieces *const endPiece,
                           const Coordinate startCoordinate, const Coordinate endCoordinate);
movePieceReturn moveKnight(pieces *const startPiece, pieces *const endPiece,
                           const Coordinate startCoordinate, const Coordinate endCoordinate);