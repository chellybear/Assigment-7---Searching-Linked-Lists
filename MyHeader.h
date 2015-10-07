/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/

// Defines the assignment header
#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <ios>
#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// Enums & Typedefs
// Struct to create linked list of Dvds
struct DvdRec
{
	string title;
	string leadActor;
	string suppActor;
	string genre1;
	string genre2;
	int year;
	int rating;
	string synopsis;

	DvdRec *next;
};

// Menu options
enum DvdOptions
{
	EXIT,
	OUTPUT,
	TITLESEARCH,
	GENRESEARCH,
	ACTORSEARCH,
	YEARSEARCH,
	RATINGSEARCH
};

// Function Prototypes
// This function outputs the menu layout.
void DisplayMenu();

// This function creates a linked list of movies
DvdRec *CreateList(ifstream& inFile);	 // CALC - input file stream

// This function error checks user's input
int ErrorCheck(const int min,		  	 // IN & CALC - minimum range
			   const int max);		  	 // IN & CALC - maximum range

// This function allows the user to specify an input and out file
void SpecifyFile(ifstream& inFile, 	  	 // CALC - input file stream
				 ofstream& oFile);	  	 // CALC - output file stream

// This function holds the list template for OutputList
void OutputListTemplate(ofstream& oFile);// CALC - output file stream

// This function outputs the linked list
void OutputList(DvdRec *head, 			 // CALC & OUT - head of linked list
				ofstream& oFile,		 // CALC - output file stream
				int& count);			 // CALC & OUT - number of dvd on list

// This function will output the movie info based on title
void OutputTitle(DvdRec *head, 			 // CALC & OUT - head of linked list
				 ofstream& oFile); 		 // CALC & OUT - head of linked list

// This function wordwraps the synopsis to be output
void WordWrap(DvdRec *head, 			 // CALC & OUT - head of linked list
			  ofstream& oFile); 		 // CALC & OUT - head of linked list

// This function prompts user to input searchItem based on search type
string GetSearchInput(int& choice);		// IN & CALC - menu choice

// This function prompts user to input searchInt based on search type
int GetSearchInt(int& choice);			// IN & CALC - menu choice

// This function searches the list for specified input
void SearchList(ofstream& oFile,  		 // CALC & OUT - head of linked list
			    DvdRec *&head,			 // CALC & OUT - head of linked list
				int choice,				 // IN & CALC - menu choice
				string& searchItem, 	 // IN & CALC & OUT - searchItem
										 // input by user
				int& searchInt);		 // IN & CALC & OUT - searchInt
										 // input by user
// This function prints header
void PrintHeader(string asName,			 // OUT - Assignment name
				 char asType,			 // OUT - Assignment type
			     int asNum);			 // OUT - Assignment number

#endif /* MYHEADER_H_ */
