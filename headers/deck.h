#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <time.h>

using namespace std;

class deck {
	vector<string> DECK;

public:

	void setDECK();
	vector<string> getDECK() { return this->DECK; };

	void shuffle();
	void printDECK();
	int randomCard();
	void delCard(string cars);
};
