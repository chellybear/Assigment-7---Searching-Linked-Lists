/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/
// Includes assignment header file
#include "MyHeader.h"

void OutputTitle(DvdRec *head, ofstream& oFile)
{
	DvdRec *dvdPtr;		// CALC & OUT - pointer for dvdPtr
//
	dvdPtr = NULL;	// Initializes dvdPtr to null
	dvdPtr = head;	// Assigns head to dvdPtr

	// Align left
	oFile << left;
	// Outputs * up to the specified width
	oFile << setfill('*') << setw(75) << '*' << setfill(' ') << endl;
	// Outputs movie title
	// IF the title is longer than specified length, will output ...
	// ELSE, will output the whole title
	if(dvdPtr->title.length() > 52)
	{
		oFile << "Title: " << dvdPtr->title.substr(0, 52)
			  << "..." << endl;
	}
	else
	{
		oFile << "Title: " << dvdPtr->title << endl;
	}
	// Outputs - up to the specified width
	oFile << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
	// Outputs year and rating
	oFile << setw(6) << "Year: " << setw(14) << dvdPtr->year
		  << "Rating: " << dvdPtr->rating << endl;
	// Outputs - up to the specified width
	oFile << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
	// Outputs leading actor and genre1
	oFile << setw(20)
		  << "Leading Actor:" << setw(26) << dvdPtr->leadActor
		  << "Genre 1: " << dvdPtr->genre1 << endl;
	// Outputs supporting actor and genre2
	oFile << setw(20)
		  << "Supporting Actor:" << setw(26) << dvdPtr->suppActor
		  << "Genre 2: " << dvdPtr->genre2 << endl;
	// Outputs - up to the specified width
	oFile << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
	// Outputs word-wrapped synopsis
	oFile << "PLOT:" << endl;
	WordWrap(head, oFile);
	oFile << dvdPtr->synopsis << endl;
	// Outputs * up to the specified width
	oFile << setfill('*') << setw(75) << '*' << setfill(' ') << endl;
	oFile << endl;
}
