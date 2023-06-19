#pragma once

#include "user-input.h"
#include "mechanics/piece_mechanics.h"

piece_type findPieceType(pieces piece);
movePieceReturn movePiece(const LetterCoordinate start, const LetterCoordinate end, const piece_type activeTurn, pieces (*board)[BOARD_SIZE_X]);