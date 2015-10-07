/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/
// Includes assignment header file
#include "MyHeader.h"

// This function prompts user to input searchInt based on search type
int GetSearchInt(int& choice)
{
	int searchInt;	// IN & OUT & CALC - int to searched, input
					// 					 by user
	searchInt = 0;  // Initialize searchInt to 0

	// Will prompt user to input searchInt based on menu choice
	switch(choice)
	{
	case YEARSEARCH:
		cout << "\nWhich year are you looking for? ";
		searchInt = ErrorCheck(1878, 3000);
		cout << "\nSearching for the year " << searchInt << endl;
		break;
	case RATINGSEARCH:
		cout << "\nWhich rating are you looking for? ";
		searchInt = ErrorCheck(0, 9);
		cout << "\nSearching for the rating " << searchInt << endl;
		break;
	default:
		cout << "\nYou shouldn't have done that.\n";
		break;
	}

	// Returns int to be searched
	return searchInt;
}
