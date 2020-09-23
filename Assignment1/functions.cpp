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
#include<fstream>
using namespace std;

enum MenuPick {FIND_LARGE,           // Find the larger balance
		       FIND_SMALL,           // Find the smaller balance
			   SUM,                  // Obtain sum of all balances
			   AVG,                  // Obtain avg of all balances
			   FIND_PER,             // Find person
			   EXIT                  // Exit program
	           };

/********************************************************************
 * FUNCTION inputData
 * __________________________________________________________________
 *
 *  This function inputs the data from the input file into the arrays
 * __________________________________________________________________
 * PRE-CONDITIONS:
 *      idAr - array containing the IDs of the people must be
 *             predefined
 *
 *      balAr - array containing the balance of the people must be
 *              predefined
 *
 *      nameAr - array containing the name of the people must be
 *               predefined
 *
 *      inFile - the input file stream must be predefined
 *
 *      index - the index number must be predefined
 *
 * POST-CONDITIONS:
 *      returns values to arrays by changing the variables
 *******************************************************************/
void inputData(ifstream &inFile, // IN - input file stream
		       string nameAr[], // IN - array containing the names
			   int idAr[],     // IN - array containing the IDs
			   float balAr[],   // IN - array containing the
                                 //      balance of the people
			   int &index)       // CALC - position in the array
{
	index = 0;

	// INPUT -- inputting information from input file into array
	getline(inFile, nameAr[index]);
	inFile >> idAr[index];
	inFile >> balAr[index];
	inFile.ignore(1000, '\n');
	index++;
	while((!inFile.eof()) && (index < 25))
	{
		getline(inFile, nameAr[index]);
		inFile >> idAr[index];
		inFile >> balAr[index];
		inFile.ignore(1000, '\n');
		index++;
	}
}
/********************************************************************
 * FUNCTION getMenuPick
 * __________________________________________________________________
 *
 *  This function prompts the user for their choice of what they want
 *  the program to do. It processes the input to check if it's
 *  valid or if the user wishes to exit.
 * __________________________________________________________________
 * PRE-CONDITIONS:
 *
 * POST-CONDITIONS:
 *      outputs menu and returns user's choice as an enumeration type
 *      MenuPick
 *******************************************************************/
MenuPick getMenuPick()
{
	// Declaring variables
	int selection;       // IN - the user's choice of what they want
	                     //      the program to do
	MenuPick choice;     // OUT - the users choice as an enumeration
	                     //       type MenuPick
	bool done;           // CALC - controls while loop (if the user
	                     //        wants to finish the program)

	// Initializing variable
	done = false;


	while(!done)
	{

		// IN & OUT -- outputs menu & prompts user for input
		//             (their choice)
		cout << "MENU OPTIONS" << endl;
		cout << "\n";
		cout << "1 - Find the larger balance" << endl;
		cout << "2 - Find the smaller balance" << endl;
		cout << "3 - Obtain the sum of all balances" << endl;
		cout << "4 - Obtain the average of all balances" << endl;
		cout << "5 - Count name" << endl;
		cout << "0 - Exit program" << endl;
		cout << "Enter an option (0 to exit): ";

		cin >> selection;

		cout << "\n";

		// PROCESSING & OUT -- if the user entered invalid input then
		//                     clears fail state and outputs message
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Please enter an integer value!" << endl;
			cout << "\n";
			continue;
		}

		if((selection < 0) || (selection > 5))
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Please enter a number between 0 and 5!" << endl;
			cout << "\n";
			continue;
		}


		// Ends loop
		done = true;
	}


	// PROCESSING -- equates the user's selection to an enumeration
	//               type
	switch(selection)
	{
	case 1:
		choice = FIND_LARGE;
		break;
	case 2:
		choice = FIND_SMALL;
		break;
	case 3:
		choice = SUM;
		break;
	case 4:
		choice = AVG;
		break;
	case 5:
		choice = FIND_PER;
		break;
	case 0:
		choice = EXIT;
		break;
	}

	// OUTPUT -- returns the user's choice as an enumeration type
	return choice;

}


/********************************************************************
 * FUNCTION findBalance
 * __________________________________________________________________
 *
 *  This function finds the larger or smaller balance in the array
 *  depending on what the user is looking for.
 * __________________________________________________________________
 * PRE-CONDITIONS:
 *      balAr[] - the balances must be predefined
 *      SIZE  - the size of the array must be predefined
 *      index - the index must be predefined
 *      LARGE - the choice of whether or not the user is looking
 *              for the larger or smaller balance must be predefined
 *
 * POST-CONDITIONS:
 *      returns index of smaller or larger balance depending on what
 *      the user wants
 *******************************************************************/
int findBalance(float balAr[],     // IN - the array containing
		                           //      people's balances
		        const int SIZE,    // CALC - the size of the array
				int &index,        // CALC & OUT - the index of the
				                   //              balance
				const bool LARGE)  // CALC - whether or not the user
                                   //        wants the larger or
                                   //        smaller balance
{
	// Declaring variables
	int i;            // CALC - loop control variable
	float balance;    // CALC - the max or min balance depending
	                  //        on what the user is looking for

	// Initializing variables
	index = 0;
	balance = balAr[0];

	if(LARGE)
	{
		// PROCESSING -- finds the larger balance
		for(i = 1; i < SIZE; i++)
		{
			if(balAr[i] > balance)
			{
				index = i;
				balance = balAr[i];
			}
		}
	}
	else if(!LARGE)
	{
		// PROCESSING -- finds the smaller balance
		for(i = 1; i < SIZE; i++)
		{
			if(balAr[i] < balance)
			{
				index = i;
				balance = balAr[i];
			}
		}
	}


	// OUTPUT -- returns the index of the larger or smaller
	//           balance
	return index;

}


/********************************************************************
 * FUNCTION obtainSumOrAvg
 * __________________________________________________________________
 *
 *  This function calculates the sum or average of all of the
 *  balances depending on what the user wants and returns that
 *  value
 * __________________________________________________________________
 * PRE-CONDITIONS:
 *      balAr[] - the balances must be predefined
 *      SIZE  - the size of the array must be predefined
 *      number - the number must be predefined
 *      AVG - the choice of whether or not the user is looking
 *            for the sum or average of all the balances must be
 *            predefined
 *
 * POST-CONDITIONS:
 *      returns the sum or average of all the balances depending
 *      on what the user wants
 *******************************************************************/
float obtainSumOrAvg(const float BAL_AR[],  // IN - array containing
		                                    //      people's balance
		             const int SIZE,        // CALC - the size of
					                        //        the array
					 float &number,         // CALC - the sum or
					                        //        average
					 const bool AVG)        // CALC - whether or not
                                            //        the user wants
                                            //        to find the sum
                                            //        or the average
{
	// Declaring variables
	int i;      // CALC - loop control variable and the index

	// Initializing variable
	number = 0;

	if(AVG)
	{
		// PROCESSING -- calculates the average
		for(i = 0; i < SIZE; i++)
		{
			number += BAL_AR[i];
		}

		number = number/i;
	}
	else
	{
		// PROCESSING -- calculates the sum
		for(i = 0; i < SIZE; i++)
		{
			number += BAL_AR[i];
		}
	}


	// OUTPUT -- returns the sum or average
	return number;
}

/********************************************************************
 * FUNCTION findName
 * __________________________________________________________________
 *
 *  This function find the name that the user wants to find
 * __________________________________________________________________
 * PRE-CONDITIONS:
 *      STR_AR[] - the array containing the names must be predefined
 *      KEY      - the name the user wants to find
 *      SIZE     - the size of the array must be predefined
 *
 * POST-CONDITIONS:
 *      returns the index of the name that the user is looking for
 *******************************************************************/
int findName (const string STR_AR[],    // IN - the name in the array
		   	  const string KEY,         // IN - the name the user
		                                //      wants to count
			  const int SIZE)           // CALC - the amount of names
                                        //        input from the file
{
	// Declaring variables
	int index;        // CALC & OUT - the index of the name
	int i;            // CALC - loop control variable

	// Initializing variables
	index = -1;

	// PROCESSING -- searching for the name
	for(i = 0; i < SIZE; i++)
	{
		// Setting the index if name found
		if(STR_AR[i] == KEY)
		{
			index = i;
		}
	}

	// OUTPUT -- returns the index of the name or -1 if not found
	return index;
}

