#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <time.h>

class player {
	vector<string> smCards;
	int checkSum;

public:


	string printSmCards(int i) {
		return this->smCards[i];
	}

	void setSmCards(string card) { this->smCards.push_back(card); }
	void takeCard(deck cards);

	void setCheckSum(string card);
	int getCheckSum() { return this->checkSum; }
	vector<string> getSmCards() { return this->smCards; }

	void min10() { this->checkSum -= 10; }
	//void checkLose() { if (this->checkSum > 21) cout << "unfortunately you lost (" << endl; }
};