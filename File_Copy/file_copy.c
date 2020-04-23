#include<stdio.h>
#include <stdlib.h>

void copyFile(FILE *in_ptr, FILE *out_ptr)
{
	//Take each character of file in c
	char c = fgetc(in_ptr);
	while(c!=EOF)
	{
		//Write each character to file
		fputc(c,out_ptr);
		c = fgetc(in_ptr);
	}
}

int main()
{
	//in_ptr reads data, out_ptr writes data
	FILE *in_ptr, *out_ptr;

	//Opening file in read mode
	in_ptr = fopen("in.txt","r");
	if(in_ptr==NULL)
	{
		printf("File not exist...!\n");
		exit(0);
	}

	//Opening file in write mode
	out_ptr = fopen("out.txt","w");
	if(out_ptr==NULL)
	{
		printf("File not exist...!\n");
		exit(0);
	}

	//Function calling
	copyFile(in_ptr, out_ptr);

	//Cose files
	fclose(in_ptr);
	fclose(out_ptr);
	return 0;
}