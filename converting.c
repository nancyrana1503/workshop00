
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

}
int main() {
	converting();        // Call the converting function
	return 0;
}