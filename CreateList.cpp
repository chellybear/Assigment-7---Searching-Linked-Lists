/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/
// Includes assignment header file
#include "MyHeader.h"

DvdRec *CreateList(ifstream& inFile)
{
	DvdRec *head;		// CALC - head of list
	DvdRec *dvdPtr;		// CALC & OUT - pointer for dvdPtr

	head = NULL;		// Initialized to NULL to indicate empty list
	dvdPtr = new DvdRec;// Creates new DvdRec node

	// While there is still information in inFile, will get the specified
	// information
	while(inFile && dvdPtr != NULL)
	{
		getline(inFile, dvdPtr->title);
		getline(inFile, dvdPtr->leadActor);
		getline(inFile, dvdPtr->suppActor);
		getline(inFile, dvdPtr->genre1);
		getline(inFile, dvdPtr->genre2);
		inFile >> dvdPtr->year;
		inFile.ignore(1000,'\n');
		inFile >> dvdPtr->rating;
		inFile.ignore(1000,'\n');
		getline(inFile, dvdPtr->synopsis);
		inFile.ignore(1000,'\n');

		// Points head of list to the next node
		dvdPtr->next = head;
		// Assigns head to dvdPtr
		head = dvdPtr;
		// Creates a new node for DvdRec
		dvdPtr = new DvdRec;
	}
	// Delete pointer
	delete dvdPtr;
	// Set pointer to null
	dvdPtr = NULL;
	// Returns information in head
	return head;
}
