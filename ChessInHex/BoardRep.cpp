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
			pos1[i1] = i;
			i1++;
		}
		else {
			if (96 <= i < 104) {
				br.board[i] = 2;
				pos2[i2] = i;
				i2++;
			}
			else {
				if (i == 0 || i == 7) {
					br.board[i] = 3;
					pos3[i3] = i;
					i3++;
				}
				else {
					if (i == 112 || i == 119) {
						br.board[i] = 4;
						pos4[i4] = i;
						i4++;
					}
					else {
						if (i == 1 || i == 6) {
							br.board[i] = 5;
							pos5[i5] = i;
							i5++;
						}
						else {
							if (i == 113 || i == 118) {
								br.board[i] = 6;
								pos6[i6] = i;
								i6++;
							}
							else {
								if (i == 2 || i == 5) {
									br.board[i] = 7;
									pos7[i7] = i;
									i7++;
								}
								else {
									if (i == 114 || i == 117) {
										br.board[i] = 8;
										pos8[i8] = i;
										i8++;
									}
									else {
										if (i == 3) {
											br.board[i] = 11;
										}
										else {
											if (i == 4) {
												br.board[i] = 9;
											}
											else {
												if (i == 115) {
													br.board[i] = 12;
												}
												else {
													if (i == 116) {
														br.board[i] = 10;
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

std::vector<int> BoardRep::getMoves(bool isWhite, const BoardRep br) {
	vector<int> possibleFields;
	vector<int> resMoves;
	int tempFval;
	int tempPos;
	for (int i = 0; i <= 120; i++) {
		if (0 <= i < 8 || 16 <= i < 24 || 32 <= i < 40 || 48 <= i < 56 || 64 <= i < 72 || 80 <= i < 88 || 96 <= i < 104 || 112 <= i < 120) {
			if (isWhite) {
				tempFval = br.board[i];
				if (tempFval == 0 || tempFval == 2 || tempFval == 4 || tempFval == 6 || tempFval == 8 || tempFval == 10 || tempFval == 12) {
					possibleFields.push_back(i);
				}
			}
			else {
				tempFval = br.board[i];
				if (tempFval == 0 || tempFval == 1 || tempFval == 3 || tempFval == 5 || tempFval == 7 || tempFval == 9 || tempFval == 11) {
					possibleFields.push_back(i);
				}
			}
		}
	}

	if (isWhite) {
		// Pawn Moves
		for (int i = 0; i < 8; i++) { // Pawn Moves
			tempPos = pos1[i];
			if (checkBounds(tempPos + 0x10)) {
				resMoves.push_back(tempPos + 0x10);
			}
			if (checkBounds(tempPos + 0x20) && (16 <= tempPos < 24)) {
				resMoves.push_back(tempPos + 0x20);
			}
		} // Pawn Moves
		// Rook Moves
		for (int i = 0; i < 2; i++) { // Rook moves
			tempPos = pos3[i];
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x10))) {
					resMoves.push_back(tempPos + (j * 0x10));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * 0x01))) {
					resMoves.push_back(tempPos + (j * 0x01));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * -0x10))) {
					resMoves.push_back(tempPos + (j * -0x10));
				}
				else {
					break;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (checkBounds(tempPos + (j * -0x01))) {
					resMoves.push_back(tempPos + (j * -0x01));
				}
				else {
					break;
				}
			}
		} // Rook moves
		// Knight Moves
		for (int i = 0; i < 2; i++) {
			if (checkBounds(pos5[i] + 0x1F)) resMoves.push_back(pos5[i] + 0x1F);
			if (checkBounds(pos5[i] + 0x21)) resMoves.push_back(pos5[i] + 0x21);
			if (checkBounds(pos5[i] + 0x0E)) resMoves.push_back(pos5[i] + 0x0E);
			if (checkBounds(pos5[i] + 0x12)) resMoves.push_back(pos5[i] + 0x12);
			if (checkBounds(pos5[i] - 0x1F)) resMoves.push_back(pos5[i] - 0x1F);
			if (checkBounds(pos5[i] - 0x21)) resMoves.push_back(pos5[i] - 0x21);
			if (checkBounds(pos5[i] - 0x0E)) resMoves.push_back(pos5[i] - 0x0E);
			if (checkBounds(pos5[i] - 0x12)) resMoves.push_back(pos5[i] - 0x12);
		}
	}
}
