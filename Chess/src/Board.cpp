#include "Board.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include <iostream>

std::string Board::getPositionKey(int x, const std::string& y) const {
    return y + std::to_string(x);
}

Board::Board(const std::string& initialState) {
    if (initialState.length() != 64) {
        throw std::invalid_argument("Initial state must be a 64-character string.");
    }

    int index = 0;
    for (char y = 'a'; y <= 'h'; ++y) {
        for (int x = 1; x <= 8; ++x) {
            char pieceChar = initialState[index++];
            bool isWhite = (pieceChar >= 'A' && pieceChar <= 'Z');
            std::string position = getPositionKey(x, std::string(1, y));

            switch (pieceChar) {
            case 'r':
            case 'R':
                board[position] = std::make_unique<Rook>(x, std::string(1, y), isWhite);
                break;
            case 'k':
            case 'K':
                board[position] = std::make_unique<King>(x, std::string(1, y), isWhite);
                break;
            case 'b':
            case 'B':
                board[position] = std::make_unique<Bishop>(x, std::string(1, y), isWhite);
                break;
            case 'q':
            case 'Q':
                board[position] = std::make_unique<Queen>(x, std::string(1, y), isWhite);
                break;
            case '#':
                board[position] = nullptr;
                break;
            default:
                break;  // Empty square
            }
        }
    }
}

Piece* Board::getPiece(int x, const std::string& y) const {
    std::string key = getPositionKey(x, y);
    auto it = board.find(key);
    if (it != board.end()) {
        return it->second.get();
    }
    return nullptr;
}

int Board::movePiece(int startX, const std::string& startY, int endX, const std::string& endY, const bool whiteTurn) {
    Piece* piece = getPiece(startX, startY);
    if (piece == nullptr) {
        return 11;
    }

    if (piece->isWhitePiece() != whiteTurn) {
        return 12;
    }



    int canMove = piece->canMove(endX, endY, *this);
    if (canMove != 42) {
        return canMove;
    }

    //save the piece old location
    Piece* oldPiece = getPiece(endX, endY);
    std::string startKey = getPositionKey(startX, startY);
    std::string endKey = getPositionKey(endX, endY);

    // Move the piece
    piece->setPosition(endX, endY);
    board[endKey] = std::move(board[startKey]);
    //board.erase(startKey);

    // Check if the move puts the current player's king in check
    if (isKingInCheck(whiteTurn)) {
         //Undo the temporary move
        piece->setPosition(startX, startY);
        board[startKey] = std::move(board[endKey]);
       if (oldPiece) {
            board[endKey] = std::unique_ptr<Piece>(oldPiece);
        }
        return 31; // Error code for move putting own king in check
    }
    if (isKingInCheck(!whiteTurn)) {
        return 41;
    }

    return canMove;
}

bool Board::isKingInCheck(bool whiteTurn) const {
    std::string kingPosition;
    for (const auto& [key, piece] : board) {
        if (piece && piece->isWhitePiece() == whiteTurn && (piece->getType() == 'k' || piece->getType() == 'K'))
        {
            kingPosition = key;
            break;
        }
    }
    if (kingPosition.empty()) {
        return false;
    }
    std::string kingY = kingPosition.substr(0, 1);
    int kingX = kingPosition[1] - '0';

    for (const auto& [key, piece] : board) {
        if (piece && piece->isWhitePiece() != whiteTurn && piece->canMove(kingX, kingY, *this) == 42)
        {
            return true;
        }
    }
    return false;
}



//void Board::printBoard() const {
//    for (char y = 'h'; y >= 'a'; --y) {
//        for (int x = 1; x <= 8; ++x) {
//            std::string key = getPositionKey(x, std::string(1, y));
//            if (board.find(key) != board.end()) {
//                std::cout << board.at(key)->getType() << " ";
//            }
//            else {
//                std::cout << ". ";
//            }
//        }
//        std::cout << std::endl;
//    }
//}