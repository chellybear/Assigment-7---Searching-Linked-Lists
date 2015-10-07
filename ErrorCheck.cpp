/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/
// Includes assignment header file
#include "MyHeader.h"

// This function error checks the user's menu input
int ErrorCheck(const int min, const int max)
{
	int validInt;   // INPUT - Choice input by user
	bool invalid;   // CALC - If choice is valid, will be false

	invalid = true;

	do
	{
		// Error checks input
		if(!(cin >> validInt))
		{
			cout << "\n**** Please input a NUMBER between " << min
			     << " and " << max << " ****\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		// If choice is is out of bounds, will output message
		else if (validInt < min || validInt > max)
		{
			cout << "\n**** The number " << validInt
			     << " is an invalid entry      ****\n"
					"**** Please input a NUMBER between "
			     << min << " and " << max << " ****\n\n";
		}
		// If input is valid, will exit do-while loop
		else
		{
			invalid = false;
		}
	}while(invalid); // Exit do-while loop

	cin.ignore(1000, '\n');
	// Return's user's menu choice
	return validInt;
}
