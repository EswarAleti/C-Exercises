#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100

void strncpy_array_sub(char str1[] , char str2[], size_t num)
{
	int i;
	//replace each character
	for(i=0;i<num && str2[i]!='\0';i++)
	{
		str1[i]=str2[i];
	}
	str1[i]='\0';
}

void strcat_array_sub(char str1[] , char str2[], size_t num)
{
	int index = 0,i;
	//Go to the end of str1 array
	while(str1[index] != '\0')
	{
		index++;
	}
	//Add to end of str1
	for(i=0;i<num;i++)
	{
		str1[index]=str2[i];
		index++;
	}
	str1[index] = '\0';
}

void strncpy_ptr(char *str1 , char *str2, size_t num)
{
	int i;
	////replace each character
	for(i=0;i<num && *str2!='\0';i++)
	{
		*str1=*str2;
		str1++;
		str2++;
	}
	//To eliminate new line character
	str1--;
	*str1='\0';
}

void strcat_ptr(char *str1 , char *str2, size_t num)
{
	int index = 0,i;
	//Go to the end of str1
	while(*str1 != '\0')
	{
		str1++;
	}
	//To eliminate new line character
	str1--;
	//Add to end of str1
	for(i=0;i<num && *str2!='\0';i++)
	{
		*str1=*str2;
		str1++;
		str2++;
	}
	//To eliminate new line character
	str1--;
	*str1='\0';
}

int main()
{
	char str1[N] , str2[N], str3[N];
	printf("\n****Using Subscript****\n");
	printf("Enter string 1:");
	scanf("%[^\n]%*c", str1); 
	printf("Enter string 2:");
	scanf("%[^\n]%*c", str2); 
	strncpy_array_sub(str3, str2, sizeof(str2));
	printf("string copy using array subscript: %s\n",str3);
	strcat_array_sub(str1, str2, sizeof(str2));
	printf("String concatination using array subscript: %s\n",str1);
	
	printf("\n****Using pointer****\n");
	char *str_ptr1,*str_ptr2,*str_ptr3;
	str_ptr1 = malloc(sizeof(char) * N);
	str_ptr2 = malloc(sizeof(char) * N);
	str_ptr3 = malloc(sizeof(char) * N);
	printf("Enter string 1:");
	fgets(str_ptr1, N, stdin);
	printf("Enter string 2:");
	fgets(str_ptr2, N, stdin);
	strncpy_ptr(str_ptr3,str_ptr2,strlen(str_ptr2));
	printf("string copy using pointer: %s\n",str_ptr3);
	strcat_ptr(str_ptr1,str_ptr2,strlen(str_ptr2));
	printf("String concatination using pointer: %s\n",str_ptr1);
	return 0;
}
