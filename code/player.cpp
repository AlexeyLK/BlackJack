#include "deck.h"
#include "player.h"

void player::takeCard(deck cards) {
	int card = cards.randomCard() - 1;
	if (card == -1) card ++;
	vector<string> copyCards = cards.getDECK();
	this->smCards.push_back(copyCards[card]);
	
	copyCards.clear();
}

void player::setCheckSum(string card) {
	if (card == "K_H" || card == "K_S" || card == "K_C" || card == "K_D" ||
		card == "Q_H" || card == "Q_S" || card == "Q_C" || card == "Q_D" ||
		card == "J_H" || card == "J_S" || card == "J_C" || card == "J_D" ||
		card == "10_H" || card == "10_S" || card == "10_C" || card == "10_D") this->checkSum += 10;

	if (card == "9_H" || card == "9_S" || card == "9_C" || card == "9_D") this->checkSum += 9;
	if (card == "8_H" || card == "8_S" || card == "8_C" || card == "8_D") this->checkSum += 8;
	if (card == "7_H" || card == "7_S" || card == "7_C" || card == "7_D") this->checkSum += 7;
	if (card == "6_H" || card == "6_S" || card == "6_C" || card == "6_D") this->checkSum += 6;
	if (card == "5_H" || card == "5_S" || card == "5_C" || card == "5_D") this->checkSum += 5;
	if (card == "4_H" || card == "4_S" || card == "4_C" || card == "4_D") this->checkSum += 4;
	if (card == "3_H" || card == "3_S" || card == "3_C" || card == "3_D") this->checkSum += 3;
	if (card == "2_H" || card == "2_S" || card == "2_C" || card == "2_D") this->checkSum += 2;
	if (card == "A_H" || card == "A_S" || card == "A_C" || card == "A_D") this->checkSum += 11;
	
}