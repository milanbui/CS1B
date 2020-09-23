/********************************************************************
 * AUTHOR		: Milan Bui
 * STUDENT ID	: 1129567
 * ASSIGNMENT #1: Functions and Arrays
 * CLASS		: CS 1B
 * SECTION		: MW: 6:30p - 8:50p
 * DUE DATE		: 14 September 2018
 ********************************************************************/

#ifndef PRINTHEADER_H_
#define PRINTHEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

/********************************************************************
 * printHeader
 *  This function returns a header including the lab name, lab number,
 *  the programmer's name, the class name, and the section time
 *  as a string
 *      returns header as string
 *******************************************************************/
string printHeader(string labName,             //OUT - name of lab
		           string labNumber);          //OUT - the lab number



#endif /* PRINTHEADER_H_ */
