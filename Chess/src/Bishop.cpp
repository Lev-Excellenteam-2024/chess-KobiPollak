#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(int startX, const std::string& startY, bool isWhite) : Piece(startX, startY, isWhite) {}

int Bishop::canMove(int newX, const std::string& newY, const Board& board) const {
    int deltaX = abs(newX - x);
    int deltaY = abs(newY[0] - y[0]);

    // Bishop moves diagonally, so deltaX and deltaY must be equal
    if (deltaX != deltaY) {
        return 21;  // Invalid move for the Bishop
    }

    // Check if the path is clear
    int stepX = (newX > x) ? 1 : -1;
    int stepY = (newY[0] > y[0]) ? 1 : -1;

    int currentX = x + stepX;
    char currentY = y[0] + stepY;

    while (currentX != newX || currentY != newY[0]) {
        if (board.getPiece(currentX, std::string(1, currentY)) != nullptr) {
            return 21;  // Path is blocked
        }

        currentX += stepX;
        currentY += stepY;
    }

    // Check if the destination has a piece of the same color
    Piece* destinationPiece = board.getPiece(newX, newY);
    if (destinationPiece != nullptr && destinationPiece->isWhitePiece() == isWhite) {
        return 13;  // Destination occupied by a piece of the same color
    }

    return 42;  // Valid move
}

char Bishop::getType() const {
    return isWhite ? 'B' : 'b';  // 'B' for white bishop, 'b' for black bishop
}