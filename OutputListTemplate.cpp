/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/
// Includes assignment header file
#include "MyHeader.h"

// This function outputs the list template for OutputList
void OutputListTemplate(ofstream& oFile)
{
	// Align left
	oFile << left;
	// Outputs list layout
	oFile << setw(9) << " MOVIE #" << setw(46) << "TITLE"
		 << right << setw(7) << "YEAR" << setw(7) << left << " RATING"
		 << setw(16) << " GENRE" << setw(16) << " ALT GENRE"
		 << setw(19) << " LEAD ACTOR" << " SUPPORTING ACTOR" << endl;
	// Setfill to - to make dashes underneath list layout
	oFile << setfill('-') << setw(8) << " " << setw(49) << " "
		  << setw(5) << " " << setw(7) << " " << setw(16) << " "
		  << setw(16) << " " << setw(19) <<  " " << setw(21) << " "
		  << setw(19)
		  << setfill(' ') << endl;
}
