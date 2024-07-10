#include "Queen.h"
#include "Board.h"

Queen::Queen(int startX, const std::string& startY, bool isWhite) : Piece(startX, startY, isWhite) {}

int Queen::canMove(int newX, const std::string& newY, const Board& board) const {
    int deltaX = abs(newX - x);
    int deltaY = abs(newY[0] - y[0]);

    // Queen moves like a Rook or a Bishop
    if (deltaX != 0 && deltaY != 0 && deltaX != deltaY) {
        return 21;  // Invalid move for the Queen
    }

    // Check if the path is clear
    int stepX = (newX > x) ? 1 : (newX < x) ? -1 : 0;
    int stepY = (newY[0] > y[0]) ? 1 : (newY[0] < y[0]) ? -1 : 0;

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

char Queen::getType() const {
    return isWhite ? 'Q' : 'q';  // 'Q' for white queen, 'q' for black queen
}