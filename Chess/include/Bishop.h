#pragma once
#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <string>

class Bishop : public Piece {
public:
    Bishop(int startX, const std::string& startY, bool isWhite);

    int canMove(int newX, const std::string& newY, const Board& board) const override;
    char getType() const override;
};

#endif // BISHOP_H