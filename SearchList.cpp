/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/
// Includes assignment header file
#include "MyHeader.h"

// This function searches the list based on type of search
void SearchList(ofstream& oFile, DvdRec *&head, int choice,
				string& searchItem, int& searchInt)
{
	bool found;		  // CALC - Sets to true if searchItem is found
	DvdRec *dvdPtr;	  // CALC & OUT - pointer for dvdPtr
	int instances;	  // CALC & OUT - number of occurences of searchItem

	dvdPtr = head;	  // Points dvdPtr to head
	found = false;    // Sets found to false
	instances = 0;	  // Initializes instance count to 0

	// Switch statement handles type of search specified by user
	// by passing in the choice
	switch(choice)
	{
	case TITLESEARCH:
		// Loop while dvdPtr != NULL and searchItem not found
		while(dvdPtr != NULL && !found)
		{
			if(dvdPtr->title == searchItem)
			{
				// Will equal true if found so it will not output !found
				// msg
				found = true;
				// Only need one occurrence to output the title
				instances = 1;
			}
			dvdPtr = dvdPtr->next;
		} // End while loop
		break;
	case GENRESEARCH:
		// Loop while dvdPtr != NULL
		while(dvdPtr != NULL)
		{
			// If genre or alt genre is found, will increment
			// Sets found to true if at least one instance is found
			if((dvdPtr->genre1 == searchItem) ||
			   (dvdPtr->genre2 == searchItem))
			{
				found = true;
				// Increments number of instances found
				instances = instances + 1;
			}
			dvdPtr = dvdPtr->next;
		}
		break;
	case ACTORSEARCH:
		// Loop while dvdPtr != NULL
		while(dvdPtr != NULL)
		{
			// If leadActor or suppActor is found, will increment
			// Sets found to true if at least one instance is found
			if((dvdPtr->leadActor == searchItem) ||
			   (dvdPtr->suppActor == searchItem))
			{
				// Will equal true if found so it will not output !found
				// msg
				found = true;
				instances = instances + 1;
			}
			dvdPtr = dvdPtr->next;
		}
		break;
	case YEARSEARCH:
			// Loop while dvdPtr != NULL
			while(dvdPtr != NULL)
			{
				// If valid year is found, will increment
				// Sets found to true if at least one instance is found
				if(dvdPtr->year == searchInt)
				{
					// Will equal true if found so it will not output !found
					// msg
					found = true;
					instances = instances + 1;
				}
				dvdPtr = dvdPtr->next;
			}
			break;
	case RATINGSEARCH:
			// Loop while dvdPtr != NULL
			while(dvdPtr != NULL)
			{
				// If rating is found, will increment
				// Sets found to true if at least one instance is found
				if(dvdPtr->rating == searchInt)
				{
					// Will equal true if found so it will not output !found
					// msg
					found = true;
					instances = instances + 1;
				}
				dvdPtr = dvdPtr->next;
			}
			break;
	}

		// If searchPtr is not found and using TITLESEARCH, will
		// output message
		if(!found && (choice == 2))
		{
			cout << "Sorry, the movie \"" << searchItem << "\" was not "
					"found.\n";
		}
		// If instances are 0, will output message
		if(instances == 0)
		{
			switch(choice)
			{
			case GENRESEARCH:
				cout << "Sorry, no movies for the genre, " << searchItem
					 << " were found.\n";
				break;
			case ACTORSEARCH:
				cout << "Sorry, no movies for the actor, " << searchItem
					 << " were found.\n";
				break;
			case YEARSEARCH:
				cout << "Sorry, no movies for the year, " << searchInt
					 << " were found.\n";
				break;
			case RATINGSEARCH:
				cout << "Sorry, no movies for the rating, " << searchInt
					 << " were found.\n";
				break;
			}
		}
		// Else, will go through switch statement and output according to
		// type of search
		else
		{
			switch(choice)
			{
			case TITLESEARCH:
				cout << "Found the movie " << searchItem << "!\n";
				break;
			case GENRESEARCH:
				cout << "Found " << instances << " movies for the genre "
					 << searchItem << "!\n";
				oFile << "Search by genre for " << searchItem
					  << " found: \n";
				OutputListTemplate(oFile);
				break;
			case ACTORSEARCH:
				cout << "Found " << instances << " movies for the actor "
					 << searchItem << "!\n";
				oFile << "Search by actor for " << searchItem
					  << " found: \n";
				OutputListTemplate(oFile);
				break;
			case YEARSEARCH:
				cout << "Found " << instances << " movies for the year "
					 << searchInt << "!\n";
				oFile << "Search by year for " << searchInt
					  << " found: \n";
				OutputListTemplate(oFile);
				break;
			case RATINGSEARCH:
				cout << "Found " << instances << " movies for the rating "
					 << searchInt << "!\n";
				oFile << "Search by rating for " << searchInt
					  << " found: \n";
				OutputListTemplate(oFile);
				break;
			}
		}
		dvdPtr = NULL;
		delete dvdPtr;
}
