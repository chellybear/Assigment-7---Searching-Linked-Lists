/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/
// Includes assignment header file
#include "MyHeader.h"

// This function receives receives an assignment name, type
// and number then outputs the appropriate header
void PrintHeader(string asName, 	// IN - assignment Name
				 char asType, 		// IN - assignment type
				 int asNum) 		// IN - assignment number
{
	 cout << left;
	 cout << "**************************************************\n";
	 cout << "* Programmed by : Rachel Jachin";
	 cout << "\n* " << setw(14) << "Student ID" << ": 959845";
	 cout << "\n* " << setw(14) << "Class" << ": CS1B –-> TTh - 6:30 - "
			  "8:20p \n* ";
	 if (toupper(asType) == 'L')
	 {
		 cout << "LAB #" << setw(9);
	 }
	 else
	 {
		 cout << "ASSIGNMENT #" << setw(2);
	 }
	 cout << asNum << ": " << asName;
	 cout << "\n**************************************************\n\n";
	 cout << right;
}
