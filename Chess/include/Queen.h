#pragma once
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include <string>

class Queen : public Piece {
public:
    Queen(int startX, const std::string& startY, bool isWhite);

    int canMove(int newX, const std::string& newY, const Board& board) const override;
    char getType() const override;
};

#endif // QUEEN_H