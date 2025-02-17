#include "Texture.h"
#include "Button.h"
#include <SDL_image.h>
#include <windows.h>
#include <iostream>
#include <thread> 
using namespace std;

void reg();
void pre_main();
void start();
void register_();
void shop_cards();
void shop_fields();
void achiv();
void main_manu();

bool init();
bool loadMedia();
void close();
void upCard_1();
void upCard_2();
void dwCard_1();
void dwCard_2();
void anRes(string res, int x, int y);
void anCard(string card, int x, int y);
void dwCard_3(string card_up_1, string card_dw_1, string card_dw_2);
void dwCard_4(string card_up_1, string card_dw_1, string card_dw_2, string card_dw_3);
void dwCard_5(string card_up_1, string card_dw_1, string card_dw_2, string card_dw_3, string card_dw_4);
void dwCard_6(string card_up_1, string card_dw_1, string card_dw_2, string card_dw_3, string card_dw_4, string card_dw_5);
void dwCard_7(string card_up_1, string card_dw_1, string card_dw_2, string card_dw_3, string card_dw_4, string card_dw_5, string card_dw_6);
void upCard_3(player player, string card_up_1, string card_up_2);
void upCard_4(player player, string card_up_1, string card_up_2, string card_up_3);
void upCard_5(player player, string card_up_1, string card_up_2, string card_up_3, string card_up_4);
void upCard_6(player player, string card_up_1, string card_up_2, string card_up_3, string card_up_4, string card_up_5);
void upCard_7(player player, string card_up_1, string card_up_2, string card_up_3, string card_up_4, string card_up_5, string card_up_6);
void anCount(int counter, int x, int y);

LButton gButtons[TOTAL_BUTTONS];

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

string res;
int p1 = 0;
int p2 = 0;
int p3 = 0;
int p4 = 0;
int p5 = 0;
int p6 = 0;

int s1 = 0;


int w = 0;
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

//Mouse button sprites
SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];
SDL_Rect gSpriteClips_st[BUTTON_SPRITE_TOTAL];
SDL_Rect gSpriteClipsPrePlay[BUTTON_SPRITE_TOTAL];
SDL_Rect gSpriteClipsRegLog[BUTTON_SPRITE_TOTAL];
SDL_Rect gSpriteClipsBack[BUTTON_SPRITE_TOTAL];
SDL_Rect gSpriteClipsf10[BUTTON_SPRITE_TOTAL];
SDL_Rect gSpriteClipsf25[BUTTON_SPRITE_TOTAL];
SDL_Rect gSpriteClipsf50[BUTTON_SPRITE_TOTAL];
SDL_Rect gSpriteClipsf200[BUTTON_SPRITE_TOTAL];
SDL_Rect gSpriteClipsShop[BUTTON_SPRITE_TOTAL];
SDL_Rect gSpriteClipsAch[BUTTON_SPRITE_TOTAL];
SDL_Rect gSpriteClipsBoards[BUTTON_SPRITE_TOTAL];
SDL_Rect gSpriteClipsCards[BUTTON_SPRITE_TOTAL];



LTexture gButtonSpriteSheetTexture;
LTexture gButtonSpriteSheetTexture2;

LTexture gFooTexture_pre_play;
LTexture gFooTexture_register_login;
LTexture gFooTexture_pre;
LTexture gFooTexture_start;

LTexture gFooTexture_register;

LTexture gFooTexture_shop_cards;
LTexture gFooTexture_shop_fields;
LTexture gFooTexture_achiv;

LTexture gFooTexture_main_menu;
// textures cards
LTexture gFooTexture;
LTexture gFooTexture_4;
LTexture gFooTexture_5;
LTexture gFooTexture_6;
LTexture gFooTexture_7;
LTexture gFooTexture_8;
LTexture gFooTexture_9;
LTexture gFooTexture_10;
LTexture gFooTexture_11;
LTexture gFooTexture_12;
LTexture gFooTexture_13;
LTexture gFooTexture_14;
LTexture gFooTexture_15;
LTexture gFooTexture_16;
LTexture gFooTexture_17;
LTexture gFooTexture_18;
LTexture gFooTexture_19;
LTexture gFooTexture_20;
LTexture gFooTexture_21;
LTexture gFooTexture_22;
LTexture gFooTexture_23;
LTexture gFooTexture_24;
LTexture gFooTexture_25;
LTexture gFooTexture_26;
LTexture gFooTexture_27;
LTexture gFooTexture_28;
LTexture gFooTexture_29;
LTexture gFooTexture_30;

LTexture gFooTexture_2_H;
LTexture gFooTexture_3_H;
LTexture gFooTexture_4_H;
LTexture gFooTexture_5_H;
LTexture gFooTexture_6_H;
LTexture gFooTexture_7_H;
LTexture gFooTexture_8_H;
LTexture gFooTexture_9_H;
LTexture gFooTexture_10_H;
LTexture gFooTexture_J_H;
LTexture gFooTexture_Q_H;
LTexture gFooTexture_K_H;
LTexture gFooTexture_A_H;

LTexture gFooTexture_2_S;
LTexture gFooTexture_3_S;
LTexture gFooTexture_4_S;
LTexture gFooTexture_5_S;
LTexture gFooTexture_6_S;
LTexture gFooTexture_7_S;
LTexture gFooTexture_8_S;
LTexture gFooTexture_9_S;
LTexture gFooTexture_10_S;
LTexture gFooTexture_J_S;
LTexture gFooTexture_Q_S;
LTexture gFooTexture_K_S;
LTexture gFooTexture_A_S;

LTexture gFooTexture_2_C;
LTexture gFooTexture_3_C;
LTexture gFooTexture_4_C;
LTexture gFooTexture_5_C;
LTexture gFooTexture_6_C;
LTexture gFooTexture_7_C;
LTexture gFooTexture_8_C;
LTexture gFooTexture_9_C;
LTexture gFooTexture_10_C;
LTexture gFooTexture_J_C;
LTexture gFooTexture_Q_C;
LTexture gFooTexture_K_C;
LTexture gFooTexture_A_C;

LTexture gFooTexture_2_D;
LTexture gFooTexture_3_D;
LTexture gFooTexture_4_D;
LTexture gFooTexture_5_D;
LTexture gFooTexture_6_D;
LTexture gFooTexture_7_D;
LTexture gFooTexture_8_D;
LTexture gFooTexture_9_D;
LTexture gFooTexture_10_D;
LTexture gFooTexture_J_D;
LTexture gFooTexture_Q_D;
LTexture gFooTexture_K_D;
LTexture gFooTexture_A_D;

LTexture gFooTexture_lose;
LTexture gFooTexture_won;

LTexture gBackgroundTexture;

LTexture gInputTextTexture;
LTexture gTextTexture;
LTexture gAch;
LTexture gShop;
LTexture gBack;
LTexture gbutton_board;
LTexture gbutton_cards;
LTexture f10;
LTexture f25;
LTexture f50;
LTexture f200;


int main(int argc, char* args[])
{
	//register_();// TODO
	//pre_main();// TODO
	//start(); TODO
	//shop_cards();// TODO
	//shop_fields();// TODO
	//achiv();// TODO
	main_manu();// TODO
	return 0;
}

void pre_main() {
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool quit = false;
			SDL_Event pre;



			while (!quit) {
				while (SDL_PollEvent(&pre) != 0)
				{
					//User requests quit
					if (pre.type == SDL_QUIT)
					{
						quit = true;
					}

					gButtons[2].handleEventPre(&pre, 'p');
					gButtons[3].handleEventPre(&pre, 'r');
				}

				gFooTexture_pre.render(0, 0);
				gButtons[2].renderPrePlay();

				gButtons[3].renderRegLog();

				SDL_RenderPresent(gRenderer);
				SDL_Delay(1);
			}
		}
	}
}

void start(string start) {

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			gBackgroundTexture.renderR(0, 0, gRenderer);
			SDL_RenderPresent(gRenderer);

			srand(time(0)); //for draft full random cards

			deck cards;
			cards.setDECK();
			cards.shuffle();

			player stickman;

			stickman.takeCard(cards);
			string card_up_1;
			card_up_1 = stickman.printSmCards(0);
			cards.delCard(card_up_1);


			upCard_1();
			upCard_2();
			dwCard_1();
			dwCard_2();

			anCard(card_up_1, 680, 53);

			player player;

			player.takeCard(cards);

			string card_dw_1;
			card_dw_1 = player.printSmCards(0);

			cards.delCard(card_dw_1);
			anCard(card_dw_1, 680, 470);

			player.takeCard(cards);
			string card_dw_2;

			card_dw_2 = player.printSmCards(1);
			cards.delCard(card_dw_2);
			anCard(card_dw_2, 580, 470);

			player.setCheckSum(card_dw_1);
			player.setCheckSum(card_dw_2);

			player.takeCard(cards);
			string card_dw_3 = player.printSmCards(2);
			cards.delCard(card_dw_3);

			player.takeCard(cards);
			string card_dw_4 = player.printSmCards(3);
			cards.delCard(card_dw_4);


			stickman.takeCard(cards);
			string card_up_2 = stickman.printSmCards(1);
			cards.delCard(card_up_2);
			stickman.setCheckSum(card_up_1);


			player.takeCard(cards);
			string card_dw_5 = player.printSmCards(4);
			cards.delCard(card_dw_5);

			player.takeCard(cards);
			string card_dw_6 = player.printSmCards(5);
			cards.delCard(card_dw_6);

			player.takeCard(cards);
			string card_dw_7 = player.printSmCards(6);
			cards.delCard(card_dw_7);

			stickman.takeCard(cards);
			string card_up_3 = stickman.printSmCards(2);
			cards.delCard(card_up_3);

			stickman.takeCard(cards);
			string card_up_4 = stickman.printSmCards(3);
			cards.delCard(card_up_4);

			stickman.takeCard(cards);
			string card_up_5 = stickman.printSmCards(4);
			cards.delCard(card_up_5);

			stickman.takeCard(cards);
			string card_up_6 = stickman.printSmCards(5);
			cards.delCard(card_up_6);

			stickman.takeCard(cards);
			string card_up_7 = stickman.printSmCards(6);
			cards.delCard(card_up_7);



			if (card_up_1 == "A_H" || card_up_1 == "A_S" || card_up_1 == "A_C" || card_up_1 == "A_D") countAstickman++;
			if (card_up_2 == "A_H" || card_up_2 == "A_S" || card_up_2 == "A_C" || card_up_2 == "A_D") countAstickman++;


			if (card_dw_1 == "A_H" || card_dw_1 == "A_S" || card_dw_1 == "A_C" || card_dw_1 == "A_D") countAplayer++;
			if (card_dw_2 == "A_H" || card_dw_2 == "A_S" || card_dw_2 == "A_C" || card_dw_2 == "A_D") countAplayer++;



			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					//Handle button events

					gButtons[0].handleEvent(&e, player, cards, card_up_1, card_up_2, card_dw_1, card_dw_2, "", 'h');
					gButtons[1].handleEvent(&e, player, cards, card_up_1, card_up_2, card_dw_1, card_dw_2, "", 's');
				}


				if (countCards == 2 && p1 == 0) {
					anCount(stickman.getCheckSum(), 650, 200);
					p1++;

					if (player.getCheckSum() == 21) {
						res = "win";
						anRes(res, 200, 50);
						for (int i = 0; i < 3000; i++) {
							SDL_Delay(1);
							anCount(stickman.getCheckSum(), 650, 200);
							anCount(player.getCheckSum(), 650, 400);
							anRes(res, 200, 50);
							SDL_RenderPresent(gRenderer);
						}

						stickman.checkSum = 0;
						player.checkSum = 0;
						player.smCards.erase(player.smCards.begin(), player.smCards.end());
						stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());


						if (start == "demo") {
							SDL_DestroyRenderer(gRenderer);
							SDL_DestroyWindow(gWindow);
							gWindow = NULL;
							gRenderer = NULL;

							pre_main();
						}
						else quit = true; //TODO
					}
					if (player.getCheckSum() == 22) {
						player.min10();
						countAplayer--;
					}
					anCount(player.getCheckSum(), 650, 400);
				}

				if (countCards == 3 && p2 == 0) {
					player.setCheckSum(card_dw_3);
					if (card_dw_3 == "A_H" || card_dw_3 == "A_S" || card_dw_3 == "A_C" || card_dw_3 == "A_D") countAplayer++;
					if (player.getCheckSum() == 21) {

						res = "win";
						anRes(res, 200, 50);
						for (int i = 0; i < 3000; i++) {
							SDL_Delay(1);
							anCount(stickman.getCheckSum(), 650, 200);
							anCount(player.getCheckSum(), 650, 400);
							anRes(res, 200, 50);
							SDL_RenderPresent(gRenderer);
						}

						stickman.checkSum = 0;
						player.checkSum = 0;

						if (start == "demo") {
							SDL_DestroyRenderer(gRenderer);
							SDL_DestroyWindow(gWindow);
							gWindow = NULL;
							gRenderer = NULL;

							pre_main();
						}
						else quit = true; //TODO
					}
					if (player.getCheckSum() > 21) {
						if (countAplayer > 0) {
							player.min10();
							cout << player.getCheckSum() << endl;
							countAplayer--;
						}
						else {
							anCard(card_dw_3, 480, 470);
							SDL_RenderPresent(gRenderer);
							SDL_Delay(1000);

							res = "lose";
							anRes(res, 200, 50);
							for (int i = 0; i < 3000; i++) {
								SDL_Delay(1);
								anCount(stickman.getCheckSum(), 650, 200);
								anCount(player.getCheckSum(), 650, 400);
								anRes(res, 200, 50);
								SDL_RenderPresent(gRenderer);
							}
							stickman.checkSum = 0;
							player.checkSum = 0;
							player.smCards.erase(player.smCards.begin(), player.smCards.end());
							stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());

							if (start == "demo") {

								SDL_DestroyRenderer(gRenderer);
								SDL_DestroyWindow(gWindow);
								gWindow = NULL;
								gRenderer = NULL;

								pre_main();
							}
							else quit = true; //TODO
						}
					}

					anCount(stickman.getCheckSum(), 650, 200);
					p2++;
					anCount(player.getCheckSum(), 650, 400);
				}

				if (countCards == 4 && p3 == 0) {
					player.setCheckSum(card_dw_4);
					if (card_dw_4 == "A_H" || card_dw_3 == "A_S" || card_dw_3 == "A_C" || card_dw_3 == "A_D") countAplayer++;
					if (player.getCheckSum() == 21) {

						res = "win";
						anRes(res, 200, 50);
						for (int i = 0; i < 3000; i++) {
							SDL_Delay(1);
							anRes(res, 200, 50);
							SDL_RenderPresent(gRenderer);
						}
						stickman.checkSum = 0;
						player.checkSum = 0;
						player.smCards.erase(player.smCards.begin(), player.smCards.end());
						stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());

						if (start == "demo") {
							SDL_DestroyRenderer(gRenderer);
							SDL_DestroyWindow(gWindow);
							gWindow = NULL;
							gRenderer = NULL;

							pre_main();
						}
						else quit = true; //TODO
					}
					if (player.getCheckSum() > 21) {
						if (countAplayer > 0) {
							player.min10();
							cout << player.getCheckSum() << endl;
							countAplayer--;
						}
						else {
							anCard(card_dw_3, 480, 470);
							anCard(card_dw_4, 380, 470);
							SDL_RenderPresent(gRenderer);
							SDL_Delay(1000);
							res = "lose";
							anRes(res, 200, 50);
							for (int i = 0; i < 3000; i++) {
								anCount(stickman.getCheckSum(), 650, 200);
								anCount(player.getCheckSum(), 650, 400);
								SDL_Delay(1);
								anRes(res, 200, 50);
								SDL_RenderPresent(gRenderer);
							}
							stickman.checkSum = 0;
							player.checkSum = 0;
							player.smCards.erase(player.smCards.begin(), player.smCards.end());
							stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
							if (start == "demo") {

								SDL_DestroyRenderer(gRenderer);
								SDL_DestroyWindow(gWindow);
								gWindow = NULL;
								gRenderer = NULL;

								pre_main();
							}
							else quit = true; //TODO
						}
					}
					anCount(stickman.getCheckSum(), 650, 200);
					p3++;
					anCount(player.getCheckSum(), 650, 400);
				}

				if (countCards == 5 && p4 == 0) {
					player.setCheckSum(card_dw_5);
					if (card_dw_5 == "A_H" || card_dw_3 == "A_S" || card_dw_3 == "A_C" || card_dw_3 == "A_D") countAplayer++;
					if (player.getCheckSum() == 21) {

						res = "win";
						anRes(res, 200, 50);
						for (int i = 0; i < 3000; i++) {
							SDL_Delay(1);
							anRes(res, 200, 50);
							SDL_RenderPresent(gRenderer);
						}
						stickman.checkSum = 0;
						player.checkSum = 0;
						player.smCards.erase(player.smCards.begin(), player.smCards.end());
						stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
						if (start == "demo") {

							SDL_DestroyRenderer(gRenderer);
							SDL_DestroyWindow(gWindow);
							gWindow = NULL;
							gRenderer = NULL;

							pre_main();
						}
						else quit = true; //TODO
					}
					if (player.getCheckSum() > 21) {
						if (countAplayer > 0) {
							player.min10();
							cout << player.getCheckSum() << endl;
							countAplayer--;
						}
						else {
							anCard(card_dw_3, 480, 470);
							anCard(card_dw_4, 380, 470);
							anCard(card_dw_5, 280, 470);
							SDL_RenderPresent(gRenderer);
							SDL_Delay(1000);
							res = "lose";
							anRes(res, 200, 50);
							for (int i = 0; i < 3000; i++) {
								anCount(stickman.getCheckSum(), 650, 200);
								anCount(player.getCheckSum(), 650, 400);
								SDL_Delay(1);
								anRes(res, 200, 50);
								SDL_RenderPresent(gRenderer);
							}
							stickman.checkSum = 0;
							player.checkSum = 0;
							player.smCards.erase(player.smCards.begin(), player.smCards.end());
							stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
							if (start == "demo") {

								SDL_DestroyRenderer(gRenderer);
								SDL_DestroyWindow(gWindow);
								gWindow = NULL;
								gRenderer = NULL;

								pre_main();
							}
							else quit = true; //TODO
						}
					}
					p4++;
					anCount(player.getCheckSum(), 650, 400);
					anCount(stickman.getCheckSum(), 650, 200);
				}

				if (countCards == 6 && p5 == 0) {
					player.setCheckSum(card_dw_6);
					if (card_dw_6 == "A_H" || card_dw_3 == "A_S" || card_dw_3 == "A_C" || card_dw_3 == "A_D") countAplayer++;
					if (player.getCheckSum() == 21) {
						res = "win";
						anRes(res, 200, 50);
						for (int i = 0; i < 3000; i++) {
							SDL_Delay(1);
							anRes(res, 200, 50);
							SDL_RenderPresent(gRenderer);
						}
						stickman.checkSum = 0;

						player.smCards.erase(player.smCards.begin(), player.smCards.end());
						stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
						if (start == "demo") {

							SDL_DestroyRenderer(gRenderer);
							SDL_DestroyWindow(gWindow);
							gWindow = NULL;
							gRenderer = NULL;

							pre_main();
						}
						else quit = true; //TODO
					}
					if (player.getCheckSum() > 21) {
						if (countAplayer > 0) {
							player.min10();
							cout << player.getCheckSum() << endl;
							countAplayer--;
						}
						else {
							anCard(card_dw_3, 480, 470);
							anCard(card_dw_4, 380, 470);
							anCard(card_dw_5, 380, 470);
							anCard(card_dw_6, 280, 470);
							SDL_RenderPresent(gRenderer);
							SDL_Delay(1000);
							res = "lose";
							anRes(res, 200, 50);
							for (int i = 0; i < 3000; i++) {
								SDL_Delay(1);
								anRes(res, 200, 50);
								SDL_RenderPresent(gRenderer);
							}
							stickman.checkSum = 0;
							player.checkSum = 0;
							player.smCards.erase(player.smCards.begin(), player.smCards.end());
							stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
							if (start == "demo") {

								SDL_DestroyRenderer(gRenderer);
								SDL_DestroyWindow(gWindow);
								gWindow = NULL;
								gRenderer = NULL;

								pre_main();
							}
							else quit = true; //TODO
						}
					}
					p5++;
					anCount(player.getCheckSum(), 650, 400);
					anCount(stickman.getCheckSum(), 650, 200);
				}

				if (countCards == 7 && p6 == 0) {
					player.setCheckSum(card_dw_7);
					if (card_dw_7 == "A_H" || card_dw_3 == "A_S" || card_dw_3 == "A_C" || card_dw_3 == "A_D") countAplayer++;
					if (player.getCheckSum() == 21) {
						if (countAplayer > 0) {
							player.min10();
							cout << player.getCheckSum() << endl;
							countAplayer--;
						}
						else {
							res = "win";
							anRes(res, 200, 50);
							for (int i = 0; i < 3000; i++) {
								SDL_Delay(1);
								anRes(res, 200, 50);
								SDL_RenderPresent(gRenderer);
							}
							stickman.checkSum = 0;
							player.checkSum = 0;
							player.smCards.erase(player.smCards.begin(), player.smCards.end());
							stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
							if (start == "demo") {

								SDL_DestroyRenderer(gRenderer);
								SDL_DestroyWindow(gWindow);
								gWindow = NULL;
								gRenderer = NULL;

								pre_main();
							}
							else quit = true; //TODO
						}
					}
					if (player.getCheckSum() > 21) {
						res = "lose";
						anCard(card_dw_3, 480, 470);
						anCard(card_dw_4, 380, 470);
						anCard(card_dw_5, 380, 470);
						anCard(card_dw_6, 280, 470);
						anCard(card_dw_7, 180, 470);
						SDL_RenderPresent(gRenderer);
						SDL_Delay(1000);
						anRes(res, 200, 50);
						for (int i = 0; i < 3000; i++) {
							SDL_Delay(1);
							anRes(res, 200, 50);
							SDL_RenderPresent(gRenderer);
						}
						stickman.checkSum = 0;
						player.checkSum = 0;
						player.smCards.erase(player.smCards.begin(), player.smCards.end());
						stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
						if (start == "demo") {

							SDL_DestroyRenderer(gRenderer);
							SDL_DestroyWindow(gWindow);
							gWindow = NULL;
							gRenderer = NULL;

							pre_main();
						}
						else quit = true; //TODO
					}
					p6++;
					anCount(player.getCheckSum(), 650, 400);
					anCount(stickman.getCheckSum(), 650, 200);
				}

				if (countCardsS == 3 && s1 == 0) {
					s1++;
					stickman.setCheckSum(card_up_2);
					if (stickman.getCheckSum() == 22) {
						stickman.min10();
						countAstickman--;
					}
					anCount(player.getCheckSum(), 650, 400);
					anCount(stickman.getCheckSum(), 650, 200);
					while (stickman.getCheckSum() < 22 && w == 0) {
						if (player.getCheckSum() <= stickman.getCheckSum()) {
							res = "lose";
							anRes(res, 200, 50);
							for (int i = 0; i < 3000; i++) {
								SDL_Delay(1);
								anRes(res, 200, 50);
								SDL_RenderPresent(gRenderer);
							}
							stickman.checkSum = 0;
							player.checkSum = 0;
							player.smCards.erase(player.smCards.begin(), player.smCards.end());
							stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
							if (start == "demo") {

								SDL_DestroyRenderer(gRenderer);
								SDL_DestroyWindow(gWindow);
								gWindow = NULL;
								gRenderer = NULL;

								pre_main();
							}
							else quit = true; //TODO
							goto finish;

						}
						else {
							stickman.setCheckSum(card_up_3);
							if (card_dw_3 == "A_H" || card_dw_3 == "A_S" || card_dw_3 == "A_C" || card_dw_3 == "A_D") countAstickman++;
							if (countAstickman > 0) {
								stickman.min10();
								countAstickman--;
							}
							anRes(res, 200, 50);
							SDL_RenderPresent(gRenderer);
							SDL_Delay(1000);
							upCard_3(player, card_up_1, card_up_2);
							anCard(card_up_1, 680, 53);
							anCard(card_up_2, 580, 53);
							anCard(card_up_3, 480, 53);
							anCount(player.getCheckSum(), 650, 400);
							anCount(stickman.getCheckSum(), 650, 200);
							SDL_RenderPresent(gRenderer);
							SDL_Delay(500);
							if (player.getCheckSum() <= stickman.getCheckSum() && stickman.getCheckSum() < 22) {
								res = "lose";
								anRes(res, 200, 50);
								for (int i = 0; i < 3000; i++) {
									SDL_Delay(1);
									anRes(res, 200, 50);
									SDL_RenderPresent(gRenderer);
								}
								stickman.checkSum = 0;
								player.checkSum = 0;
								player.smCards.erase(player.smCards.begin(), player.smCards.end());
								stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
								if (start == "demo")
								{
									SDL_DestroyRenderer(gRenderer);
									SDL_DestroyWindow(gWindow);
									gWindow = NULL;
									gRenderer = NULL;

									pre_main();
								}
								else quit = true; //TODO
								goto finish;
							}
							else {
								if (stickman.getCheckSum() > 21) {
									stickman.checkSum = 0;
									player.checkSum = 0;
									player.smCards.erase(player.smCards.begin(), player.smCards.end());
									stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
									if (start == "demo") {

										SDL_DestroyRenderer(gRenderer);
										SDL_DestroyWindow(gWindow);
										gWindow = NULL;
										gRenderer = NULL;

										pre_main();
									}
									else quit = true; //TODO
									goto finishW;
								}
								stickman.setCheckSum(card_up_4);
								if (card_dw_4 == "A_H" || card_dw_4 == "A_S" || card_dw_4 == "A_C" || card_dw_4 == "A_D") countAstickman++;
								if (countAstickman > 0) {
									stickman.min10();
									countAstickman--;
								}
								anRes(res, 200, 50);
								SDL_RenderPresent(gRenderer);
								SDL_Delay(1000);
								upCard_4(player, card_up_1, card_up_2, card_up_3);
								anCard(card_up_1, 680, 53);
								anCard(card_up_2, 580, 53);
								anCard(card_up_3, 480, 53);
								anCard(card_up_4, 380, 53);
								anCount(player.getCheckSum(), 650, 400);
								anCount(stickman.getCheckSum(), 650, 200);
								SDL_RenderPresent(gRenderer);
								SDL_Delay(500);
								if (player.getCheckSum() <= stickman.getCheckSum() && stickman.getCheckSum() < 22) {
									res = "lose";
									anRes(res, 200, 50);
									for (int i = 0; i < 3000; i++) {
										SDL_Delay(1);
										anRes(res, 200, 50);
										SDL_RenderPresent(gRenderer);
									}
									stickman.checkSum = 0;
									player.checkSum = 0;
									player.smCards.erase(player.smCards.begin(), player.smCards.end());
									stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());

									if (start == "demo") {

										SDL_DestroyRenderer(gRenderer);
										SDL_DestroyWindow(gWindow);
										gWindow = NULL;
										gRenderer = NULL;

										pre_main();
									}
									else quit = true; //TODO
									goto finish;
								}
								else {
									if (stickman.getCheckSum() > 21) {
										stickman.checkSum = 0;
										player.checkSum = 0;
										player.smCards.erase(player.smCards.begin(), player.smCards.end());
										stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
										if (start == "demo") {

											SDL_DestroyRenderer(gRenderer);
											SDL_DestroyWindow(gWindow);
											gWindow = NULL;
											gRenderer = NULL;

											pre_main();
										}
										else quit = true; //TODO
										goto finishW;
									}
									stickman.setCheckSum(card_up_5);
									if (card_dw_5 == "A_H" || card_dw_5 == "A_S" || card_dw_5 == "A_C" || card_dw_5 == "A_D") countAstickman++;
									if (countAstickman > 0) {
										stickman.min10();
										countAstickman--;
									}
									anRes(res, 200, 50);
									SDL_RenderPresent(gRenderer);
									SDL_Delay(1000);
									upCard_5(player, card_up_1, card_up_2, card_up_3, card_up_4);
									anCard(card_up_1, 680, 53);
									anCard(card_up_2, 580, 53);
									anCard(card_up_3, 480, 53);
									anCard(card_up_4, 380, 53);
									anCard(card_up_5, 280, 53);
									anCount(player.getCheckSum(), 650, 400);
									anCount(stickman.getCheckSum(), 650, 200);
									SDL_RenderPresent(gRenderer);
									SDL_Delay(500);
									if (player.getCheckSum() <= stickman.getCheckSum() && stickman.getCheckSum() < 22) {
										res = "lose";
										anRes(res, 200, 50);
										for (int i = 0; i < 3000; i++) {
											SDL_Delay(1);
											anRes(res, 200, 50);
											SDL_RenderPresent(gRenderer);
										}
										stickman.checkSum = 0;
										player.checkSum = 0;
										player.smCards.erase(player.smCards.begin(), player.smCards.end());
										stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
										if (start == "demo") {

											SDL_DestroyRenderer(gRenderer);
											SDL_DestroyWindow(gWindow);
											gWindow = NULL;
											gRenderer = NULL;

											pre_main();
										}
										else quit = true; //TODO
										goto finish;
									}
									else {
										if (stickman.getCheckSum() > 21) {
											stickman.checkSum = 0;
											player.checkSum = 0;
											player.smCards.erase(player.smCards.begin(), player.smCards.end());
											stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
											if (start == "demo") {

												SDL_DestroyRenderer(gRenderer);
												SDL_DestroyWindow(gWindow);
												gWindow = NULL;
												gRenderer = NULL;

												pre_main();
											}
											else quit = true; //TODO
											goto finishW;
										}
										stickman.setCheckSum(card_up_6);
										if (card_dw_6 == "A_H" || card_dw_6 == "A_S" || card_dw_6 == "A_C" || card_dw_6 == "A_D") countAstickman++;
										if (countAstickman > 0) {
											stickman.min10();
											countAstickman--;
										}
										anRes(res, 200, 50);
										SDL_RenderPresent(gRenderer);
										SDL_Delay(1000);
										upCard_5(player, card_up_1, card_up_2, card_up_3, card_up_4);
										anCard(card_up_1, 680, 53);
										anCard(card_up_2, 580, 53);
										anCard(card_up_3, 480, 53);
										anCard(card_up_4, 380, 53);
										anCard(card_up_5, 280, 53);
										anCard(card_up_6, 180, 53);
										anCount(player.getCheckSum(), 650, 400);
										anCount(stickman.getCheckSum(), 650, 200);
										SDL_RenderPresent(gRenderer);
										SDL_Delay(500);
										if (player.getCheckSum() <= stickman.getCheckSum() && stickman.getCheckSum() < 22) {
											res = "lose";
											anRes(res, 200, 50);
											for (int i = 0; i < 3000; i++) {
												SDL_Delay(1);
												anRes(res, 200, 50);
												SDL_RenderPresent(gRenderer);
											}
											stickman.checkSum = 0;
											player.checkSum = 0;
											player.smCards.erase(player.smCards.begin(), player.smCards.end());
											stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
											if (start == "demo") {

												SDL_DestroyRenderer(gRenderer);
												SDL_DestroyWindow(gWindow);
												gWindow = NULL;
												gRenderer = NULL;

												pre_main();
											}
											else quit = true; //TODO
											goto finish;
										}
										else {
											if (stickman.getCheckSum() > 21) {
												stickman.checkSum = 0;
												player.checkSum = 0;
												player.smCards.erase(player.smCards.begin(), player.smCards.end());
												stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
												if (start == "demo") {

													SDL_DestroyRenderer(gRenderer);
													SDL_DestroyWindow(gWindow);
													gWindow = NULL;
													gRenderer = NULL;

													pre_main();
												}
												else quit = true; //TODO
												goto finishW;
											}
											stickman.setCheckSum(card_up_7);
											if (card_dw_7 == "A_H" || card_dw_7 == "A_S" || card_dw_7 == "A_C" || card_dw_7 == "A_D") countAstickman++;
											if (countAstickman > 0) {
												stickman.min10();
												countAstickman--;
											}
											anRes(res, 200, 50);
											SDL_RenderPresent(gRenderer);
											SDL_Delay(1000);
											upCard_5(player, card_up_1, card_up_2, card_up_3, card_up_4);
											anCard(card_up_1, 680, 53);
											anCard(card_up_2, 580, 53);
											anCard(card_up_3, 480, 53);
											anCard(card_up_4, 380, 53);
											anCard(card_up_5, 280, 53);
											anCard(card_up_6, 180, 53);
											anCard(card_up_7, 80, 53);
											anCount(player.getCheckSum(), 650, 400);
											anCount(stickman.getCheckSum(), 650, 200);
											SDL_RenderPresent(gRenderer);
											SDL_Delay(500);
											if (player.getCheckSum() <= stickman.getCheckSum() && stickman.getCheckSum() < 22) {
												res = "lose";
												anRes(res, 200, 50);
												for (int i = 0; i < 3000; i++) {
													SDL_Delay(1);
													anRes(res, 200, 50);
													SDL_RenderPresent(gRenderer);
												}
												stickman.checkSum = 0;
												player.checkSum = 0;
												player.smCards.erase(player.smCards.begin(), player.smCards.end());
												stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
												if (start == "demo") {

													SDL_DestroyRenderer(gRenderer);
													SDL_DestroyWindow(gWindow);
													gWindow = NULL;
													gRenderer = NULL;

													pre_main();
												}
												else quit = true; //TODO
												goto finish;
											}
											else {
											finishW:
												res = "win";
												SDL_Delay(1000);
												anRes(res, 200, 50);
												for (int i = 0; i < 3000; i++) {
													SDL_Delay(1);
													anRes(res, 200, 50);
													SDL_RenderPresent(gRenderer);
												}
												stickman.checkSum = 0;
												player.checkSum = 0;
												player.smCards.erase(player.smCards.begin(), player.smCards.end());
												stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
												if (start == "demo") {

													SDL_DestroyRenderer(gRenderer);
													SDL_DestroyWindow(gWindow);
													gWindow = NULL;
													gRenderer = NULL;

													pre_main();
												}
												else quit = true; //TODO
												goto finish;
											}
											stickman.checkSum = 0;
											player.checkSum = 0;
											player.smCards.erase(player.smCards.begin(), player.smCards.end());
											stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
											if (start == "demo") {

												SDL_DestroyRenderer(gRenderer);
												SDL_DestroyWindow(gWindow);
												gWindow = NULL;
												gRenderer = NULL;

												pre_main();
											}
											else quit = true; //TODO
										}
										stickman.checkSum = 0;
										player.checkSum = 0;
										player.smCards.erase(player.smCards.begin(), player.smCards.end());
										stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
										if (start == "demo") {

											SDL_DestroyRenderer(gRenderer);
											SDL_DestroyWindow(gWindow);
											gWindow = NULL;
											gRenderer = NULL;

											pre_main();
										}
										else quit = true; //TODO
									}
									stickman.checkSum = 0;
									player.checkSum = 0;
									player.smCards.erase(player.smCards.begin(), player.smCards.end());
									stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
									if (start == "demo") {

										SDL_DestroyRenderer(gRenderer);
										SDL_DestroyWindow(gWindow);
										gWindow = NULL;
										gRenderer = NULL;

										pre_main();
									}
									else quit = true; //TODO
								}
								stickman.checkSum = 0;
								player.checkSum = 0;
								player.smCards.erase(player.smCards.begin(), player.smCards.end());
								stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
								if (start == "demo") {

									SDL_DestroyRenderer(gRenderer);
									SDL_DestroyWindow(gWindow);
									gWindow = NULL;
									gRenderer = NULL;

									pre_main();
								}
								else quit = true; //TODO
							}
							stickman.checkSum = 0;
							player.checkSum = 0;
							player.smCards.erase(player.smCards.begin(), player.smCards.end());
							stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
							if (start == "demo") {

								SDL_DestroyRenderer(gRenderer);
								SDL_DestroyWindow(gWindow);
								gWindow = NULL;
								gRenderer = NULL;

								pre_main();
							}
							else quit = true; //TODO
						}
						stickman.checkSum = 0;
						player.checkSum = 0;
						player.smCards.erase(player.smCards.begin(), player.smCards.end());
						stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
						if (start == "demo") {

							SDL_DestroyRenderer(gRenderer);
							SDL_DestroyWindow(gWindow);
							gWindow = NULL;
							gRenderer = NULL;

							pre_main();
						}
						else quit = true; //TODO
					}
					stickman.checkSum = 0;
					player.checkSum = 0;
					player.smCards.erase(player.smCards.begin(), player.smCards.end());
					stickman.smCards.erase(stickman.smCards.begin(), stickman.smCards.end());
					if (start == "demo") {

						SDL_DestroyRenderer(gRenderer);
						SDL_DestroyWindow(gWindow);
						gWindow = NULL;
						gRenderer = NULL;

						pre_main();
					}
					else quit = true; //TODO
				}

				gButtons[0].render();
				gButtons[1].render2();
				SDL_RenderPresent(gRenderer);

			}
		}
	finish:
		//Free resources and close SDL
		close();
		//return 0;
	}
}

void register_() {
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool quit = false;
			while (!quit) {
				gFooTexture_register.render(0, 0);
				SDL_RenderPresent(gRenderer);
				reg();
				SDL_Delay(1);
			}
		}
	}
}

void shop_cards() {
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			SDL_Event st;
			bool quit = false;
			while (SDL_PollEvent(&st) != 0)
			{
				//User requests quit
				if (st.type == SDL_QUIT)
				{
					quit = true;
				}
				gButtons[8].handleEventBoards(&st, 'S');
			}
			while (!quit) {
				gFooTexture_shop_cards.render(0, 0);
				gButtons[8].renderBoards();
				SDL_RenderPresent(gRenderer);
				SDL_Delay(1);
			}
		}
	}
}

void shop_fields() {
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool quit = false;
			SDL_Event st;
			while (!quit) {
				while (SDL_PollEvent(&st) != 0)
				{
					//User requests quit
					if (st.type == SDL_QUIT)
					{
						quit = true;
					}
					gButtons[9].handleEventCards(&st, 'S');
				}
				gFooTexture_shop_fields.render(0, 0);
				gButtons[9].renderCards();
				SDL_RenderPresent(gRenderer);
				SDL_Delay(1);
			}

		}
	}
}

void achiv() {
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			SDL_Event st;
			bool quit = false;
			while (!quit) {
				while (SDL_PollEvent(&st) != 0)
				{
					//User requests quit
					if (st.type == SDL_QUIT)
					{
						quit = true;
					}
					gButtons[7].handleEventBack(&st, 'S');
				}

				gFooTexture_achiv.render(0, 0);
				gButtons[7].renderBack();
				SDL_RenderPresent(gRenderer);
				SDL_Delay(1);
			}

		}
	}
}

void main_manu() {
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{

			SDL_Event st;
			bool quit = false;
			while (!quit) {
				while (SDL_PollEvent(&st) != 0)
				{
					//User requests quit
					if (st.type == SDL_QUIT)
					{
						quit = true;
					}

					gButtons[4].handleEventStart(&st, 'S');
					gButtons[5].handleEventAch(&st, 'A');
					gButtons[6].handleEventShop(&st, 'S');
					gButtons[12].handleEventf10(&st, 'f');
					gButtons[13].handleEventf25(&st, 'f');
					gButtons[14].handleEventf50(&st, 'f');
					gButtons[15].handleEventf200(&st, 'f');


				}
				gFooTexture_main_menu.render(0, 0);

				gButtons[4].renderST();
				gButtons[5].renderAch();
				gButtons[6].renderShop();
				gButtons[12].renderf10();
				gButtons[13].renderf25();
				gButtons[14].renderf50();
				gButtons[15].renderf200();

				SDL_RenderPresent(gRenderer);
				SDL_Delay(1);
			}
		}
	}
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Black Jack", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}


bool loadMedia()
{

	//Loading success flag
	bool success = true;

	if (!gFooTexture_pre.loadFromFile("images/pre_main.png", gRenderer))
	{
		printf("Failed to load images/pre_main.png texture image!\n");
		success = false;
	}

	//Load Foo' texture
	if (!gFooTexture.loadFromFile("images/card_shirt_1.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_won.loadFromFile("images/won.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_lose.loadFromFile("images/lose.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	//***********************************************************************************
	if (!gFooTexture_4.loadFromFile("images/4_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_5.loadFromFile("images/5_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_6.loadFromFile("images/6_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_7.loadFromFile("images/7_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_8.loadFromFile("images/8_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_9.loadFromFile("images/9_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_10.loadFromFile("images/10_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_11.loadFromFile("images/11_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_12.loadFromFile("images/12_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_13.loadFromFile("images/13_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_14.loadFromFile("images/14_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_15.loadFromFile("images/15_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_16.loadFromFile("images/16_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_17.loadFromFile("images/17_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_18.loadFromFile("images/18_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_19.loadFromFile("images/19_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_20.loadFromFile("images/20_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_21.loadFromFile("images/21_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_22.loadFromFile("images/22_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_23.loadFromFile("images/23_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_24.loadFromFile("images/24_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_25.loadFromFile("images/25_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_26.loadFromFile("images/26_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_27.loadFromFile("images/27_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_28.loadFromFile("images/28_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_29.loadFromFile("images/29_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	if (!gFooTexture_30.loadFromFile("images/30_num.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	//***********************************************************************************
	if (!gFooTexture_2_H.loadFromFile("images/hearts_2.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_3_H.loadFromFile("images/hearts_3.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_4_H.loadFromFile("images/hearts_4.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_5_H.loadFromFile("images/hearts_5.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_6_H.loadFromFile("images/hearts_6.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_7_H.loadFromFile("images/hearts_7.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_8_H.loadFromFile("images/hearts_8.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_9_H.loadFromFile("images/hearts_9.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_10_H.loadFromFile("images/hearts_10.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_J_H.loadFromFile("images/hearts_J.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_Q_H.loadFromFile("images/hearts_Q.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_K_H.loadFromFile("images/hearts_K.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_A_H.loadFromFile("images/hearts_A.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	//***********************************************************************************
	if (!gFooTexture_2_S.loadFromFile("images/spades_2.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_3_S.loadFromFile("images/spades_3.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_4_S.loadFromFile("images/spades_4.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_5_S.loadFromFile("images/spades_5.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_6_S.loadFromFile("images/spades_6.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_7_S.loadFromFile("images/spades_7.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_8_S.loadFromFile("images/spades_8.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_9_S.loadFromFile("images/spades_9.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_10_S.loadFromFile("images/spades_10.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_J_S.loadFromFile("images/spades_J.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_Q_S.loadFromFile("images/spades_Q.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_K_S.loadFromFile("images/spades_K.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_A_S.loadFromFile("images/spades_A.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	//***********************************************************************************
	if (!gFooTexture_2_C.loadFromFile("images/clubs_2.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_3_C.loadFromFile("images/clubs_3.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_4_C.loadFromFile("images/clubs_4.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_5_C.loadFromFile("images/clubs_5.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_6_C.loadFromFile("images/clubs_6.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_7_C.loadFromFile("images/clubs_7.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_8_C.loadFromFile("images/clubs_8.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_9_C.loadFromFile("images/clubs_9.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_10_C.loadFromFile("images/clubs_10.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_J_C.loadFromFile("images/clubs_J.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_Q_C.loadFromFile("images/clubs_Q.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_K_C.loadFromFile("images/clubs_K.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_A_C.loadFromFile("images/clubs_A.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	//***********************************************************************************
	if (!gFooTexture_2_D.loadFromFile("images/diamonds_2.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_3_D.loadFromFile("images/diamonds_3.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_4_D.loadFromFile("images/diamonds_4.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_5_D.loadFromFile("images/diamonds_5.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_6_D.loadFromFile("images/diamonds_6.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_7_D.loadFromFile("images/diamonds_7.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_8_D.loadFromFile("images/diamonds_8.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_9_D.loadFromFile("images/diamonds_9.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_10_D.loadFromFile("images/diamonds_10.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_J_D.loadFromFile("images/diamonds_J.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_Q_D.loadFromFile("images/diamonds_Q.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_K_D.loadFromFile("images/diamonds_K.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gFooTexture_A_D.loadFromFile("images/diamonds_A.png", gRenderer))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	//***********************************************************************************

	//Load background texture
	if (!gBackgroundTexture.loadFromFile("images/fild.png", gRenderer))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!gFooTexture_register.loadFromFile("images/register.png", gRenderer))
	{
		printf("Failed to load register texture image!\n");
		success = false;
	}

	if (!gFooTexture_shop_cards.loadFromFile("images/shop_cards.png", gRenderer))
	{
		printf("Failed to load shop_cards texture image!\n");
		success = false;
	}

	if (!gFooTexture_shop_fields.loadFromFile("images/shop_fields.png", gRenderer))
	{
		printf("Failed to load shop_fields texture image!\n");
		success = false;
	}

	if (!gFooTexture_achiv.loadFromFile("images/achivments_F.png", gRenderer))
	{
		printf("Failed to load achivments texture image!\n");
		success = false;
	}

	if (!gFooTexture_main_menu.loadFromFile("images/main_menu.png", gRenderer))
	{
		printf("Failed to load main_menu texture image!\n");
		success = false;
	}

	if (!gButtonSpriteSheetTexture.loadFromFile("images/hit_an.png", gRenderer))
	{
		printf("Failed to load button sprite texture!\n");
		success = false;
	}

	else
	{
		//Set sprites
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClips[i].x = 0;
			gSpriteClips[i].y = i * 160;
			gSpriteClips[i].w = BUTTON_WIDTH;
			gSpriteClips[i].h = BUTTON_HEIGHT;
		}

		//Set buttons in corners
		gButtons[0].setPosition(229, 247);
		//gButtons[1].setPosition(429, 247);
		//gButtons[2].setPosition(0, SCREEN_HEIGHT - BUTTON_HEIGHT);
		//gButtons[3].setPosition(SCREEN_WIDTH - BUTTON_WIDTH, SCREEN_HEIGHT - BUTTON_HEIGHT);
	}

	if (!gButtonSpriteSheetTexture2.loadFromFile("images/stand_an.png", gRenderer))
	{
		printf("Failed to load button sprite texture!\n");
		success = false;
	}
	else
	{
		//Set sprites
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClips[i].x = 0;
			gSpriteClips[i].y = i * 160;
			gSpriteClips[i].w = BUTTON_WIDTH;
			gSpriteClips[i].h = BUTTON_HEIGHT;
		}


		gButtons[1].setPosition(429, 247);

	}

	if (!gFooTexture_pre_play.loadFromFile("images/pre_play.png", gRenderer))
	{
		printf("Failed to load images/pre_play.png texture image!\n");
		success = false;
	}
	else
	{
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClipsPrePlay[i].x = 0;
			gSpriteClipsPrePlay[i].y = i * 80;
			gSpriteClipsPrePlay[i].w = BUTTON_WIDTH_pre;
			gSpriteClipsPrePlay[i].h = BUTTON_HEIGHT_pre;
		}
		gButtons[2].setPosition(329, 300);
	}

	if (!gFooTexture_register_login.loadFromFile("images/register_login.png", gRenderer))
	{
		printf("Failed to load images/register_login.png texture image!\n");
		success = false;
	}
	else
	{
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClipsRegLog[i].x = 0;
			gSpriteClipsRegLog[i].y = i * 80;
			gSpriteClipsRegLog[i].w = BUTTON_WIDTH_reg;
			gSpriteClipsRegLog[i].h = BUTTON_HEIGHT_reg;
		}
		gButtons[3].setPosition(329, 400);
	}

	if (!gFooTexture_start.loadFromFile("images/Start_button.png", gRenderer))
	{
		printf("Failed to load Start_button texture image!\n");
		success = false;
	}
	else
	{
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClips_st[i].x = 0;
			gSpriteClips_st[i].y = i * 100;
			gSpriteClips_st[i].w = 248;
			gSpriteClips_st[i].h = 100;
		}
		gButtons[4].setPosition(85, 479);
	}

	if (!gAch.loadFromFile("images/achivments.png", gRenderer))
	{
		printf("Failed to load achivments texture image!\n");
		success = false;
	}
	else
	{
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClipsAch[i].x = 0;
			gSpriteClipsAch[i].y = i * 181;
			gSpriteClipsAch[i].w = 155;
			gSpriteClipsAch[i].h = 181;
		}
		gButtons[5].setPosition(45, 55);
	}

	if (!gShop.loadFromFile("images/shop.png", gRenderer))
	{
		printf("Failed to load achivments texture image!\n");
		success = false;
	}
	else
	{
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClipsShop[i].x = 0;
			gSpriteClipsShop[i].y = i * 151;
			gSpriteClipsShop[i].w = 152;
			gSpriteClipsShop[i].h = 151;
		}
		gButtons[6].setPosition(620, 55);
	}

	if (!gBack.loadFromFile("images/button_back.png", gRenderer))
	{
		printf("Failed to load achivments texture image!\n");
		success = false;
	}
	else
	{
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClipsBack[i].x = 0;
			gSpriteClipsBack[i].y = i * 75;
			gSpriteClipsBack[i].w = 105;
			gSpriteClipsBack[i].h = 75;
		}
		gButtons[7].setPosition(60, 0);
	}

	if (!gbutton_board.loadFromFile("images/button_board.png", gRenderer))
	{
		printf("Failed to load achivments gbutton_board image!\n");
		success = false;
	}
	else
	{
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClipsBoards[i].x = 0;
			gSpriteClipsBoards[i].y = i * 80;
			gSpriteClipsBoards[i].w = 165;
			gSpriteClipsBoards[i].h = 80;
		}
		gButtons[8].setPosition(620, 404);
	}

	if (!gbutton_cards.loadFromFile("images/button_cards.png", gRenderer))
	{
		printf("Failed to load gbutton_cards image!\n");
		success = false;
	}
	else
	{
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClipsCards[i].x = 0;
			gSpriteClipsCards[i].y = i * 76;
			gSpriteClipsCards[i].w = 161;
			gSpriteClipsCards[i].h = 76;
		}
		gButtons[9].setPosition(620, 404);
	}
	//fish)))////////////////////////////////////////////////

	if (!f10.loadFromFile("images/f10.png", gRenderer))
	{
		printf("Failed to load f10 image!\n");
		success = false;
	}
	else
	{
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClipsf10[i].x = 0;
			gSpriteClipsf10[i].y = i * 105;
			gSpriteClipsf10[i].w = 160;
			gSpriteClipsf10[i].h = 105;
		}
		gButtons[12].setPosition(350, 394);
	}

	if (!f25.loadFromFile("images/f25.png", gRenderer))
	{
		printf("Failed to load f25 image!\n");
		success = false;
	}
	else
	{
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClipsf25[i].x = 0;
			gSpriteClipsf25[i].y = i * 105;
			gSpriteClipsf25[i].w = 160;
			gSpriteClipsf25[i].h = 105;
		}
		gButtons[13].setPosition(430, 504);
	}

	if (!f50.loadFromFile("images/f50.png", gRenderer))
	{
		printf("Failed to load f50 image!\n");
		success = false;
	}
	else
	{
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClipsf50[i].x = 0;
			gSpriteClipsf50[i].y = i * 105;
			gSpriteClipsf50[i].w = 160;
			gSpriteClipsf50[i].h = 105;
		}
		gButtons[14].setPosition(510, 394);
	}

	if (!f200.loadFromFile("images/f200.png", gRenderer))
	{
		printf("Failed to load f200 image!\n");
		success = false;
	}
	else
	{
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClipsf200[i].x = 0;
			gSpriteClipsf200[i].y = i * 105;
			gSpriteClipsf200[i].w = 160;
			gSpriteClipsf200[i].h = 105;
		}
		gButtons[15].setPosition(590, 504);
	}

	return success;

}

void close()
{
	gButtonSpriteSheetTexture.free();
	gButtonSpriteSheetTexture2.free();
	//Free loaded images
	gFooTexture.free();
	gBackgroundTexture.free();

	gFooTexture_4.free();
	gFooTexture_5.free();
	gFooTexture_6.free();
	gFooTexture_7.free();
	gFooTexture_8.free();
	gFooTexture_9.free();
	gFooTexture_10.free();
	gFooTexture_11.free();
	gFooTexture_12.free();
	gFooTexture_13.free();
	gFooTexture_14.free();
	gFooTexture_15.free();
	gFooTexture_16.free();
	gFooTexture_17.free();
	gFooTexture_18.free();
	gFooTexture_19.free();
	gFooTexture_20.free();
	gFooTexture_21.free();
	gFooTexture_22.free();
	gFooTexture_23.free();
	gFooTexture_24.free();
	gFooTexture_25.free();
	gFooTexture_26.free();
	gFooTexture_27.free();
	gFooTexture_28.free();
	gFooTexture_29.free();
	gFooTexture_30.free();

	gFooTexture_2_H.free();
	gFooTexture_3_H.free();
	gFooTexture_4_H.free();
	gFooTexture_5_H.free();
	gFooTexture_6_H.free();
	gFooTexture_7_H.free();
	gFooTexture_8_H.free();
	gFooTexture_9_H.free();
	gFooTexture_10_H.free();
	gFooTexture_J_H.free();
	gFooTexture_Q_H.free();
	gFooTexture_K_H.free();
	gFooTexture_A_H.free();

	gFooTexture_2_S.free();
	gFooTexture_3_S.free();
	gFooTexture_4_S.free();
	gFooTexture_5_S.free();
	gFooTexture_6_S.free();
	gFooTexture_7_S.free();
	gFooTexture_8_S.free();
	gFooTexture_9_S.free();
	gFooTexture_10_S.free();
	gFooTexture_J_S.free();
	gFooTexture_Q_S.free();
	gFooTexture_K_S.free();
	gFooTexture_A_S.free();

	gFooTexture_2_C.free();
	gFooTexture_3_C.free();
	gFooTexture_4_C.free();
	gFooTexture_5_C.free();
	gFooTexture_6_C.free();
	gFooTexture_7_C.free();
	gFooTexture_8_C.free();
	gFooTexture_9_C.free();
	gFooTexture_10_C.free();
	gFooTexture_J_C.free();
	gFooTexture_Q_C.free();
	gFooTexture_K_C.free();
	gFooTexture_A_C.free();

	gFooTexture_2_D.free();
	gFooTexture_3_D.free();
	gFooTexture_4_D.free();
	gFooTexture_5_D.free();
	gFooTexture_6_D.free();
	gFooTexture_7_D.free();
	gFooTexture_8_D.free();
	gFooTexture_9_D.free();
	gFooTexture_10_D.free();
	gFooTexture_J_D.free();
	gFooTexture_Q_D.free();
	gFooTexture_K_D.free();
	gFooTexture_A_D.free();

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void upCard_1() {
	for (int i = 261; i > 53; i--) {

		//Render Foo' to the screen
		gFooTexture.render(31, i);

		//Update screen
		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 680; i++) {

		//Render Foo' to the screen
		gFooTexture.render(i, 53);

		//Update screen

		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);

		SDL_Delay(1);
	}
	gFooTexture.render(680, 53);
	SDL_RenderPresent(gRenderer);
}

void upCard_2() {
	for (int i = 261; i > 53; i--) {

		//Render Foo' to the screen
		gFooTexture.render(31, i);
		gFooTexture.render(680, 53);
		//Update screen
		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);



		SDL_Delay(1);
	}
	for (int i = 31; i < 580; i++) {

		//Render Foo' to the screen
		gFooTexture.render(680, 53);
		gFooTexture.render(i, 53);

		//Update screen

		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}

	gFooTexture.render(680, 53);
	gFooTexture.render(580, 53);
	SDL_RenderPresent(gRenderer);
}

void dwCard_1() {
	for (int i = 261; i < 470; i++) {
		gFooTexture.render(580, 53);
		gFooTexture.render(680, 53);
		//Render Foo' to the screen
		gFooTexture.render(31, i);

		//Update screen
		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 680; i++) {

		//Render Foo' to the screen
		gFooTexture.render(580, 53);
		gFooTexture.render(680, 53);
		gFooTexture.render(i, 470);

		//Update screen

		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);

		SDL_Delay(1);
	}
	gFooTexture.render(680, 53);
	gFooTexture.render(580, 53);
	gFooTexture.render(680, 470);
	SDL_RenderPresent(gRenderer);
}

void dwCard_2() {
	for (int i = 261; i < 470; i++) {
		gFooTexture.render(580, 53);
		gFooTexture.render(680, 53);
		gFooTexture.render(680, 470);
		//Render Foo' to the screen
		gFooTexture.render(31, i);

		//Update screen
		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 580; i++) {

		//Render Foo' to the screen
		gFooTexture.render(580, 53);
		gFooTexture.render(680, 53);
		gFooTexture.render(680, 470);
		gFooTexture.render(i, 470);

		//Update screen

		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);

		SDL_Delay(1);
	}
	gFooTexture.render(680, 53);
	gFooTexture.render(580, 53);
	gFooTexture.render(680, 470);
	gFooTexture.render(580, 470);
	SDL_RenderPresent(gRenderer);
}

void anRes(string res, int x, int y) {
	if (res == "win") gFooTexture_won.render(x, y);
	if (res == "lose") gFooTexture_lose.render(x, y);
}

void anCard(string card, int x, int y) {
	if (card == "2_H") {
		gFooTexture_2_H.render(x, y);
	}

	if (card == "3_H") {
		gFooTexture_3_H.render(x, y);
	}

	if (card == "4_H") {
		gFooTexture_4_H.render(x, y);
	}

	if (card == "5_H") {
		gFooTexture_5_H.render(x, y);
	}

	if (card == "6_H") {
		gFooTexture_6_H.render(x, y);
	}

	if (card == "7_H") {
		gFooTexture_7_H.render(x, y);
	}

	if (card == "8_H") {
		gFooTexture_8_H.render(x, y);
	}

	if (card == "9_H") {
		gFooTexture_9_H.render(x, y);
	}

	if (card == "10_H") {
		gFooTexture_10_H.render(x, y);
	}

	if (card == "J_H") {
		gFooTexture_J_H.render(x, y);
	}

	if (card == "Q_H") {
		gFooTexture_Q_H.render(x, y);
	}

	if (card == "K_H") {
		gFooTexture_K_H.render(x, y);
	}

	if (card == "A_H") {
		gFooTexture_A_H.render(x, y);
	}
	//*************************************
	if (card == "2_S") {
		gFooTexture_2_S.render(x, y);
	}

	if (card == "3_S") {
		gFooTexture_3_S.render(x, y);
	}

	if (card == "4_S") {
		gFooTexture_4_S.render(x, y);
	}

	if (card == "5_S") {
		gFooTexture_5_S.render(x, y);
	}

	if (card == "6_S") {
		gFooTexture_6_S.render(x, y);
	}

	if (card == "7_S") {
		gFooTexture_7_S.render(x, y);
	}

	if (card == "8_S") {
		gFooTexture_8_S.render(x, y);
	}

	if (card == "9_S") {
		gFooTexture_9_S.render(x, y);
	}

	if (card == "10_S") {
		gFooTexture_10_S.render(x, y);
	}

	if (card == "J_S") {
		gFooTexture_J_S.render(x, y);
	}

	if (card == "Q_S") {
		gFooTexture_Q_S.render(x, y);
	}

	if (card == "K_S") {
		gFooTexture_K_S.render(x, y);
	}

	if (card == "A_S") {
		gFooTexture_A_S.render(x, y);
	}
	//*************************************
	if (card == "2_C") {
		gFooTexture_2_C.render(x, y);
	}

	if (card == "3_C") {
		gFooTexture_3_C.render(x, y);
	}

	if (card == "4_C") {
		gFooTexture_4_C.render(x, y);
	}

	if (card == "5_C") {
		gFooTexture_5_C.render(x, y);
	}

	if (card == "6_C") {
		gFooTexture_6_C.render(x, y);
	}

	if (card == "7_C") {
		gFooTexture_7_C.render(x, y);
	}

	if (card == "8_C") {
		gFooTexture_8_C.render(x, y);
	}

	if (card == "9_C") {
		gFooTexture_9_C.render(x, y);
	}

	if (card == "10_C") {
		gFooTexture_10_C.render(x, y);
	}

	if (card == "J_C") {
		gFooTexture_J_C.render(x, y);
	}

	if (card == "Q_C") {
		gFooTexture_Q_C.render(x, y);
	}

	if (card == "K_C") {
		gFooTexture_K_C.render(x, y);
	}

	if (card == "A_C") {
		gFooTexture_A_C.render(x, y);
	}
	//*************************************


	if (card == "2_D") {
		gFooTexture_2_D.render(x, y);
	}

	if (card == "3_D") {
		gFooTexture_3_D.render(x, y);
	}

	if (card == "4_D") {
		gFooTexture_4_D.render(x, y);
	}

	if (card == "5_D") {
		gFooTexture_5_D.render(x, y);
	}

	if (card == "6_D") {
		gFooTexture_6_D.render(x, y);
	}

	if (card == "7_D") {
		gFooTexture_7_D.render(x, y);
	}

	if (card == "8_D") {
		gFooTexture_8_D.render(x, y);
	}

	if (card == "9_D") {
		gFooTexture_9_D.render(x, y);
	}

	if (card == "10_D") {
		gFooTexture_10_D.render(x, y);
	}

	if (card == "J_D") {
		gFooTexture_J_D.render(x, y);
	}

	if (card == "Q_D") {
		gFooTexture_Q_D.render(x, y);
	}

	if (card == "K_D") {
		gFooTexture_K_D.render(x, y);
	}

	if (card == "A_D") {
		gFooTexture_A_D.render(x, y);
	}
}

void dwCard_3(string card_up_1, string card_dw_1, string card_dw_2) {
	for (int i = 261; i < 470; i++) {

		gFooTexture.render(580, 53);
		gFooTexture.render(680, 53);
		gFooTexture.render(680, 470);
		gFooTexture.render(580, 470);
		anCard(card_up_1, 680, 53);
		anCard(card_dw_1, 680, 470);
		anCard(card_dw_2, 580, 470);
		//Render Foo' to the screen
		gFooTexture.render(31, i);

		//Update screen
		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 480; i++) {

		//Render Foo' to the screen
		gFooTexture.render(580, 53);
		gFooTexture.render(680, 53);
		gFooTexture.render(580, 470);
		gFooTexture.render(680, 470);
		anCard(card_up_1, 680, 53);
		anCard(card_dw_1, 680, 470);
		anCard(card_dw_2, 580, 470);
		gFooTexture.render(i, 470);

		//Update screen

		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);

		SDL_Delay(1);
	}
	gFooTexture.render(680, 53);
	gFooTexture.render(580, 53);
	gFooTexture.render(680, 470);
	gFooTexture.render(580, 470);
	gFooTexture.render(480, 470);
	anCard(card_up_1, 680, 53);
	anCard(card_dw_1, 680, 470);
	anCard(card_dw_2, 580, 470);
	SDL_RenderPresent(gRenderer);
}

void dwCard_4(string card_up_1, string card_dw_1, string card_dw_2, string card_dw_3) {

	for (int i = 261; i < 470; i++) {

		gFooTexture.render(580, 53);

		anCard(card_up_1, 680, 53);
		anCard(card_dw_1, 680, 470);
		anCard(card_dw_2, 580, 470);
		anCard(card_dw_3, 480, 470);
		//Render Foo' to the screen
		gFooTexture.render(31, i);

		//Update screen
		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 380; i++) {

		//Render Foo' to the screen
		gFooTexture.render(580, 53);

		anCard(card_up_1, 680, 53);
		anCard(card_dw_1, 680, 470);
		anCard(card_dw_2, 580, 470);
		anCard(card_dw_3, 480, 470);
		gFooTexture.render(i, 470);

		//Update screen

		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);

		SDL_Delay(1);
	}
	gFooTexture.render(680, 53);
	gFooTexture.render(580, 53);
	gFooTexture.render(680, 470);
	gFooTexture.render(580, 470);
	gFooTexture.render(480, 470);
	gFooTexture.render(380, 470);
	anCard(card_up_1, 680, 53);
	anCard(card_dw_1, 680, 470);
	anCard(card_dw_2, 580, 470);
	anCard(card_dw_3, 480, 470);

	SDL_RenderPresent(gRenderer);
}

void dwCard_5(string card_up_1, string card_dw_1, string card_dw_2, string card_dw_3, string card_dw_4) {

	for (int i = 261; i < 470; i++) {

		gFooTexture.render(580, 53);

		anCard(card_up_1, 680, 53);
		anCard(card_dw_1, 680, 470);
		anCard(card_dw_2, 580, 470);
		anCard(card_dw_3, 480, 470);
		anCard(card_dw_4, 380, 470);
		//Render Foo' to the screen
		gFooTexture.render(31, i);

		//Update screen
		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 280; i++) {

		//Render Foo' to the screen
		gFooTexture.render(580, 53);

		anCard(card_up_1, 680, 53);
		anCard(card_dw_1, 680, 470);
		anCard(card_dw_2, 580, 470);
		anCard(card_dw_3, 480, 470);
		anCard(card_dw_4, 380, 470);
		gFooTexture.render(i, 470);

		//Update screen

		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);

		SDL_Delay(1);
	}

	gFooTexture.render(580, 53);


	anCard(card_up_1, 680, 53);
	anCard(card_dw_1, 680, 470);
	anCard(card_dw_2, 580, 470);
	anCard(card_dw_3, 480, 470);
	anCard(card_dw_4, 380, 470);
	SDL_RenderPresent(gRenderer);
}

void dwCard_6(string card_up_1, string card_dw_1, string card_dw_2, string card_dw_3, string card_dw_4, string card_dw_5) {

	for (int i = 261; i < 470; i++) {

		gFooTexture.render(580, 53);

		anCard(card_up_1, 680, 53);
		anCard(card_dw_1, 680, 470);
		anCard(card_dw_2, 580, 470);
		anCard(card_dw_3, 480, 470);
		anCard(card_dw_4, 380, 470);
		anCard(card_dw_5, 280, 470);
		//Render Foo' to the screen
		gFooTexture.render(31, i);

		//Update screen
		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 180; i++) {

		//Render Foo' to the screen
		gFooTexture.render(580, 53);

		anCard(card_up_1, 680, 53);
		anCard(card_dw_1, 680, 470);
		anCard(card_dw_2, 580, 470);
		anCard(card_dw_3, 480, 470);
		anCard(card_dw_4, 380, 470);
		anCard(card_dw_5, 280, 470);
		gFooTexture.render(i, 470);

		//Update screen

		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);

		SDL_Delay(1);
	}

	gFooTexture.render(580, 53);


	anCard(card_up_1, 680, 53);
	anCard(card_dw_1, 680, 470);
	anCard(card_dw_2, 580, 470);
	anCard(card_dw_3, 480, 470);
	anCard(card_dw_4, 380, 470);
	anCard(card_dw_5, 280, 470);
	SDL_RenderPresent(gRenderer);
}

void dwCard_7(string card_up_1, string card_dw_1, string card_dw_2, string card_dw_3, string card_dw_4, string card_dw_5, string card_dw_6) {
	for (int i = 261; i < 470; i++) {

		gFooTexture.render(580, 53);

		anCard(card_up_1, 680, 53);
		anCard(card_dw_1, 680, 470);
		anCard(card_dw_2, 580, 470);
		anCard(card_dw_3, 480, 470);
		anCard(card_dw_4, 380, 470);
		anCard(card_dw_5, 280, 470);
		anCard(card_dw_6, 180, 470);
		//Render Foo' to the screen
		gFooTexture.render(31, i);

		//Update screen
		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 80; i++) {

		//Render Foo' to the screen
		gFooTexture.render(580, 53);

		anCard(card_up_1, 680, 53);
		anCard(card_dw_1, 680, 470);
		anCard(card_dw_2, 580, 470);
		anCard(card_dw_3, 480, 470);
		anCard(card_dw_4, 380, 470);
		anCard(card_dw_5, 280, 470);
		anCard(card_dw_6, 180, 470);
		gFooTexture.render(i, 470);

		//Update screen

		SDL_RenderPresent(gRenderer);
		gBackgroundTexture.render(0, 0);

		SDL_Delay(1);
	}

	gFooTexture.render(580, 53);


	anCard(card_up_1, 680, 53);
	anCard(card_dw_1, 680, 470);
	anCard(card_dw_2, 580, 470);
	anCard(card_dw_3, 480, 470);
	anCard(card_dw_4, 380, 470);
	anCard(card_dw_5, 280, 470);
	anCard(card_dw_6, 180, 470);
	SDL_RenderPresent(gRenderer);
}

void upCard_3(player player, string card_up_1, string card_up_2) {
	string card_dw_1 = player.printSmCards(0);
	string card_dw_2 = player.printSmCards(1);
	string card_dw_3 = player.printSmCards(2);
	string card_dw_4 = player.printSmCards(3);
	string card_dw_5 = player.printSmCards(4);
	string card_dw_6 = player.printSmCards(5);
	string card_dw_7 = player.printSmCards(6);
	for (int i = 261; i > 53; i--) {
		gFooTexture.render(31, i);
		if (countCards == 2) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 3) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 4) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 5) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 6) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 7) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			anCard(card_dw_7, 80, 470);
			SDL_RenderPresent(gRenderer);
		}
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 480; i++) {
		gFooTexture.render(i, 53);
		if (countCards == 2) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 3) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 4) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 5) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 6) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 7) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			anCard(card_dw_7, 80, 470);
			SDL_RenderPresent(gRenderer);
		}
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}

	//gFooTexture.render(680, 53);
	//gFooTexture.render(580, 53);
	SDL_RenderPresent(gRenderer);
}

void upCard_4(player player, string card_up_1, string card_up_2, string card_up_3) {
	string card_dw_1 = player.printSmCards(0);
	string card_dw_2 = player.printSmCards(1);
	string card_dw_3 = player.printSmCards(2);
	string card_dw_4 = player.printSmCards(3);
	string card_dw_5 = player.printSmCards(4);
	string card_dw_6 = player.printSmCards(5);
	string card_dw_7 = player.printSmCards(6);
	for (int i = 261; i > 53; i--) {
		gFooTexture.render(31, i);
		if (countCards == 2) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 3) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 4) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 5) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 6) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 7) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			anCard(card_dw_7, 80, 470);
			SDL_RenderPresent(gRenderer);
		}
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 380; i++) {
		gFooTexture.render(i, 53);
		if (countCards == 2) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 3) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 4) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 5) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 6) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 7) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			anCard(card_dw_7, 80, 470);
			SDL_RenderPresent(gRenderer);
		}
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}

	//gFooTexture.render(680, 53);
	//gFooTexture.render(580, 53);
	SDL_RenderPresent(gRenderer);
}

void upCard_5(player player, string card_up_1, string card_up_2, string card_up_3, string card_up_4) {
	string card_dw_1 = player.printSmCards(0);
	string card_dw_2 = player.printSmCards(1);
	string card_dw_3 = player.printSmCards(2);
	string card_dw_4 = player.printSmCards(3);
	string card_dw_5 = player.printSmCards(4);
	string card_dw_6 = player.printSmCards(5);
	string card_dw_7 = player.printSmCards(6);
	for (int i = 261; i > 53; i--) {
		gFooTexture.render(31, i);
		if (countCards == 2) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 3) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 4) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 5) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 6) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 7) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			anCard(card_dw_7, 80, 470);
			SDL_RenderPresent(gRenderer);
		}
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 280; i++) {
		gFooTexture.render(i, 53);
		if (countCards == 2) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 3) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 4) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 5) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 6) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 7) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			anCard(card_dw_7, 80, 470);
			SDL_RenderPresent(gRenderer);
		}
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}

	//gFooTexture.render(680, 53);
	//gFooTexture.render(580, 53);
	SDL_RenderPresent(gRenderer);
}

void upCard_6(player player, string card_up_1, string card_up_2, string card_up_3, string card_up_4, string card_up_5) {
	string card_dw_1 = player.printSmCards(0);
	string card_dw_2 = player.printSmCards(1);
	string card_dw_3 = player.printSmCards(2);
	string card_dw_4 = player.printSmCards(3);
	string card_dw_5 = player.printSmCards(4);
	string card_dw_6 = player.printSmCards(5);
	string card_dw_7 = player.printSmCards(6);
	for (int i = 261; i > 53; i--) {
		gFooTexture.render(31, i);
		if (countCards == 2) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 3) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 4) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 5) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 6) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 7) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			anCard(card_dw_7, 80, 470);
			SDL_RenderPresent(gRenderer);
		}
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 180; i++) {
		gFooTexture.render(i, 53);
		if (countCards == 2) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 3) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 4) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 5) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 6) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 7) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			anCard(card_dw_7, 80, 470);
			SDL_RenderPresent(gRenderer);
		}
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}

	//gFooTexture.render(680, 53);
	//gFooTexture.render(580, 53);
	SDL_RenderPresent(gRenderer);
}

void upCard_7(player player, string card_up_1, string card_up_2, string card_up_3, string card_up_4, string card_up_5, string card_up_6) {
	string card_dw_1 = player.printSmCards(0);
	string card_dw_2 = player.printSmCards(1);
	string card_dw_3 = player.printSmCards(2);
	string card_dw_4 = player.printSmCards(3);
	string card_dw_5 = player.printSmCards(4);
	string card_dw_6 = player.printSmCards(5);
	string card_dw_7 = player.printSmCards(6);
	for (int i = 261; i > 53; i--) {
		gFooTexture.render(31, i);
		if (countCards == 2) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_up_6, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 3) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_up_6, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 4) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_up_6, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 5) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_up_6, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 6) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_up_6, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 7) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_up_6, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			anCard(card_dw_7, 80, 470);
			SDL_RenderPresent(gRenderer);
		}
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}
	for (int i = 31; i < 80; i++) {
		gFooTexture.render(i, 53);
		if (countCards == 2) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_up_6, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 3) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_up_6, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 4) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_up_6, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 5) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_up_6, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 6) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_up_6, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			SDL_RenderPresent(gRenderer);
		}
		if (countCards == 7) {
			anCard(card_up_1, 680, 53);
			anCard(card_up_2, 580, 53);
			anCard(card_up_3, 480, 53);
			anCard(card_up_4, 380, 53);
			anCard(card_up_5, 280, 53);
			anCard(card_up_6, 280, 53);
			anCard(card_dw_1, 680, 470);
			anCard(card_dw_2, 580, 470);
			anCard(card_dw_3, 480, 470);
			anCard(card_dw_4, 380, 470);
			anCard(card_dw_5, 280, 470);
			anCard(card_dw_6, 180, 470);
			anCard(card_dw_7, 80, 470);
			SDL_RenderPresent(gRenderer);
		}
		gBackgroundTexture.render(0, 0);
		SDL_Delay(1);
	}

	//gFooTexture.render(680, 53);
	//gFooTexture.render(580, 53);
	SDL_RenderPresent(gRenderer);
}

void anCount(int counter, int x, int y) {
	if (counter == 4) gFooTexture_4.render(x, y);
	if (counter == 5) gFooTexture_5.render(x, y);
	if (counter == 6) gFooTexture_6.render(x, y);
	if (counter == 7) gFooTexture_7.render(x, y);
	if (counter == 8) gFooTexture_8.render(x, y);
	if (counter == 9) gFooTexture_9.render(x, y);
	if (counter == 10) gFooTexture_10.render(x, y);
	if (counter == 11) gFooTexture_11.render(x, y);
	if (counter == 12) gFooTexture_12.render(x, y);
	if (counter == 13) gFooTexture_13.render(x, y);
	if (counter == 14) gFooTexture_14.render(x, y);
	if (counter == 15) gFooTexture_15.render(x, y);
	if (counter == 16) gFooTexture_16.render(x, y);
	if (counter == 17) gFooTexture_17.render(x, y);
	if (counter == 18) gFooTexture_18.render(x, y);
	if (counter == 19) gFooTexture_19.render(x, y);
	if (counter == 20) gFooTexture_20.render(x, y);
	if (counter == 21) gFooTexture_21.render(x, y);
	if (counter == 22) gFooTexture_22.render(x, y);
	if (counter == 23) gFooTexture_23.render(x, y);
	if (counter == 24) gFooTexture_24.render(x, y);
	if (counter == 25) gFooTexture_25.render(x, y);
	if (counter == 26) gFooTexture_26.render(x, y);
	if (counter == 27) gFooTexture_27.render(x, y);
	if (counter == 28) gFooTexture_28.render(x, y);
	if (counter == 29) gFooTexture_29.render(x, y);
	if (counter == 30) gFooTexture_30.render(x, y);
}

void LButton::render()
{
	//Show current button sprite
	gButtonSpriteSheetTexture.render(mPosition.x, mPosition.y, &gSpriteClips[mCurrentSprite]);
}

void LButton::render2()
{
	//Show current button sprite
	gButtonSpriteSheetTexture2.render(mPosition.x, mPosition.y, &gSpriteClips[mCurrentSprite]);
}

void LButton::renderPrePlay()
{
	gFooTexture_pre_play.render(mPosition.x, mPosition.y, &gSpriteClipsPrePlay[mCurrentSprite]);

}

void LButton::renderRegLog()
{
	gFooTexture_register_login.render(mPosition.x, mPosition.y, &gSpriteClipsRegLog[mCurrentSprite]);

}

void LButton::renderST()
{
	gFooTexture_start.render(mPosition.x, mPosition.y, &gSpriteClips_st[mCurrentSprite]);

}

void LButton::renderAch()
{
	gAch.render(mPosition.x, mPosition.y, &gSpriteClipsAch[mCurrentSprite]);

}

void LButton::renderShop()
{
	gShop.render(mPosition.x, mPosition.y, &gSpriteClipsShop[mCurrentSprite]);

}

void LButton::renderBack()
{
	gBack.render(mPosition.x, mPosition.y, &gSpriteClipsBack[mCurrentSprite]);

}

void LButton::renderBoards() {
	gbutton_board.render(mPosition.x, mPosition.y, &gSpriteClipsBoards[mCurrentSprite]);

}

void LButton::renderCards() {
	gbutton_cards.render(mPosition.x, mPosition.y, &gSpriteClipsCards[mCurrentSprite]);
}

void LButton::renderf10() {
	f10.render(mPosition.x, mPosition.y, &gSpriteClipsf10[mCurrentSprite]);
}

void LButton::renderf25() {
	f25.render(mPosition.x, mPosition.y, &gSpriteClipsf25[mCurrentSprite]);
}

void LButton::renderf50() {
	f50.render(mPosition.x, mPosition.y, &gSpriteClipsf50[mCurrentSprite]);
}

void LButton::renderf200() {
	f200.render(mPosition.x, mPosition.y, &gSpriteClipsf200[mCurrentSprite]);
}


void LButton::handleEvent(SDL_Event* e, player player, deck cards, string card_up_1, string card_up_2, string  card_dw_1, string  card_dw_2, string card_dw_3, char h_s)
{
	if (h_s == 'h') {
		//If mouse event happened
		if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + BUTTON_WIDTH)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + BUTTON_HEIGHT)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (e->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;

					if (countCards == 2) {

						dwCard_3(card_up_1, card_dw_1, card_dw_2);
						string card_dw_3 = player.printSmCards(2);
						anCard(card_dw_3, 480, 470);

						countCards++;

						break;
					}

					if (countCards == 3) {
						string card_dw_3 = player.printSmCards(2);
						dwCard_4(card_up_1, card_dw_1, card_dw_2, card_dw_3);

						anCard(card_dw_3, 480, 470);
						string card_dw_4 = player.printSmCards(3);
						anCard(card_dw_4, 380, 470);

						countCards++;
						//cout << player.getCheckSum() << endl;
						break;
					}

					if (countCards == 4) {

						card_dw_3 = player.printSmCards(2);
						string card_dw_4 = player.printSmCards(3);
						dwCard_5(card_up_1, card_dw_1, card_dw_2, card_dw_3, card_dw_4);
						string card_dw_5 = player.printSmCards(4);
						anCard(card_dw_5, 280, 470);
						countCards++;
						break;
					}

					if (countCards == 5) {
						string card_dw_3 = player.printSmCards(2);
						string card_dw_4 = player.printSmCards(3);
						string card_dw_5 = player.printSmCards(4);
						string card_dw_6 = player.printSmCards(5);
						dwCard_6(card_up_1, card_dw_1, card_dw_2, card_dw_3, card_dw_4, card_dw_5);
						anCard(card_dw_6, 180, 470);
						countCards++;
						break;
					}

					if (countCards == 6) {
						string card_dw_3 = player.printSmCards(2);
						string card_dw_4 = player.printSmCards(3);
						string card_dw_5 = player.printSmCards(4);
						string card_dw_6 = player.printSmCards(5);
						string card_dw_7 = player.printSmCards(6);
						dwCard_7(card_up_1, card_dw_1, card_dw_2, card_dw_3, card_dw_4, card_dw_5, card_dw_6);
						anCard(card_dw_7, 80, 470);
						countCards++;
						break;
					}
					break;
				}
			}
		}
	}

	if (h_s == 's') {
		//If mouse event happened
		if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + BUTTON_WIDTH)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + BUTTON_HEIGHT)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (e->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
					anCard(card_up_2, 580, 53);
					countCardsS++;
					//cout << "KYKAREKY" << endl;
					break;

				}
			}
		}
	}

}

void LButton::handleEventPre(SDL_Event* pre, char p_r) {
	if (p_r == 'p') {
		//If mouse event happened
		if (pre->type == SDL_MOUSEMOTION || pre->type == SDL_MOUSEBUTTONDOWN || pre->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + BUTTON_WIDTH_pre)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + BUTTON_HEIGHT_pre)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (pre->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;

					SDL_DestroyRenderer(gRenderer);
					SDL_DestroyWindow(gWindow);
					gWindow = NULL;
					gRenderer = NULL;

					start("demo");
					//cout << "KYKAREKY" << endl;
					break;

				}
			}
		}
	}

	if (p_r == 'r') {
		//If mouse event happened
		if (pre->type == SDL_MOUSEMOTION || pre->type == SDL_MOUSEBUTTONDOWN || pre->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + BUTTON_WIDTH_reg)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + BUTTON_HEIGHT_reg)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (pre->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;

					SDL_DestroyRenderer(gRenderer);
					SDL_DestroyWindow(gWindow);
					gWindow = NULL;
					gRenderer = NULL;

					register_();

					//cout << "KYKAREKY" << endl;
					break;

				}
			}
		}
	}
}

void LButton::handleEventStart(SDL_Event* str, char st) {
	//cout << "ewrwerwerwerwer";
	if (st == 'S') {
		//cout << "ewrwerwerwerwer";		//If mouse event happened
		if (str->type == SDL_MOUSEMOTION || str->type == SDL_MOUSEBUTTONDOWN || str->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + 248)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + 100)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (str->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;

					SDL_DestroyRenderer(gRenderer);
					SDL_DestroyWindow(gWindow);
					gWindow = NULL;
					gRenderer = NULL;

					start("demo");
					break;

				}
			}
		}
	}
}

void LButton::handleEventAch(SDL_Event* str, char st) {
	if (st == 'A') {
		//cout << "ewrwerwerwerwer";		//If mouse event happened
		if (str->type == SDL_MOUSEMOTION || str->type == SDL_MOUSEBUTTONDOWN || str->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + 248)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + 100)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (str->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;

					SDL_DestroyRenderer(gRenderer);
					SDL_DestroyWindow(gWindow);
					gWindow = NULL;
					gRenderer = NULL;

					achiv();
					break;

				}
			}
		}
	}
}

void LButton::handleEventShop(SDL_Event* str, char st) {
	if (st == 'S') {
		//cout << "ewrwerwerwerwer";		//If mouse event happened
		if (str->type == SDL_MOUSEMOTION || str->type == SDL_MOUSEBUTTONDOWN || str->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + 248)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + 100)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (str->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;

					SDL_DestroyRenderer(gRenderer);
					SDL_DestroyWindow(gWindow);
					gWindow = NULL;
					gRenderer = NULL;

					shop_cards();
					break;

				}
			}
		}
	}
}

void LButton::handleEventBack(SDL_Event* str, char st) {
	if (st == 'S') {
		//cout << "ewrwerwerwerwer";		//If mouse event happened
		if (str->type == SDL_MOUSEMOTION || str->type == SDL_MOUSEBUTTONDOWN || str->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + 248)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + 100)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (str->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;

					SDL_DestroyRenderer(gRenderer);
					SDL_DestroyWindow(gWindow);
					gWindow = NULL;
					gRenderer = NULL;

					main_manu();
					break;

				}
			}
		}
	}
}

void LButton::handleEventBoards(SDL_Event* str, char st) {
	if (st == 'S') {
		//cout << "ewrwerwerwerwer";		//If mouse event happened
		if (str->type == SDL_MOUSEMOTION || str->type == SDL_MOUSEBUTTONDOWN || str->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + 248)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + 100)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (str->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;

					SDL_DestroyRenderer(gRenderer);
					SDL_DestroyWindow(gWindow);
					gWindow = NULL;
					gRenderer = NULL;

					shop_fields();
					break;

				}
			}
		}
	}
}

void LButton::handleEventCards(SDL_Event* str, char st) {
	if (st == 'S') {
		//cout << "ewrwerwerwerwer";		//If mouse event happened
		if (str->type == SDL_MOUSEMOTION || str->type == SDL_MOUSEBUTTONDOWN || str->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + 248)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + 100)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (str->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;

					SDL_DestroyRenderer(gRenderer);
					SDL_DestroyWindow(gWindow);
					gWindow = NULL;
					gRenderer = NULL;

					shop_cards();
					break;

				}
			}
		}
	}
}

void LButton::handleEventf10(SDL_Event* str, char st) {
	if (st == 'f') {
		//cout << "ewrwerwerwerwer";		//If mouse event happened
		if (str->type == SDL_MOUSEMOTION || str->type == SDL_MOUSEBUTTONDOWN || str->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + 150)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + 100)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (str->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
					break;

				}
			}
		}
	}
}

void LButton::handleEventf25(SDL_Event* str, char st) {
	if (st == 'f') {
		//cout << "ewrwerwerwerwer";		//If mouse event happened
		if (str->type == SDL_MOUSEMOTION || str->type == SDL_MOUSEBUTTONDOWN || str->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + 150)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + 100)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (str->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
					break;

				}
			}
		}
	}
}

void LButton::handleEventf50(SDL_Event* str, char st) {
	if (st == 'f') {
		//cout << "ewrwerwerwerwer";		//If mouse event happened
		if (str->type == SDL_MOUSEMOTION || str->type == SDL_MOUSEBUTTONDOWN || str->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + 150)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + 100)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (str->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
					break;

				}
			}
		}
	}
}

void LButton::handleEventf200(SDL_Event* str, char st) {
	if (st == 'f') {
		//cout << "ewrwerwerwerwer";		//If mouse event happened
		if (str->type == SDL_MOUSEMOTION || str->type == SDL_MOUSEBUTTONDOWN || str->type == SDL_MOUSEBUTTONUP)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < mPosition.x)
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > mPosition.x + 150)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < mPosition.y)
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > mPosition.y + 100)
			{
				inside = false;
			}

			//Mouse is outside button
			if (!inside)
			{
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				switch (str->type)
				{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;

				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;

				case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
					break;

				}
			}
		}
	}
}

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

void reg()
{
	string login, pass;
	cout << "Enter login to log or register: " << endl;
	cin >> login;
	cout << "Enter password: " << endl;
	cin >> pass;

	//if(login == "info from db") // ->> if(password == "pass from bd") ->
	//else login+ to DB, pssword + to DB 

	if (1 == 1) {
		//
		main_manu();
	}
	else {
		cout << "some";
	}
}
