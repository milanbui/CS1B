/********************************************************************
 * AUTHOR		: Milan Bui
 * STUDENT ID	: 1129567
 * ASSIGNMENT #1: Functions and Arrays
 * CLASS		: CS 1B
 * SECTION		: MW: 6:30p - 8:50p
 * DUE DATE		: 14 September 2018
 ********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;


/********************************************************************
 * FUNCTION printHeader
 * __________________________________________________________________
 *
 * This function returns a header including the lab name, lab number,
 * the programmer's name, the class name, and the section time
 * as a string
 * __________________________________________________________________
 * PRE-CONDITIONS:
 *     labName - Name of the lab. The labName should be previously
 *               defined
 *     labNumber - Number of the lab. The labNumber should be
 *                 previously defined
 *
 * POST-CONDITIONS:
 *      returns header as string
 *******************************************************************/
string printHeader(string labName,            //OUT - name of lab
		           string labNumber)          //OUT - the lab number
{

	ostringstream output;

	//  OUTPUT - Class Heading
	output << left;
	output << "***************************************************"
		   << "*****";
	output << "\n*	PROGRAMMED BY : " << "Milan Bui";
	output << "\n*	" << setw(14) << "CLASS" << ": " << "CS1B";
	output << "\n*	" << setw(14) << "SECTION" << ": "
		   << "MW: 6:30p - 8:50p";
	output << "\n*	ASSIGNMENT #" << setw(2) << labNumber << ": "
		   << labName;
	output << "\n*************************************************"
		   << "*******\n\n";
	output << right;

	//  OUTPUT - return class heading as string
	return output.str();

}
