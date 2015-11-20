
#include <vector>

class BoardRep {
private:
	int board[128];
	int pos1[8];	//	1 = white Pawn
	int pos2[8];	//	2 = black Pawn
	int pos3[2];	//	3 = white Rook
	int pos4[2];	//	4 = black Rook
	int pos5[2];	//	5 = white Knight
	int pos6[2];	//	6 = black Knight
	int pos7[2];	//	7 = white Bishop
	int pos8[2];	//	8 = black Bishop
	int pos9[1];	//	9 = white King
	int pos10[1];	//	10 = black King
	int pos11[9];	//	11 = white Queen
	int pos12[9];	//	12 = black Queen
	int unitVal[7];
public:
	// Variables:

	// Methods:
	BoardRep startSetup();
	BoardRep movePiece(int prev, int post, const BoardRep br);
	int getBoardVal(bool isWhite, const BoardRep br);
	std::vector<int> getMoves(bool isWhite, const BoardRep br);
};
