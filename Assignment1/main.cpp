/********************************************************************
 * AUTHOR		: Milan Bui
 * ASSIGNMENT #1        : Functions and Arrays
 * CLASS		: CS 1B
 * SECTION		: MW: 6:30p - 8:50p
 * DUE DATE		: 14 September 2018
 ********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "functions.h"
#include "printHeader.h"
using namespace std;
/********************************************************************
 *
 * FINDING BALANCES AND PEOPLE FROM FILE
 * __________________________________________________________________
 *
 * This program will prompt the user for the input and output file
 * they wish to use. It will then take the input form the input file
 * and input it into the arrays. It then prompts the user for what
 * they wants the program to do with the information: find the
 * largest balance, find the smaller balance, find the sum, find the
 * the average, find a person, or exit. It then does that and outputs
 * the results to the output file while notifying the user of the
 * status by outputting a message to the screen.
 * __________________________________________________________________
 * INPUT:
 *      idAr - array containing the IDs of the people
 *
 *      balAr - array containing the balance of the people
 *
 *      nameAr - array containing the name of the people
 *
 *      nameKey - name that the user wants to find
 *
 *      inputFile - the input file containing the people's info
 *
 *      outputFile - the output file to send out the results
 *
 *      choice - what the user wants the program to do
 *
 *
 * OUTPUT:
 *      idAr - array containing the IDs of the people
 *
 *      balAr - array containing the balance of the people
 *
 *      nameAr - array containing the name of the people
 *
 *      nameKey - name that the user wants to find
 *
 *      num - the sum or average of all the balances depending on
 *            what the user wants
 *
 ********************************************************************/
int main()
{
	// Declaring variables
	int index;               // CALC - position in the array

	int findIndex;           // CALC - position in array of the
	                         //        desired person or balance
	int idAr[25];            // IN & OUT - array containing the IDs
	                         //            of the people
	float balAr[25];         // IN & OUT - array containing the
	                         //            balance of the people
	string nameAr[25];       // IN & OUT - array containing the
	                         //            name of the people
	string nameKey;          // IN & OUT - name that the user wants
	                         //            to find
	string inputFile;        // IN - the input file containing the
	                         //      people's information
	string outputFile;       // IN - the output file to send out
	                         //      the results
	MenuPick choice;         // IN - what the user wants the
	                         //      program to do
	float num;               // CALC & OUT - the sum or average of
	                         //              all the balances
	                         //              depending on what the
	                         //              user wants
	bool done;               // CALC - controls the loop/whether
	                         //        or not the user is done
	bool large;              // CALC - whether or not the user
	                         //        is looking for the larger
	                         //        or smaller sum
	bool avg;                // CALC - whether or not the user
	                         //        is looking for the sum or
	                         //        average
	ifstream inFile;         // IN - input file stream

	ofstream outFile;        // OUT - output file stream

	// Initializing variables
	done = false;

	// OUTPUT -- outputs header to screen
	cout << printHeader("Functions and Arrays", "1");

	// Prompts user for the name of the input file
	cout << left << setw(45) << "What input file would you like "
								"to use?";
	cin >> inputFile;
	cin.ignore(1000, '\n');

	// Checks for failure to open input file
	inFile.open(inputFile);
	if(!inFile)
	{
		cout << "Problem opening input file " << inputFile;
		return 1;
	}

	// Prompts user for the name of the output file
	cout << left << setw(45) << "What output file would you like "
			                    "to use?";
	cin >> outputFile;
	cin.ignore(1000, '\n');

	// Checks for the failure to open the output file
	outFile.open(outputFile);
	if(outFile.fail())
		{
			cout << "Problem opening output file " << outputFile;
			exit(1);
		}

	// OUTPUT -- outputs header to output file
	outFile << printHeader("Functions and Arrays", "1");

	cout << "\n";

	// INPUT -- inputting information from input file into array
	inputData(inFile, nameAr, idAr, balAr, index);

	while(!done)
	{
		// INPUT -- outputs menu, prompts user for their choice,
		//         and validates the input
		choice = getMenuPick();

		// PROCESSING -- executes code depending on choice
		switch(choice)
		{
		case FIND_LARGE:
			// Sets large to true to find the largest balance
			large = true;

			// Finds index of the largest balance
			findIndex = findBalance(balAr, index, findIndex, large);

			// OUTPUT -- outputs message to screen
			cout << "Finding the larger balance..." << endl;
			cout << "\n";

			// OUTPUT -- outputs ID#, name, and balance of the person
			//           with the largest balance to the output file
			outFile << "Larger Balance:" << endl;
			outFile << left << setw(9) << "ID #";
			outFile << left << setw(25) << "NAME";
			outFile << left << setw(11) << "BALANCE DUE" << endl;
			outFile << left << setw(9) << "____";
			outFile << left << setw(25) << "____________________";
			outFile << "___________" << endl;
			outFile << left << setw(9) << idAr[findIndex];
			outFile << left << setw(25) << nameAr[findIndex];
			outFile << fixed << setprecision(2);
			outFile << '$' << right << setw(10) << balAr[findIndex]
				    << endl;
			outFile << "\n";
			break;
		case FIND_SMALL:
			// Sets large to false to find smaller balance
			large = false;

			// Finds index of the smallest balance
			findIndex = findBalance(balAr, index, findIndex, large);

			// OUTPUT -- outputs message to screen
			cout << "Finding the smaller balance..." << endl;
			cout << "\n";

			// OUTPUT -- outputs ID#, name, and balance of the person
			//           with the smallest balance to the output file
			outFile << "Smaller Balance:" << endl;
			outFile << left << setw(9) << "ID #";
			outFile << left << setw(25) << "NAME";
			outFile << left << setw(11) << "BALANCE DUE" << endl;
			outFile << left << setw(9) << "____";
			outFile << left << setw(25) << "____________________";
			outFile << "___________" << endl;
			outFile << left << setw(9) << idAr[findIndex];
			outFile << left << setw(25) << nameAr[findIndex];
			outFile << fixed << setprecision(2);
			outFile << '$' << right << setw(10) << balAr[findIndex]
					<< endl;
			outFile << "\n";
			break;
		case SUM:
			// Sets avg to false to find sum
			avg = false;

			// CALC - calculates the sum of all the balances
			num = obtainSumOrAvg(balAr, index, num, avg);

			// OUTPUT -- outputs message to screen
			cout << "Obtaining sum of all balances..." << endl;
			cout << "\n";

			// OUTPUT -- outputs the sum to the output file
			outFile << "Sum of Balance for all persons:" << endl;
			outFile << left << setw(4) << '$';
			outFile << fixed << setprecision(2) << right << setw(7)
					<< num << endl;
			outFile << "\n";
			break;
		case AVG:
			// Sets avg to true to find avg
			avg = true;

			// CALC - calculates the average of all the balances
			num = obtainSumOrAvg(balAr, index, num, avg);

			// OUTPUT -- outputs message to screen
			cout << "Obtaining average of all balances..." << endl;
			cout << "\n";

			// OUTPUT -- outputs average to output file
			outFile << "Average of Balance for all persons:" << endl;
			outFile << left << setw(4) << '$';
			outFile << fixed << setprecision(2) << right << setw(7)
					<< num << endl;
			outFile << "\n";
			break;
		case FIND_PER:
			// Prompts user for the name they want to find
			cout << "Who do you want to search for (enter done to"
				 << " exit): ";
			cin.ignore(1000, '\n');
			getline(cin, nameKey);

			// PROCESSING -- find the index of the person with the
			//               matching name
			findIndex = findName(nameAr, nameKey, index);

			// OUTPUT -- outputs whether or not the person was found
			//           to the screen
			if(findIndex == -1)
			{
				cout << nameKey << " was not found." << endl;
				cout << "\n";
			}
			else
			{
				cout << "Found." << endl;
				cout << "\n";

				// OUTPUT -- if found, outputs the person's info
				outFile << "Search Name:" << endl;
				outFile << left << setw(9) << "ID #";
				outFile << left << setw(25) << "NAME";
				outFile << left << setw(11) << "BALANCE DUE" << endl;
				outFile << left << setw(9) << "____";
				outFile << left << setw(25) << "____________________";
				outFile << "___________" << endl;
				outFile << left << setw(9) << idAr[findIndex];
				outFile << left << setw(25) << nameAr[findIndex];
				outFile << fixed << setprecision(2);
				outFile << '$' << right << setw(10) << balAr[findIndex]
						<< endl;
				outFile << "\n";

			}

			break;
		case EXIT:
			// OUTPUT -- outputs message to screen
			cout << "Thank you for using my program." << endl;
			cout << "\n";

			// Sets done to true to exit.
			done = true;
			break;
		default:
			cout << "Should not run." << endl;
			break;
		}
	}

	// Closes input and output files
	inFile.close();
	outFile.close();

	return 0;
}
