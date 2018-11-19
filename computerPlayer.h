#ifndef COMPUTERPLAYER_H_INCLUDED
#define COMPUTERPLAYER_H_INCLUDED

#include "game.h" 
#include "cookie.h" 


/**
 * Determines if a proposed bite by the computer player could allow
 * a skillful opponent to force a loss.
 *
 * @param cookie   current cookie
 * @param column   column of porposed bite
 * @param row      row of proposed byte
 * @return         true if choosing this bite could lead to a forced loss
 */
bool isADangerousMove (Cookie& cookie, int column, int row);

bool computerPlayerMustLose
(Cookie& cookie, int& column, int& row,
		int maxColumns, int lastNonEmptyRow);
bool computerPlayerCanForceAWin
(Cookie& cookie,
		int& column, int& row,
		int maxColumns, int lastNonEmptyRow);

void getComputerPlayerMove (Cookie& cookie, int& column, int& row);


#endif // COMPUTERPLAYER_H_INCLUDED
