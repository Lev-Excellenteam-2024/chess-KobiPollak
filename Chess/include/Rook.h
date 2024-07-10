#pragma once
#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"



class Rook : public Piece {
public:
    Rook(int startX, const std::string& startY, bool isWhite);
    int canMove(int newX, const std::string& newY, const Board& board) const override;
    char getType() const override;
};

#endif //#ROOK_H