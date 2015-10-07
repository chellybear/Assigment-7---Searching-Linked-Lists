/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/
// Includes assignment header file
#include "MyHeader.h"

int main()
{
	/*********************************************************************
	 * ASSIGNMENT 7 - SEARCHING LINKED LISTS
	 *____________________________________________________________________
	 * This program will create a linked list based on input file. It will
	 * allow the user to make searches within the linked list. It will
	 * output found searches to an output file.
	 *____________________________________________________________________
	 * INPUT :
	 *  dvdPtr->title	  :	Title of movie
	 *	dvdPtr->leadActor : Lead actor
	 *	dvdPtr->suppActor : Supporting actor
	 *	dvdPtr->genre1	  : Genre of movie
	 *	dvdPtr->genre2	  : Alt. Genre of movie
	 *	dvdPtr->year      : Year of movie
	 *	dvdPtr->rating    : Movie rating
	 *	dvdPtr->synopsis) : Summary of movie
	 *
	 * CALC  :
	 * 	head 			  : head of the list
	 * OUTPUT:
	 *  dvdPtr->title	  :	Title of movie
	 *	dvdPtr->leadActor : Lead actor
	 *	dvdPtr->suppActor : Supporting actor
	 *	dvdPtr->genre1	  : Genre of movie
	 *	dvdPtr->genre2	  : Alt. Genre of movie
	 *	dvdPtr->year      : Year of movie
	 *	dvdPtr->rating    : Movie rating
	 *	dvdPtr->synopsis) : Summary of movie
	 *	head 			  : head of the list
	 *********************************************************************/

	DvdRec *head;		// CALC & OUT - head of linked list
	DvdRec *dvdPtr; 	// CALC & OUT - dvdPtr points to head of linked
						// list
	ifstream inFile;	// Declares input file stream inFile
	ofstream oFile; 	// Declares ouput file stream oFile
	int choice;			// IN & CALC - menu choice input by user
	int count;			// CALC & OUT - number of movie on list
	string searchItem;	// IN & CALC & OUT - string to be input by user
	int searchInt;		// IN & CALC & OUT - int to be input by user

	choice = 0;			// Initialize menu choice to 0
	count = 0;			// Initialize count to 0
	searchInt = 0;		// Initialize int to be searched to 0
	head = NULL;		// Point head to NULL
	dvdPtr = new DvdRec;// Create new DvdRec node

	// Align left
	cout << left;
	// Outputs print header
	PrintHeader("Searching Linked Lists", 'A', 7);
	// Specifies inFile and oFile to be used
	SpecifyFile(inFile, oFile);
	// Creates list after specifying inFile
	head = CreateList(inFile);
	dvdPtr = head;
	// Display menu
	DisplayMenu();
	// Prompt user for input, error check it (Initialize LCV)
	choice = ErrorCheck(0,6);
	// Will loop until choice is 0 for exit
	while(choice != 0)
	{
		// Check LCV
		switch(choice)
		{
		case OUTPUT :
					  cout << endl;
					  cout << "Listing all movies!\n";
					  oFile << "COMPLETE MOVIE LISTING\n";
					  // Output the list template
					  OutputListTemplate(oFile);
					  // While dvdPtr is not NULL, will loop
					  while(dvdPtr != NULL)
					  {
						 // Outputs one movie
						 OutputList(dvdPtr, oFile, count);
						 // Points to next node
						 dvdPtr = dvdPtr->next;
						 // Increment list count
						 count++;
					  }
					  oFile << endl;
					  // Point dvdPtr back to head
					  dvdPtr = head;
					  break;
		case TITLESEARCH:
					  // Gets the searchItem input by user
					  searchItem = GetSearchInput(choice);
					  // Searches list based on type of search
					  SearchList(oFile, dvdPtr, 2, searchItem, searchInt);
					  // Outputs a single title if it matches the search key
					  while(dvdPtr != NULL)
					  {
						  if(dvdPtr->title == searchItem)
						  {
							  OutputTitle(dvdPtr, oFile);
						  }
						  dvdPtr = dvdPtr->next;
					  }
					  oFile << endl;
					  dvdPtr = head;
					  break;
		case GENRESEARCH:
					  // Gets the searchItem input by user
					  searchItem = GetSearchInput(choice);
					  // Searches list based on type of search
					  SearchList(oFile, dvdPtr, 3, searchItem, searchInt);
					  while(dvdPtr != NULL)
					  {
						  if((dvdPtr->genre1 == searchItem) ||
							  (dvdPtr->genre2 == searchItem))
						  {
							  // Outputs movie of searchItem that was found
							  OutputList(dvdPtr, oFile, count);
							  // Increment number of movies found
							  count++;
						  }
						  // Sets head of list to the next node
						  dvdPtr = dvdPtr->next;
					  }
					  oFile << endl;
					  dvdPtr = head;
					  break;
		case ACTORSEARCH:
					  // Gets the searchItem input by user
					  searchItem = GetSearchInput(choice);
					  // Searches list based on type of search
					  SearchList(oFile, dvdPtr, 4, searchItem, searchInt);
					  while(dvdPtr != NULL)
					  {
						  if((dvdPtr->leadActor == searchItem) ||
							  (dvdPtr->suppActor == searchItem))
						  {
							  // Outputs movie of searchItem that was found
							  OutputList(dvdPtr, oFile, count);
							  // Increment number of movies found
							  count++;
						  }
						  // Sets head of list to the next node
						  dvdPtr = dvdPtr->next;
					  }
					  oFile << endl;
					  dvdPtr = head;
					  break;
		case YEARSEARCH:
					  // Gets the searchItem input by user
					  searchInt = GetSearchInt(choice);
					  // Searches list based on type of search
					  SearchList(oFile, dvdPtr, 5, searchItem, searchInt);
					  while(dvdPtr != NULL)
					  {
						  if(dvdPtr->year == searchInt)
						  {
							  // Outputs movie of searchItem that was found
							  OutputList(dvdPtr, oFile, count);
							  // Increment number of movies found
							  count++;
						  }
						  // Sets head of list to the next node
						  dvdPtr = dvdPtr->next;
					  }
					  oFile << endl;
					  dvdPtr = head;
					  break;
		case RATINGSEARCH:
					  // Gets the searchItem input by user
					  searchInt = GetSearchInt(choice);
					  // Searches list based on type of search
					  SearchList(oFile, dvdPtr, 6, searchItem, searchInt);
					  while(dvdPtr != NULL)
					  {
						  if(dvdPtr->rating == searchInt)
						  {
							  // Outputs movie of searchItem that was found
							  OutputList(dvdPtr, oFile, count);
							  // Increment number of movies found
							  count++;
						  }
						  // Sets head of list to the next node
						  dvdPtr = dvdPtr->next;
					  }
					  oFile << endl;
					  dvdPtr = head;
					  break;
		case EXIT	: break;
		default 	: cout << left << endl;
					  cout << "ERROR! How did you get here?\n\n";
					 break;
		}

		count = 0;               // Changes count back to 0
		// Display menu
		DisplayMenu();
		choice = ErrorCheck(0,6);// Change LCV
	}
	// close inFile
	inFile.close();
	// close oFile
	oFile.close();
}
