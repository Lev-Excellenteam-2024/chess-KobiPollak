#include "Rook.h"
#include "Board.h"

Rook::Rook(int startX, const std::string& startY, bool isWhite) : Piece(startX, startY, isWhite) {}

int Rook::canMove(int newX, const std::string& newY, const Board& board) const {
    if (x != newX && y != newY) {
        return 21;  // Rook can only move in straight lines
    }
    

    // Check if the path is clear
    int deltaX = (newX > x) ? 1 : (newX < x) ? -1 : 0;
    int deltaY = (newY > y) ? 1 : (newY < y) ? -1 : 0;

    int currentX = x + deltaX;
    char currentY = y[0] + deltaY;

    while (currentX != newX || currentY != newY[0]) {
        if (board.getPiece(currentX, std::string(1, currentY)) != nullptr) {
            return 21;  // Path is blocked
        }

        currentX += deltaX;
        currentY += deltaY;
    }

    // Check if the destination has a piece of the same color
    Piece* destinationPiece = board.getPiece(newX, newY);
    if (destinationPiece != nullptr && destinationPiece->isWhitePiece() == isWhite) {
        return 13;
    }
    
    return 42;
}

char Rook::getType() const {
    return isWhite ? 'R' : 'r';  // 'R' for white rook, 'r' for black rook
}