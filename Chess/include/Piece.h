#pragma once
#include<string>

class Board;

class Piece {
protected:
	std::string y;
	int x;
	bool isWhite;

public:
	Piece(int startX, std::string startY, bool player) : x(startX), y(startY), isWhite(player) {};

	virtual int canMove(int newX, const std::string& newY, const Board& board) const = 0;

	void setPosition(int newX, const std::string& newY) {
		x = newX;
		y = newY;
	}

	int getX() const { return x; }
	std::string getY() const { return y; }
	bool isWhitePiece() const { return isWhite; }
	virtual char getType() const = 0;

};