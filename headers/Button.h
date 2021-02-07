#pragma once
#include "deck.h"
#include "player.h"
#include <SDL.h>

static int countCards = 2;
static int countCardsS = 2;
static int countAplayer = 0;
static int countAstickman = 0;
const int BUTTON_WIDTH = 160;
const int BUTTON_HEIGHT = 160;
const int TOTAL_BUTTONS = 2;


void dwCard_3(string card_up_1, string card_dw_1, string card_dw_2);
void dwCard_4(string card_up_1, string card_dw_1, string card_dw_2, string card_dw_3);
void dwCard_5(string card_up_1, string card_dw_1, string card_dw_2, string card_dw_3, string card_dw_4);
void dwCard_6(string card_up_1, string card_dw_1, string card_dw_2, string card_dw_3, string card_dw_4, string card_dw_5);
void dwCard_7(string card_up_1, string card_dw_1, string card_dw_2, string card_dw_3, string card_dw_4, string card_dw_5, string card_dw_6);
void anCard(string card, int x, int y);

enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

class LButton
{
public:
	//Initializes internal variables
	LButton();

	//Sets top left position
	void setPosition(int x, int y);

	//Handles mouse event
	void handleEvent(SDL_Event* e, player player, deck cards, string card_up_1, string card_up_2, string  card_dw_1, string  card_dw_2, string card_dw_3, char h_s);

	//Shows button sprite
	void render();
	void render2();
private:
	//Top left position
	SDL_Point mPosition;

	//Currently used global sprite
	LButtonSprite mCurrentSprite;
};
