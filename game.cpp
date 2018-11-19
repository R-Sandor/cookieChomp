#include <iostream>
#include "game.h"
using namespace std;
/**
 * Release any storage held by a game
 *
 * @param g  a no-longer-needed game
 */
void cleanUpGame (Game& g)
{
	cleanUpCookie(g.cookie);
}

/**
 * Check to see if the current game has been ended
 * (i.e., has someone eaten the poison crumb?)
 *
 * @param g  the game
 * @return  true iff the poison has been eaten
 */
bool gameEnded(const Game& g)
{
	return getNumberOfColumns(g.cookie) <= 0;
}


/**
 * Create a new game with a cookie of random size
 *
 * @param g   newly initialized game
 */
void initializeGame(Game& g)
{
	initCookie (g.cookie);
	cout << "The cookie has " << getNumberOfRows(g.cookie) << " rows of "
			<< getNumberOfColumns(g.cookie) << " columns" << endl;
}



void printRules()
{
	cout << "Chomp is a game played with a rectangular \"cookie\" made\n"
			<< "up of square \"crumbs\".\n\n";
	cout << "Taking turns, each player takes a bite from the cookie,\n"
			<< "selecting a crumb that is removed from the cookie, together\n"
			<< "with all crumbs below and to the right of the selected one.\n\n";
	cout << "The top-left crumb in this cookie is poisoned. The player\n"
			<< "who eats the poisoned crumb loses the game.\n" << endl;

}

/**
 * Check a proposed move to see if it is legal.
 * A legal move must bite at least one remaining crumb.
 *
 * @param g a game
 * @param column x position of the desred bite
 * @param row y position of the desired bite
 * @return true iff this move is legal
 */
bool biteIsLegal (const Game& g, int column, int row)
{
	return (column >= 0) && (row >= 0) && row < getNumberOfRows(g.cookie)
			&& (column < getNumberOfColumns(g.cookie,row));
}


