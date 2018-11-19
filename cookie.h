#ifndef COOKIE_H_INCLUDED 
#define COOKIE_H_INCLUDED 

#include <iostream>



struct Cookie {


	int initialNumberOfRows;

	/// Number of rows currently remaining in the cookie
	int numberOfRows;

	/// Number of columns currently remaining in the cookie
	int numberOfColumns;


	/**
	 * The "shape" of the cookie.
	 *
	 * If crumbs[i] == j, then the cookie currently
	 * has crumbs filling the j columns at row i
	 */
	int* crumbs;
};



/**
 * Number of non-empty rows currently remaining in the cookie
 *    (value decreases as we continue to take bites)
 *
 * @param cookie the cookie
 * @return number of non-empty rows in the cookie
 */
int getNumberOfRows(const Cookie& cookie);

/**
 * The number of rows remaining in a specific column
 * @param cookie   the cookie
 * @param colNum   a column number in the cookie
 * @return   number of non-empty rows remaining in that column
 */
int getNumberOfRows(const Cookie& cookie, int colNum);

/**
 * Number of non-empty columns currently remaining in the cookie
 * @param cookie the cookie
 * @return number of non-empty columns
 */
int getNumberOfColumns(const Cookie& cookie);

/**
 * The number of columns remaining in a specific row
 * @param cookie a cookie
 * @param rowNum a row
 * @return  number of non-empty columns in that row
 */
int getNumberOfColumns(const Cookie& cookie, int rowNum);

/**
 * Remove the crumb at the indicated position and
 *   all crumbs below and to the right of that position.
 * @param cookie   cookie from which we want to take a bite
 * @param column   column of desired bite
 * @param row      row of desired biete
 */
void takeABite (Cookie& cookie, int column, int row);



void cleanUpCookie(Cookie& cookie);

void display (std::ostream& output, const Cookie& cookie);

void initCookie(Cookie& cookie);

#endif
