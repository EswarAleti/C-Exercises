#include<stdio.h>

// Assume it is the function of Assignment 3A
// This function will find sum of odd numbers in array
int odd_num_sum(int arr[], int size)
{
	// Initial sum is 0
	int sum=0,i;
	// Iterate over array
	for(i=0;i<size;i++)
	{
		// If arr[i] is odd then add it to sum
		if(arr[i]%2==1)
		{
			sum += arr[i];
		}
	}
	// Return the sum
	return sum;
}

// Assume it is the function of Assignment 3B
// This function will find sum of even numbers in array
int even_num_sum(int arr[], int size)
{
	// Initial sum is 0
	int sum=0,i;
	// Iterate over array
	for(i=0;i<size;i++)
	{
		// If arr[i] is even then add it to sum
		if(arr[i]%2==0)
		{
			sum += arr[i];
		}
	}
	// Return the sum
	return sum;
}

int main()
{
	char choice;
	do
	{
		// Menu printing
		printf("\n[A] Assignment 3A\n[B] Assignment 3B\n[Q] Quit");
		printf("\nEnter your choice: ");
		// Input choice from user
		choice =  getchar();
		int arr[] = {1,2,3,4,5,6,7,8,9,10};
		int size = sizeof(arr)/sizeof(int);
		// Switch statement
		switch(choice)
		{
			// Assignment 3A has odd_num_sum() function
			case 'A':
					printf("Sum of odd numbers: %d\n",odd_num_sum(arr,size));
					break;
			// Assignment 3B has even_num_sum() function
			case 'B':
					printf("Sum of odd numbers: %d\n",even_num_sum(arr,size));
					break;
			// Quit		  
			case 'Q':
					break;
			// Invalid input case
			default :
					printf("Invalid input please try again...!\n");
					break;
		}
		// To remove white space of above printing statement
		getchar();
	}while(choice!='Q');
	return 0;
}