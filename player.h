#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>

struct Player {
	std::string name;
	int numGamesWon;
};


void initPlayer (Player& player, std::string name);

#endif 
