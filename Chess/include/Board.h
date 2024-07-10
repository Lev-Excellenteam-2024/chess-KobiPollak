#pragma once
#include <unordered_map>
#include <memory>
#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>
#include "Piece.h"
#include "Rook.h"

class Board {
private:
    std::unordered_map<std::string, std::unique_ptr<Piece>> board;

    std::string getPositionKey(int x, const std::string& y) const;

public:
    Board(const std::string& initialState);

    Piece* getPiece(int x, const std::string& y) const;

    int movePiece(int startX, const std::string& startY, int endX, const std::string& endY, const bool whiteTurn);

    bool isKingInCheck(bool whiteTurn) const;

    //void printBoard() const;
};