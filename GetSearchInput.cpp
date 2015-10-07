/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/
// Includes assignment header file
#include "MyHeader.h"

// This function prompts user to input searchItem based on search type
string GetSearchInput(int& choice)
{
	string searchItem;	// IN & CALC & OUT - string to searched, input
						// 					 by user
	// Outputs message according to type of search
	switch(choice)
	{
	case TITLESEARCH:
		cout << "\nWhich title are you looking for? ";
		getline(cin, searchItem);
		cout << "\nSearching for the title " << searchItem << endl;
		break;
	case GENRESEARCH:
		cout << "\nWhich genre are you looking for? ";
		getline(cin, searchItem);
		cout << "\nSearching for the genre " << searchItem << endl;
		break;
	case ACTORSEARCH:
		cout << "\nWhich actor are you looking for? ";
		getline(cin, searchItem);
		cout << "\nSearching for the actor " << searchItem << endl;
		break;
	default:
		cout << "\nSomething went wrong. How did you get here?\n";
		break;

	}
	// Returns the string to be searched
	return searchItem;

}
