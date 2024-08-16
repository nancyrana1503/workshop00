
// CONVERTING SOURCE MODULE //


#define _CRT_SECURE_NO_WARNINGS		// Suppress warnings for using unsafe standard library functions
#define BUFFER_SIZE 80				// Defining the buffer size for input strings
#include "converting.h"

						   // Version 1

// Function to convert strings to integers and print the results

void converting(void)
{
	printf("*** Start of Converting Strings to int Demo ***\n");
	char intString[BUFFER_SIZE];			// Buffer holds the input string
	int intNumber = 0;							// Variable stores the converted integer

	do {

		// Prompt the user to enter a numeric string or enter 'q' to quit

		printf("Type an int numeric string (q - to quit):\n");
		fgets(intString, BUFFER_SIZE, stdin);
		intString[strlen(intString) - 1] = '\0';

		if (strcmp(intString, "q") != 0)
		{

			intNumber = atoi(intString);
			printf("Converted number is %d\n", intNumber);
		}
	} while (strcmp(intString, "q") != 0);		// loop until the user enters 'q'


	printf("*** End of Converting Strings to int Demo ***\n\n");

	// Version 2


// Start of the demo for converting strings to double

	printf("*** Start of Converting Strings to double Demo ***\n");
	char doubleString[BUFFER_SIZE];
	double doubleNumber;
	do {
		printf("Type the double numeric string (q - to quit):\n");		// Prompt the user to input a double numeric string or 'q' to quit

		fgets(doubleString, BUFFER_SIZE, stdin);			// Read the input string from the user

		doubleString[strlen(doubleString) - 1] = '\0';		// Remove the newline character at the end of the string

		if ((strcmp(doubleString, "q") != 0))		// Check if the input string is not 'q'
		{
			doubleNumber = atof(doubleString);
			printf("Converted number is %f\n", doubleNumber);
		}
	} while (strcmp(doubleString, "q") != 0);	// Continue the loop until the user types 'q'

	printf("*** End of Converting Strings to double Demo ***\n");		// End of the demo

	//version 3
	printf("***  Start of Converting Strings to long Demo ***\n");
	char longString[BUFFER_SIZE];
	long longNumber;
	do {
		printf("Type the long numeric string (q - to quit): \n");
		fgets(longString, BUFFER_SIZE, stdin);
		longString[strlen(longString) - 1] = '\0';
		if ((strcmp(longString, "q") != 0))
		{
			longNumber = atol(longString);
			printf("Converted number is %ld\n", longNumber);
		}
	} while (strcmp(longString, "q") != 0);
	printf("*** End of Converting Strings to long Demo ***\n");
}
int main() {
	converting();        // Call the converting function
	return 0;
}


