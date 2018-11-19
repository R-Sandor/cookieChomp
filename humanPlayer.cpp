#include <iostream>
#include "humanPlayer.h"
using namespace std;

void getHumanPlayerMove (Cookie& cookie, int& column, int& row)
{
	cout << "Your turn to take a bite from the cookie.\n";
	cout << "Enter the column number and row number at which\n";
	cout << "  you wish to chomp (separated by a blank space): " << flush;
	cin >> column >> row;
	if (cin.fail()) {
		cin.clear();
		std::string junk;
		getline(cin, junk); // discard rest of this input line
	}
}



