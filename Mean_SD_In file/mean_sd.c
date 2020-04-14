#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

//This function counts number of prices in file
int count_num_data_items()
{
	//Opening file
	FILE *fp;
	fp = fopen("prices.txt","r");
	//File invalidation
	if(fp==NULL)
	{
		printf("Failed to open the file...!");
		return 0;
	}
	int count=0;
	char *line=NULL;
	size_t buff=0;
	ssize_t len;
	//read each price into line
	while((len = fgets(&line, &buff, fp)) != -1)
	{
		//Increment count by 1
		count++;
	}
	//Closing file
	fclose(fp);
	//returning count
	return count;
}

//This function converts string to integers
int string_to_int(char *str,size_t len)
{
	int i;
	int num=0;
	for(i=0;i<len;i++)
	{
		char ch = *(str+i);
		//If character is a digit
		if(ch>='0' && ch<='9')
		{
			num = (num*10)+(*(str+i)-'0');
		}
	}
	//return num
	return num;
}

//This function reads file data into arr
void read_data(int *arr)
{
	//Opening file
	FILE *fp;
	fp = fopen("prices.txt","r");
	if(fp==NULL)
	{
		printf("Failed to open the file...!");
		return	;
	}

	int count=0;
	char *line=NULL;
	size_t buff=0;
	ssize_t len=0;
	int index=0;
	//read line by line
	while((len = fgets(&line, &buff, fp)) != -1)
	{
		//Convert the line into integer and store it to arr
		*(arr+index) = string_to_int(line,len);
		//Increment arrray index by 1
		index++;
	}
	//close file
	fclose(fp);
}

//This function calculates mean of arr
float find_mean(int *arr,int len)
{
	//Initial sum is 0
	float sum=0;
	int i;
	//Add each price to sum
	for(i=0;i<len;i++)
	{
		sum+=*(arr+i);
	}
	//mean = total / number of prices
	return sum/len;
}

//This function calculates standard_deviation of arr
float find_standard_deviation(int *arr,int len)
{
	//First get mean
	float mean=find_mean(arr,len);
	float square_diff_sum = 0;
	int i;
	for(i=0;i<len;i++)
	{
		//Find difference between price and mean
		float diff = *(arr+i) - mean;
		//Find square of diff and add it to square_diff_sum
		square_diff_sum += diff*diff;
	}
	//Formula for standard deviation
	float sd = sqrt(square_diff_sum/len);
	return sd;
}

int main()
{
	//Get number of prices in file
	int count = count_num_data_items();
	//Dynamically create array
	int *arr = (int *)malloc(sizeof(int)*count); 
	//Read data into arr
	read_data(arr);
	//Call functions and print output
	printf("Mean: %.2f\n",find_mean(arr,count));
	printf("Standard deviation: %.2f\n",find_standard_deviation(arr,count));
}
