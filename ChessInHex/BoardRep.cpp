#include "BoardRep.h"
#include <vector>
#include <iostream>

using namespace std;
/*
1 = white Pawn
2 = black Pawn
3 = white Rook
4 = black Rook
5 = white Knight
6 = black Knight
7 = white Bishop
8 = black Bishop
9 = white King
10 = black King
11 = white Queen
12 = black Queen
*/

BoardRep BoardRep::startSetup() {
	BoardRep br;
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	int i4 = 0;
	int i5 = 0;
	int i6 = 0;
	int i7 = 0;
	int i8 = 0;

	for (int i = 0; i < 128; i++) {
		if (16 <= i < 24) {
			br.board[i] = 1;
			pos1.push_back(i);
		}
		else {
			if (96 <= i < 104) {
				br.board[i] = 2;
				pos2.push_back(i);
			}
			else {
				if (i == 0 || i == 7) {
					br.board[i] = 3;
					pos3.push_back(i);
				}
				else {
					if (i == 112 || i == 119) {
						br.board[i] = 4;
						pos4.push_back(i);
					}
					else {
						if (i == 1 || i == 6) {
							br.board[i] = 5;
							pos5.push_back(i);
						}
						else {
							if (i == 113 || i == 118) {
								br.board[i] = 6;
								pos6.push_back(i);
							}
							else {
								if (i == 2 || i == 5) {
									br.board[i] = 7;
									pos7.push_back(i);
								}
								else {
									if (i == 114 || i == 117) {
										br.board[i] = 8;
										pos8.push_back(i);
									}
									else {
										if (i == 3) {
											br.board[i] = 11;
											pos11.push_back(i);
										}
										else {
											if (i == 4) {
												br.board[i] = 9;
												pos9.push_back(i);
											}
											else {
												if (i == 115) {
													br.board[i] = 12;
													pos12.push_back(i);
												}
												else {
													if (i == 116) {
														br.board[i] = 10;
														pos10.push_back(i);
													}
													else {
														br.board[i] = 0;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	br.unitVal[0] = 0;
	br.unitVal[1] = 100;	// 1 = white Pawn
	br.unitVal[2] = -100;	// 2 = black Pawn
	br.unitVal[3] = 500;	// 3 = white Rook
	br.unitVal[4] = -500;	// 4 = black Rook
	br.unitVal[5] = 300;    // 5 = white Knight
	br.unitVal[6] = -300;	// 6 = black Knight
	br.unitVal[7] = 300;	// 7 = white Bishop
	br.unitVal[8] = -300;	// 8 = black Bishop
	br.unitVal[9] = 10000;	// 9 = white King
	br.unitVal[10] = -10000;	// 10 = black King
	br.unitVal[11] = 900;	// 11 = white Queen
	br.unitVal[12] = -900;	// 12 = black Queen

	return br;
}

int BoardRep::getBoardVal(bool isWhite, const BoardRep br) {
	int res = 0;
	if (isWhite) {
		for (int i = 0; i < 128; i++) {
			res += unitVal[board[i]];
		}
	}
	else {
		for (int i = 0; i < 128; i++) {
			res -= unitVal[board[i]];
		}
	}
	return res;
}

bool checkBounds(int pos) {
	if (0 <= pos < 8 || 16 <= pos < 24 || 32 <= pos < 40 || 48 <= pos < 56 || 64 <= pos < 72 || 80 <= pos < 88 || 96 <= pos < 104 || 112 <= pos < 120) {
		return true;
	}
	else return false;
}

std::vector<Move> BoardRep::getMoves(bool isWhite, const BoardRep br) {
	vector<int> possibleFields;
	vector<Move> resMoves;
	int tempFval;
	int tempPos;
	//Selects spaces with pieces on them, in the corresponding color
	for (int i = 0; i <= 120; i++) {
		if (0 <= i < 8 || 16 <= i < 24 || 32 <= i < 40 || 48 <= i < 56 || 64 <= i < 72 || 80 <= i < 88 || 96 <= i < 104 || 112 <= i < 120) {
			if (isWhite) {
				tempFval = br.board[i];
				if (tempFval == 1 || tempFval == 3 || tempFval == 5 || tempFval == 7 || tempFval == 9 || tempFval == 11) {
					possibleFields.push_back(i);
					if (tempFval == 1) pos1.push_back(i);
					if (tempFval == 3) pos3.push_back(i);
					if (tempFval == 5) pos5.push_back(i);
					if (tempFval == 7) pos7.push_back(i);
					if (tempFval == 9) pos9.push_back(i);
					if (tempFval == 11) pos11.push_back(i);
				}
			}
			else {
				tempFval = br.board[i];
				if (tempFval == 2 || tempFval == 4 || tempFval == 6 || tempFval == 8 || tempFval == 10 || tempFval == 12) {
					possibleFields.push_back(i);
					if (tempFval == 2) pos2.push_back(i);
					if (tempFval == 4) pos4.push_back(i);
					if (tempFval == 6) pos6.push_back(i);
					if (tempFval == 8) pos8.push_back(i);
					if (tempFval == 10) pos10.push_back(i);
					if (tempFval == 12) pos12.push_back(i);
				}
			}
		}
	}

	if (isWhite) {
		// Pawn Moves
		for (int i = 0; i < 8; i++) { // Pawn Moves
			tempPos = pos1[i];
			if (checkBounds(tempPos + 0x10)) {
				resMoves.push_back(Move(tempPos, 0x10));
			}
			if (checkBounds(tempPos + 0x20) && (16 <= tempPos < 24)) {
				resMoves.push_back(Move(tempPos, 0x20));
			}

			tempFval = board[tempPos + 0xf];
			if (checkBounds(tempPos + 0xf) && (tempFval == 2 || tempFval == 4 || tempFval == 6 || tempFval == 8 || tempFval == 10 || tempFval == 12)) {
				resMoves.push_back(Move(tempPos, 0xf));
			}
			tempFval = board[tempPos + 0x11];
			if (checkBounds(tempPos + 0x11) && (tempFval == 2 || tempFval == 4 || tempFval == 6 || tempFval == 8 || tempFval == 10 || tempFval == 12)) {
				resMoves.push_back(Move(tempPos, 0x11));
			}

		} // Pawn Moves
		  // Rook Moves
		for (int i = 0; i < 2; i++) { // Rook moves
			tempPos = pos3[i];
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x10))) {
					resMoves.push_back(Move(tempPos, (j * 0x10)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x01))) {
					resMoves.push_back(Move(tempPos, (j * 0x01)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * -0x10))) {
					resMoves.push_back(Move(tempPos, (j * -0x10)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * -0x01))) {
					resMoves.push_back(Move(tempPos, (j * -0x01)));
				}
				else {
					break;
				}
			}
		} // Rook moves
		  // Knight Moves
		for (int i = 0; i < 2; i++) {
			if (checkBounds(pos5[i] + 0x1F)) resMoves.push_back(Move(pos5[i], 0x1F));
			if (checkBounds(pos5[i] + 0x21)) resMoves.push_back(Move(pos5[i], 0x21));
			if (checkBounds(pos5[i] + 0x0E)) resMoves.push_back(Move(pos5[i], 0x0E));
			if (checkBounds(pos5[i] + 0x12)) resMoves.push_back(Move(pos5[i], 0x12));
			if (checkBounds(pos5[i] - 0x1F)) resMoves.push_back(Move(pos5[i], -0x1F));
			if (checkBounds(pos5[i] - 0x21)) resMoves.push_back(Move(pos5[i], -0x21));
			if (checkBounds(pos5[i] - 0x0E)) resMoves.push_back(Move(pos5[i], -0x0E));
			if (checkBounds(pos5[i] - 0x12)) resMoves.push_back(Move(pos5[i], -0x12));
		}
		// Bishop Moves
		for (int i = 0; i < 2; i++) {
			tempPos = pos7[i];
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x11))) {
					resMoves.push_back(Move(tempPos, (j * 0x11)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0xf))) {
					resMoves.push_back(Move(tempPos, (j * 0xf)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos - (j * 0x11))) {
					resMoves.push_back(Move(tempPos, -(j * 0x11)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos - (j * 0xf))) {
					resMoves.push_back(Move(tempPos, -(j * 0xf)));
				}
				else {
					break;
				}
			}
		}
		// King Moves
		tempPos = pos9[0];
		if (checkBounds(tempPos + 0x1)) resMoves.push_back(Move(tempPos, 0x1));
		if (checkBounds(tempPos - 0x1)) resMoves.push_back(Move(tempPos, -0x1));
		if (checkBounds(tempPos + 0x10)) resMoves.push_back(Move(tempPos, 0x10));
		if (checkBounds(tempPos - 0x10)) resMoves.push_back(Move(tempPos, -0x10));
		// Queen Moves
		for (int i = 0; i < 9; i++) {
			tempPos = pos11[i];
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x11))) {
					resMoves.push_back(Move(tempPos, (j * 0x11)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0xf))) {
					resMoves.push_back(Move(tempPos, (j * 0xf)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos - (j * 0x11))) {
					resMoves.push_back(Move(tempPos, -(j * 0x11)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos - (j * 0xf))) {
					resMoves.push_back(Move(tempPos, -(j * 0xf)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x1))) {
					resMoves.push_back(Move(tempPos, (j * 0x1)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x10))) {
					resMoves.push_back(Move(tempPos, (j * 0x10)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos - (j * 0x1))) {
					resMoves.push_back(Move(tempPos, -(j * 0x1)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos - (j * 0x10))) {
					resMoves.push_back(Move(tempPos, -(j * 0x10)));
				}
				else {
					break;
				}
			}
		}
	}
	else {
		// Pawn Moves
		for (int i = 0; i < 8; i++) { // Pawn Moves
			tempPos = pos2[i];
			if (checkBounds(tempPos - 0x10)) {
				resMoves.push_back(Move(tempPos, -0x10));
			}
			if (checkBounds(tempPos - 0x20) && (16 <= tempPos < 24)) {
				resMoves.push_back(Move(tempPos, -0x20));
			}
			tempFval = board[tempPos - 0xf];
			if (checkBounds(tempPos - 0xf) && (tempFval == 1 || tempFval == 3 || tempFval == 5 || tempFval == 7 || tempFval == 9 || tempFval == 11)) {
				resMoves.push_back(Move(tempPos, -0xf));
			}
			tempFval = board[tempPos - 0x11];
			if (checkBounds(tempPos - 0x11) && (tempFval == 1 || tempFval == 3 || tempFval == 5 || tempFval == 7 || tempFval == 9 || tempFval == 11)) {
				resMoves.push_back(Move(tempPos, -0x11));
			}
			for (int i = 0; i < 2; i++) { // Rook moves
				tempPos = pos4[i];
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos + (j * 0x10))) {
						resMoves.push_back(Move(tempPos, j * 0x10));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos + (j * 0x01))) {
						resMoves.push_back(Move(tempPos, j * 0x01));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos + (j * -0x10))) {
						resMoves.push_back(Move(tempPos, j * -0x10));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos + (j * -0x01))) {
						resMoves.push_back(Move(tempPos, j * -0x01));
					}
					else {
						break;
					}
				}
			} // Rook moves
			  // Knight Moves
			for (int i = 0; i < 2; i++) {
				if (checkBounds(pos6[i] + 0x1F)) resMoves.push_back(Move(pos6[i], 0x1F));
				if (checkBounds(pos6[i] + 0x21)) resMoves.push_back(Move(pos6[i], 0x21));
				if (checkBounds(pos6[i] + 0x0E)) resMoves.push_back(Move(pos6[i], 0x0E));
				if (checkBounds(pos6[i] + 0x12)) resMoves.push_back(Move(pos6[i], 0x12));
				if (checkBounds(pos6[i] - 0x1F)) resMoves.push_back(Move(pos6[i], -0x1F));
				if (checkBounds(pos6[i] - 0x21)) resMoves.push_back(Move(pos6[i], -0x21));
				if (checkBounds(pos6[i] - 0x0E)) resMoves.push_back(Move(pos6[i], -0x0E));
				if (checkBounds(pos6[i] - 0x12)) resMoves.push_back(Move(pos6[i], -0x12));
			}
			// Bishop Moves
			for (int i = 0; i < 2; i++) {
				tempPos = pos8[i];
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos + (j * 0x11))) {
						resMoves.push_back(Move(tempPos, (j * 0x11)));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos + (j * 0xf))) {
						resMoves.push_back(Move(tempPos, (j * 0xf)));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos - (j * 0x11))) {
						resMoves.push_back(Move(tempPos, -(j * 0x11)));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos - (j * 0xf))) {
						resMoves.push_back(Move(tempPos, -(j * 0xf)));
					}
					else {
						break;
					}
				}
			}
			// King Moves
			tempPos = pos10[0];
			if (checkBounds(tempPos + 0x1)) resMoves.push_back(Move(tempPos, 0x1));
			if (checkBounds(tempPos - 0x1)) resMoves.push_back(Move(tempPos, -0x1));
			if (checkBounds(tempPos + 0x10)) resMoves.push_back(Move(tempPos, 0x10));
			if (checkBounds(tempPos - 0x10)) resMoves.push_back(Move(tempPos, -0x10));
			// Queen Moves
			for (int i = 0; i < 9; i++) {
				tempPos = pos12[i];
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos + (j * 0x11))) {
						resMoves.push_back(Move(tempPos, (j * 0x11)));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos + (j * 0xf))) {
						resMoves.push_back(Move(tempPos, (j * 0xf)));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos - (j * 0x11))) {
						resMoves.push_back(Move(tempPos, -(j * 0x11)));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos - (j * 0xf))) {
						resMoves.push_back(Move(tempPos, -(j * 0xf)));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos + (j * 0x10))) {
						resMoves.push_back(Move(tempPos, j * 0x10));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos + (j * 0x01))) {
						resMoves.push_back(Move(tempPos, j * 0x01));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos + (j * -0x10))) {
						resMoves.push_back(Move(tempPos, j * -0x10));
					}
					else {
						break;
					}
				}
				for (int j = 0; j < 8; j++) {
					if (checkBounds(tempPos + (j * -0x01))) {
						resMoves.push_back(Move(tempPos, j * -0x01));
					}
					else {
						break;
					}
				}
			}
		} // Pawn Moves
		  // Rook Moves
		for (int i = 0; i < 2; i++) { // Rook moves
			tempPos = pos3[i];
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x10))) {
					resMoves.push_back(Move(tempPos, j * 0x10));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x01))) {
					resMoves.push_back(Move(tempPos, j * 0x01));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * -0x10))) {
					resMoves.push_back(Move(tempPos, j * -0x10));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * -0x01))) {
					resMoves.push_back(Move(tempPos, j * -0x01));
				}
				else {
					break;
				}
			}
		} // Rook moves
		  // Knight Moves
		for (int i = 0; i < 2; i++) {
			if (checkBounds(pos5[i] + 0x1F)) resMoves.push_back(Move(pos5[i], 0x1F));
			if (checkBounds(pos5[i] + 0x21)) resMoves.push_back(Move(pos5[i], 0x21));
			if (checkBounds(pos5[i] + 0x0E)) resMoves.push_back(Move(pos5[i], 0x0E));
			if (checkBounds(pos5[i] + 0x12)) resMoves.push_back(Move(pos5[i], 0x12));
			if (checkBounds(pos5[i] - 0x1F)) resMoves.push_back(Move(pos5[i], -0x1F));
			if (checkBounds(pos5[i] - 0x21)) resMoves.push_back(Move(pos5[i], -0x21));
			if (checkBounds(pos5[i] - 0x0E)) resMoves.push_back(Move(pos5[i], -0x0E));
			if (checkBounds(pos5[i] - 0x12)) resMoves.push_back(Move(pos5[i], -0x12));
		}
		// Bishop Moves
		for (int i = 0; i < 2; i++) {
			tempPos = pos7[i];
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x11))) {
					resMoves.push_back(Move(tempPos, (j * 0x11)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0xf))) {
					resMoves.push_back(Move(tempPos, (j * 0xf)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos - (j * 0x11))) {
					resMoves.push_back(Move(tempPos, -(j * 0x11)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos - (j * 0xf))) {
					resMoves.push_back(Move(tempPos, -(j * 0xf)));
				}
				else {
					break;
				}
			}
		}
		// King Moves
		tempPos = pos9[0];
		if (checkBounds(tempPos + 0x1)) resMoves.push_back(Move(tempPos, 0x1));
		if (checkBounds(tempPos - 0x1)) resMoves.push_back(Move(tempPos, -0x1));
		if (checkBounds(tempPos + 0x10)) resMoves.push_back(Move(tempPos, 0x10));
		if (checkBounds(tempPos - 0x10)) resMoves.push_back(Move(tempPos, -0x10));
		// Queen Moves
		for (int i = 0; i < 9; i++) {
			tempPos = pos11[i];
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x11))) {
					resMoves.push_back(Move(tempPos, (j * 0x11)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0xf))) {
					resMoves.push_back(Move(tempPos, (j * 0xf)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos - (j * 0x11))) {
					resMoves.push_back(Move(tempPos, -(j * 0x11)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos - (j * 0xf))) {
					resMoves.push_back(Move(tempPos, -(j * 0xf)));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x10))) {
					resMoves.push_back(Move(tempPos, j * 0x10));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x01))) {
					resMoves.push_back(Move(tempPos, j * 0x01));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * -0x10))) {
					resMoves.push_back(Move(tempPos, j * -0x10));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * -0x01))) {
					resMoves.push_back(Move(tempPos, j * -0x01));
				}
				else {
					break;
				}
			}
		}
	}
}


