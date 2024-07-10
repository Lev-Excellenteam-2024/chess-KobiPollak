#pragma once
#include "Piece.h"

class King : public Piece {
public:
    King(int startX, const std::string& startY, bool isWhite);
    int canMove(int newX, const std::string& newY, const Board& board) const override;
    char getType() const override;
};
