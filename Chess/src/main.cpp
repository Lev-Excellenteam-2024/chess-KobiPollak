// Chess 
#include "Chess.h"
#include "Board.h"

int main()
{
	int canMove;
	//string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"; 
	string board = "#B###Q####K###b#####q####k###B########R###R#############r#r#####";
	/*string board = "####b#####K#############q#############B###R#####Q#######r#r#####";*/
	Chess a(board);
	Board bor(board);
	int codeResponse = 0;
	string res = a.getInput();
	while (res != "exit")
	{
		/* 
		codeResponse value : 
		Illegal movements : 
		11 - there is not piece at the source  
		12 - the piece in the source is piece of your opponent
		13 - there one of your pieces at the destination 
		21 - illegal movement of that piece 
		31 - this movement will cause you checkmate

		legal movements : 
		41 - the last movement was legal and cause check 
		42 - the last movement was legal, next turn 
		*/

		/**/ 
		{ // put your code here instead that code
			/*cout << "code response >> ";
			cin >> codeResponse;*/
			int startX, endX;
			std::string startY, endY;
			startY = res.substr(0, 1);
			startX = res[1] - '0';
			endY = res.substr(2, 1);
			endX = res[3] - '0';
			canMove = bor.movePiece(startX, startY, endX, endY, a.m_turn);
			
		}
		/**/

		a.setCodeResponse(canMove);
		//a.setCodeResponse(codeResponse);
		res = a.getInput(); 
	}

	cout << endl << "Exiting " << endl; 
	return 0;
}