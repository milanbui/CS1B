/********************************************************************
 * AUTHOR		: Milan Bui
 * STUDENT ID	: 1129567
 * ASSIGNMENT #1: Functions and Arrays
 * CLASS		: CS 1B
 * SECTION		: MW: 6:30p - 8:50p
 * DUE DATE		: 14 September 2018
 ********************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// PREPROCESSOR DIRECTIVES
#include <iostream>
#include <iomanip>
#include <string>
#include<fstream>
using namespace std;

// GLOBAL CONSTANTS

// TYPE DEFINITIONS AND ENUMERATED TYPES
enum MenuPick {FIND_LARGE,           // Find the larger balance index
		       FIND_SMALL,           // Find the smaller balance index
			   SUM,                  // Obtain sum of all balances
			   AVG,                  // Obtain avg of all balances
			   FIND_PER,             // Find person index
			   EXIT                  // Exit program
	           };

// PROTOTYPES

/********************************************************************
 * inputData
 *  This function inputs the data from the input file into the arrays
 *      returns values to arrays by changing the variables
 *******************************************************************/
void inputData(ifstream &inFile,  // IN - input file stream
		       string nameAr[],  // IN - array containing the
                                  //      name of the people
			   int idAr[],       // IN - array containing the
                                  //      IDs of the people
			   float balAr[],    // IN - array containing the
                                  //      balance of the people
			   int &index);       // CALC - position in the array

/********************************************************************
 * getMenuPick
 *  This function prompts the user for their choice of what they want
 *  the program to do. It processes the input to check if it's
 *  valid or if the user wishes to exit.
 *     returns their selection as an enumeration type MenuPick
 *******************************************************************/
MenuPick getMenuPick();

/********************************************************************
 * findBalance
 *  This function finds the larger or smaller balance in the array
 *  depending on what the user is looking for.
 *     returns index of smaller or larger balance depending on what
 *     the user wants
 *******************************************************************/
int findBalance(float balAr[],      // IN - the array containing
		                            //      people's balances
		        const int SIZE,     // CALC - the size of the array
				int &index,         // CALC & OUT - the index of the
				                    //              balance
				const bool LARGE);  // CALC - whether or not the user
                                    //        wants the larger or
                                    //        smaller balance

/********************************************************************
 * obtainSumOrAvg
 *  This function calculates the sum or average of all of the
 *  balances depending on what the user wants and returns that
 *  value
 *     returns the sum or average of all the balances depending
 *     on what the user wants
 *******************************************************************/
float obtainSumOrAvg(const float BAL_AR[],   // IN - array containing
		                                     //      people's balance
		             const int SIZE,         // CALC - the size of
					                         //        the array
					 float &number,          // CALC - the sum or
					                         //        average
					 const bool AVG);        // CALC - whether or not
                                             //        the user wants
                                             //        to find the sum
                                             //        or the average

/********************************************************************
 * findName
 *  This function find the name that the user wants to find
 *     returns the index of the name that the user is looking for
 *******************************************************************/
int findName (const string STR_AR[],     // IN - the name in the array
		   	  const string KEY,          // IN - the name the user
		                                 //      wants to count
			  const int SIZE);           // CALC - the amount of names
                                         //        input from the file

#endif /* FUNCTIONS_H_ */
