#include<stdio.h>

void PrintSudouRegion(int region[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",region[i][j]);
		}
		printf("\n");
	}
}

void SudokuRegion(int region[3][3])
{
	// Intialize all entries to 0
	int checker[10] = {0};
	int x,y,i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			// Make entry of region[i][j] to 1
			checker[region[i][j]]=1;
			// If region[i][j] is 0 then store the indices
			if(region[i][j]==0)
			{
				x=i,y=j;
			}
		}
	}
	for(i=1;i<10;i++)
	{
		// If i is the missed numbers
		if(checker[i]==0)
		{
			// Place i in the location
			region[x][y]=i;
		}
	}
}

void PrintPrimesBetween(int x, int y)
{
	int i,j;
	// Initialy assumed that all are non-primes
	int isPrime[y+1];
	for(i=1;i<y+1;i++)
	{
	    isPrime[i]=0;
	}

	// Check each number from 1 to y
	for(i=1;i<y+1;i++)
	{
		int factors=0;
		// Find number of factors of i from 1 to i
		for(j=1;j<=i;j++)
		{
			// If j is a factor of i then increment factors by 1
			if(i%j==0)
			{
				factors++;
			}
		}
		// Prime number will have only 2 factors
		if(factors==2)
		{
			isPrime[i]=1;
		}
	}
	// From x to y
	for(i=x;i<=y;i++)
	{
		// If i is prime then print it
		if(isPrime[i]==1)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
}

int main()
{
	int region1[3][3] = {{0,2,3},{4,5,6},{7,8,9}};
	printf("Before:\n");
	PrintSudouRegion(region1);
	SudokuRegion(region1);
	printf("After:\n");
	PrintSudouRegion(region1);

	int region2[3][3] = {{5,8,6},{9,2,0},{7,1,3}};
	printf("Before:\n");
	PrintSudouRegion(region2);
	SudokuRegion(region2);
	printf("After:\n");
	PrintSudouRegion(region2);

	int x=1,y=100;
	printf("Prime numbers between %d and %d:\n",x,y);
	PrintPrimesBetween(x,y);
	return 0;
}