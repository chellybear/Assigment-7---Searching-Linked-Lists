/*************************************************************************
 * AUTHOR		: Rachel Jachin											 *
 * ASSIGN #7	: Searching Linked Lists								 *
 * CLASS		: CS1B													 *
 * SECTION		: TTh 6:30 - 8:20p										 *
 * DUE DATE		: 4/17/2014												 *
 *************************************************************************/
// Includes assignment header file
#include "MyHeader.h"

void SpecifyFile(ifstream& inFile, ofstream& oFile)
{
	string inFileName;	// IN - input file name
	string oFileName;	// OUT - output file name

	// Prompts user to enter input file
	cout << "Which input file would you like to use? Type d for default: ";
	getline(cin, inFileName);
	// Will open default input file if filename is "d"
	if(inFileName == "d")
	{
		inFile.open("InFile.txt");
	}
	// Will open specified input file
	else
	{
		inFile.open(inFileName.c_str());
	}

	// Prompts user to enter output file
	cout << "Which output file would you like to use? Type d for default: ";
	getline(cin, oFileName);
	// Will open default output file if filename is "d"
	if(oFileName == "d")
	{
		oFile.open("OFile.txt");
	}
	// Will open specified output file
	else
	{
		oFile.open(oFileName.c_str());
	}

}
