#include "King.h"
#include "Board.h"

King::King(int startX, const std::string& startY, bool isWhite) : Piece(startX, startY, isWhite) {}

int King::canMove(int newX, const std::string& newY, const Board& board) const {
    int deltaX = abs(newX - x);
    int deltaY = abs(newY[0] - y[0]);

    // King can only move one square in any direction
    if (deltaX <= 1 && deltaY <= 1) {
        // Check if the destination has a piece of the same color
        Piece* destinationPiece = board.getPiece(newX, newY);
        if (destinationPiece == nullptr || destinationPiece->isWhitePiece() != isWhite) {
            return 42;  // Valid move
        }
        else {
            return 13;  // Destination occupied by a piece of the same color
        }
    }

    return 21;  // Invalid move for the King
}

char King::getType() const {
    return isWhite ? 'K' : 'k';  // 'K' for white king, 'k' for black king
}