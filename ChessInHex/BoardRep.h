#include "move.h"
#include <vector>

class BoardRep {
private:
	int board[128];
	std::vector<int> pos1;	//	1 = white Pawn
	std::vector<int> pos2;	//	2 = black Pawn
	std::vector<int> pos3;	//	3 = white Rook
	std::vector<int> pos4;	//	4 = black Rook
	std::vector<int> pos5;	//	5 = white Knight
	std::vector<int> pos6;	//	6 = black Knight
	std::vector<int> pos7;	//	7 = white Bishop
	std::vector<int> pos8;	//	8 = black Bishop
	std::vector<int> pos9;	//	9 = white King
	std::vector<int> pos10;	//	10 = black King
	std::vector<int> pos11;	//	11 = white Queen
	std::vector<int> pos12;	//	12 = black Queen
	int unitVal[7];
public:
	// Variables:

	// Methods:
	BoardRep startSetup();
	BoardRep movePiece(int prev, int post, const BoardRep br);
	int getBoardVal(bool isWhite, const BoardRep br);
	std::vector<Move> getMoves(bool isWhite, const BoardRep br);
};
