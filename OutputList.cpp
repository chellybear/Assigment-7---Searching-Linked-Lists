/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/
// Includes assignment header file
#include "MyHeader.h"

// This function outputs the linked list
void OutputList(DvdRec *head, ofstream& oFile, int& count)
{
	DvdRec *dvdPtr;		// Declares pointer for dvdPtr
	dvdPtr = head;		// Points dvdPtr to head

	// Outputs certain length of title
	oFile << right << setw(5) << count + 1 << "    " << left;

	// If title is too long will output "..."
	if(dvdPtr->title.length() > 40)
	{
		oFile << setw(43) << dvdPtr->title.substr(0, 40)
			  << "...";
	}
	else
	{
		oFile << setw(46) << dvdPtr->title;
	}
	// Outputs the year, rating, genres, and actors of the movie
	oFile << right << setw(7) << dvdPtr->year
		  << setw(5) << dvdPtr->rating << "   " << left
		  << setw(16) << dvdPtr->genre1
		  << setw(16) << dvdPtr->genre2
		  << setw(19) << dvdPtr->leadActor
		  << dvdPtr->suppActor << endl;
}
