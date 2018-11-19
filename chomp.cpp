#include <cstdlib>
#include <sys/types.h>
#include <ctime>
#include <iostream>
#include <string>

#include "computerPlayer.h"
#include "cookie.h"
#include "game.h"
#include "humanPlayer.h"
#include "player.h"
using namespace std;


/**
 * A cookie in the game of chomp. A cookie is begins as
 * a rectangular arrangement of "crumbs". We can then take
 * bites at specific locations. A byte at (x,y) eliminates the
 * crumb at that location and all crumbs below and to the right.
 * For example, given a cookie
 *     %%%%
 *     %%%%
 *     %%%%
 *     %%%%
 * a bite at (1,2) would leave:
 *     %%%%
 *     %%%%
 *     %
 *     %
 * after which, a second bite at (2,1) would leave
 *     %%%%
 *     %%
 *     %
 *     %
 */

Player computer = {"computer", 0};
Player human = {"", 0};



void printScore(Player& human, Player& computer)
{
	cout << "Score\tComputer: " << computer.numGamesWon
			<< "\t" << human.name << ": " << human.numGamesWon
			<< endl;
}

void initHumanPlayer(Player& human)
{
	human.numGamesWon = 0;
	cout << "Welcome to Chomp!\n"
			<< "What is your name? "
			<< flush;
	getline (cin, human.name);

	cout << "OK, " << human.name << ", let's play." << endl;
}


/**
 * Play an entire game
 * @param game    the game with an initialized cookie
 * @param human   human player
 * @param computer computer player
 */
void playAGame(Game& game, Player& human, Player& computer)
{
	while (!gameEnded(game))
	{
		display (cout, game.cookie);

		// First, the human player's move
		int xBite = -1;
		int yBite = -1;
		bool legalMove = false;
		while (!legalMove)
		{
			getHumanPlayerMove (game.cookie, xBite, yBite);
			legalMove = biteIsLegal (game, xBite, yBite);
			if (!legalMove)
			{
				cout << "Sorry, but that is not a legal move." << endl;
			}
		}
		takeABite (game.cookie, xBite, yBite);
		if (gameEnded(game))
		{
			++computer.numGamesWon;
			cout << "You have eaten the poison crumb! You lose." << endl;
		}
		else
		{
			// Computer player's move
			display (cout, game.cookie);
			getComputerPlayerMove (game.cookie, xBite, yBite);
			cout << "I will chomp at column " << xBite
					<< ", row " << yBite << "." << endl;
			takeABite (game.cookie, xBite, yBite);
			if (gameEnded(game))
			{
				++human.numGamesWon;
				cout << "I had to eat the poison crumb. You win!"
						<< endl;
			}
		}

	}
}










int main (int argc, char** argv)
{
	// Start the random number generator
	int seed = 12371;
	if (argc == 1)
		seed = time(0);
	srand (seed);


	printRules();

	bool playAnotherGame = true;
	while (playAnotherGame)
	{
		Game game;
		initializeGame(game);
		playAGame(game, human, computer);
		printScore(human, computer);
		cout << "Play again? (Y/N) " << flush;
		string response;
		playAnotherGame = false;
		while (response == "" && cin >> response)
		{
			if (response[0] == 'Y' || response[0] == 'y' ||
					response[0] == 'N' || response[0] == 'n')
				playAnotherGame = response[0] == 'Y' || response[0] == 'y';
			else
				response = "";
		}
		cleanUpGame(game);
	}
	return 0;
}










