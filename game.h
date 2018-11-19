#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED 

#include "cookie.h"


struct Game {

	/// The cookie for this game.
	Cookie cookie;
};

bool biteIsLegal (const Game& g, int column, int row);

void cleanUpGame (Game& g);

bool gameEnded(const Game& g);

void initializeGame(Game& g);

void printRules();

#endif
