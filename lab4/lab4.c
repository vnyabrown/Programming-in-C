/* CSC219 Lab 4 - Naya Brown */
/* Created: 10/25/23 ~ Complete 10/25/23 */

#include <stdio.h>

int main (int argc, char * argv[])
{
	char userStr[500]; // char array to hold input from user
	char readCh; // char to read/check then insert each input from user
	// integers to hold count of type of char encountered
	int num_ws = 0, num_dig = 0, num_low = 0, num_up = 0;
	int arr_count = 0; // integer to hold index of array
	
	// 1. Ask user for any input, input must stop when z is input
		printf("Enter any input from the keyboard. To END, input 'z'");
		
		while (readCh != 'z') //while user input is not z, keep reading input
		{
			readCh = getchar(); // read input
			if (readCh != 'z')
			{
			userStr[arr_count] = readCh; // add input to array
			}

	// 2. Count whitespace, digit numbers, lower case and upper case letters
			// check input is whitespace
			if (readCh == '\n' || readCh == '\t' || readCh == ' ')
				num_ws = num_ws + 1; // updates whitespace count
			// check input is digit
			else if (readCh == 48 || readCh < 58) 
				num_dig = num_dig + 1; // updates digit count
			// check input is lowercase character
			else if (readCh >= 97 && readCh < 122)
			{
				num_low = num_low + 1; // updates lowercase count
				userStr[arr_count] = (readCh - 32);

			} // end of if
			// check input is uppercase character
			else if (readCh >= 65 && readCh < 90)
			{
				num_up = num_up + 1; // updates uppercase count
				userStr[arr_count] = (readCh + 32);

			} // end of if
			else if (readCh == 'z')
				break;
			arr_count = arr_count+1;
		} // end of while

	// 3. Output to user the data found in step 2
		//Output string to user		
		int i;
		for (i = 0; i<=arr_count; i++)
			{
				printf("%c", userStr[i]);
			}
		printf("\n\n");
	
		printf("The number of whitespace characters is: %d\n", num_ws);
		printf("The number of digits is: %d\n", num_dig);
		printf("The number of lowercase characters is: %d\n", num_low);
		printf("The number of uppercase characters is: %d\n\n", num_up);
		printf("Goodbye!\n");

	return 0;
} // end of main


