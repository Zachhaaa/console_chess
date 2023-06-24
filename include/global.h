#pragma once

#include "mechanics/piece_mechanics.h"

#define BOARD_SIZE_X 8
#define BOARD_SIZE_Y 8

extern pieces board[BOARD_SIZE_Y][BOARD_SIZE_X];
extern piece_type activeTurn;

extern Coordinate whiteKingCoor;
extern Coordinate blackKingCoor;