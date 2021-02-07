#include "deck.h"

void deck::setDECK() {
	vector<string> DECK;

	
	
	DECK.push_back("A_H");
	DECK.push_back("A_S");
	DECK.push_back("A_C");
	DECK.push_back("A_D");
	
	DECK.push_back("K_H");
	DECK.push_back("K_S");
	DECK.push_back("K_C");
	DECK.push_back("K_D");

	DECK.push_back("Q_H");
	DECK.push_back("Q_S");
	DECK.push_back("Q_C");
	DECK.push_back("Q_D");




	
	DECK.push_back("J_H");
	DECK.push_back("J_S");
	DECK.push_back("J_C");
	DECK.push_back("J_D");

	DECK.push_back("10_H");
	DECK.push_back("10_S");
	DECK.push_back("10_C");
	DECK.push_back("10_D");
	
	DECK.push_back("9_H");
	DECK.push_back("9_S");
	DECK.push_back("9_C");
	DECK.push_back("9_D");

	
	
	DECK.push_back("8_H");
	DECK.push_back("8_S");
	DECK.push_back("8_C");
	DECK.push_back("8_D");

	DECK.push_back("7_H");
	DECK.push_back("7_S");
	DECK.push_back("7_C");
	DECK.push_back("7_D");

	DECK.push_back("6_H");
	DECK.push_back("6_S");
	DECK.push_back("6_C");
	DECK.push_back("6_D");

	DECK.push_back("5_H");
	DECK.push_back("5_S");
	DECK.push_back("5_C");
	DECK.push_back("5_D");
	
	DECK.push_back("4_H");
	DECK.push_back("4_S");
	DECK.push_back("4_C");
	DECK.push_back("4_D");
	
	DECK.push_back("3_H");
	DECK.push_back("3_S");
	DECK.push_back("3_C");
	DECK.push_back("3_D");

	DECK.push_back("2_H");
	DECK.push_back("2_S");
	DECK.push_back("2_C");
	DECK.push_back("2_D");
	
	this->DECK = DECK;
}

void deck::shuffle() {
	srand(unsigned(time(NULL)));
	random_shuffle(this->DECK.begin(), this->DECK.end());
}

void deck::printDECK() {
	for (int i = 0; i < this->DECK.size(); i++)
		cout << this->DECK[i] << endl;
}

int deck::randomCard() {
	
	int x = rand();
	int y = x % (this->DECK.size()) + 1;
	return y;
}

void deck::delCard(string card) {
	for (int i = 0; i < this->DECK.size(); i++) {
		if (this->DECK[i] == card) {
			this->DECK.erase(this->DECK.begin() + i);
		}
	}
}