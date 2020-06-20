#include<stdio.h>

// ArrStruct contains two arrays
struct ArrStruct
{
	int c[100][100];
	char b[100][100];
};

// Implementation of LCS_LENGTH
struct ArrStruct LCS_LENGTH(char X[], char Y[], int m, int n)
{
	struct ArrStruct arr;
	int i,j;
	for(i=1;i<m+1;i++)
	{
		arr.c[i][0] = 0;
	}
	for(j=0;j<n+1;j++)
	{
		arr.c[0][j] = 0;
	}
	for(i=1;i<m+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			if(X[i-1]==Y[j-1])
			{
				arr.c[i][j] = arr.c[i-1][j-1]+1;
				// C means corner
				arr.b[i][j]='C';
			}
			else if(arr.c[i-1][j]>=arr.c[i][j-1])
			{
				arr.c[i][j] = arr.c[i-1][j];
				// U means UP
				arr.b[i][j] = 'U';
			}
			else
			{
				arr.c[i][j] = arr.c[i][j-1];
				// L means Left
				arr.b[i][j] = 'L';
			}
		}
	}
	return arr;
}

// Implementation of PRINT_LCS
void PRINT_LCS(struct ArrStruct arr, char X[], int i, int j)
{
	// Base condition
	if(i==-1 || j==-1)
	{
		return;
	}
	if(arr.b[i][j]=='C')
	{
		PRINT_LCS(arr,X,i-1,j-1);
		printf("%c",X[i-1]);
	}
	else if(arr.b[i][j]=='U')
	{
		PRINT_LCS(arr,X,i-1,j);
	}
	else
	{
		PRINT_LCS(arr,X,i,j-1);
	}
}

int main()
{
	char X[] = "ABCBDAB";
	char Y[] = "BDCABA";
	int m=sizeof(X);
	int n=sizeof(Y);
	// Function calling
	struct ArrStruct arr = LCS_LENGTH(X,Y,m,n);
	// Function calling
	PRINT_LCS(arr,X,m,n);
	return 0;
}
