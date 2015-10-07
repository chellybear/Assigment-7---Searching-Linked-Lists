/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/
// Includes assignment header file
#include "MyHeader.h"

void WordWrap(DvdRec *head, ofstream& oFile)
{
	DvdRec *dvdPtr;	// CALC - pointer for dvdPtr
	int maxLength;	// CALC - the maximum length before word-wrap
	int inputStr;	// IN & CALC - the length of the string input
	int index;		// CALC - counts until inputStr is reached
	string word;	// CALC & OUT - outputs the next word of the synopsis
	string line;	// CALC & OUT - outputs the whole line of the synopsis

	dvdPtr = NULL;						// Sets dvdPtr to null
	dvdPtr = head;						// Assigns head to dvdPtr
	inputStr = dvdPtr->synopsis.size(); // Assigns the size of the synopsis
										// to inputStr
	maxLength = 72;					    // Sets maxLength to 72

	// While index is less than size of inputStr, will check if the char
	// is not ' ', then adds it to word
	for(index = 0; index < inputStr; index++)
	{
		if(dvdPtr->synopsis[index] != ' ')
		{
			word += dvdPtr->synopsis[index];
		}
		else
		{
			// If the line and word length are greater than/equal to the
			// maxLength, will output the whole line and clear the next
			if((line.length() + word.length()) >= maxLength)
			{
				oFile << line << endl;
				line.clear();
			}
			line += word + ' ';
			word.clear();
		}
	}
	// Outputs the last line and last word
	oFile << line << word;
	dvdPtr->synopsis.clear();
}
