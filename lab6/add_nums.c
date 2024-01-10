/*
# CSC219 Lab 5 - Naya Brown
# Created: Nov 16th, 2023 ~ Completed: Nov 19th, 2023
# Program: Uses integer arrays to add two large integer numbers
*/

#include <stdio.h>
#define N 20

/*Function prototypes*/
void add(int sum[], int a[], int b[]);
void prn_num(int a[]);

int main(int argc, char * argv[])
{
	int a[N] = {7, 5, 9, 8, 9, 7, 5, 0, 0, 9, 9, 0, 8, 8};
	int b[N] = {7, 7, 5, 3, 1, 2, 8, 8, 9, 6, 7, 7};
	int sum[N];

	printf("Integer a: ");
	prn_num(a);
	printf("Integer b: ");
	prn_num(b);
	add(sum, a, b);
	printf("Sum: ");
	prn_num(sum);	
	return 0;

} // end of main

/*Function definitions*/
void add(int sum[], int a[], int b[])
{
	//digits are stored in reverse order from 0 to N-1
	// if there is elements in array b to add, add them otherwise sum value is value in array a
	// add first elements, if carry exists (if num/10!=0)
	// store that carry (num/10) and store digit (num%10) in array
	// go to next digit, if there is a carry to add (carry !=0) add it and reset the carry value to 0
	// keep going until end of both arrays
	
	printf("Checking N: %d, Checking N-1: %d\n", N, N-1);
	int i, carry = 0, temp_sum;
	for (i = 0; i<N-1; i++)
	{
		printf("Current temp_sum: %d, i: %d, a: %d\n", temp_sum, i, a[i]);

		if (b[i]) // if there is an element in array b to be added
		{
			temp_sum = a[i] + b[i] + carry;
			sum[i] = temp_sum%10;
		
			carry = (temp_sum/10);
		}
		else if (a[i])
			sum[i] = a[i];
		else 
			sum[i] = 0;
		printf("sum: %d\n", sum[i]);
	}
	
} // end of add

void prn_num(int a[])
{
	int i;
	for (i = N - 1; i >= 0; --i) 
	{
		if (a[i] == 0)
			putchar(' ');
		else
			break;
	}
	for (; i >= 0; --i)
	{
		printf("%d", a[i]);
	}
	putchar('\n');
} // end of prn_num
