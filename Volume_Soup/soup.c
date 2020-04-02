#include<stdio.h>

//soup_volume function definition with diameter and height as parameter
float soup_volume(float d, float h)
{
	//Funding radius
	float r = d/2;
	//Finding volume of the cylinder
	float volume_cylinder = 3.14159*(r*r)*h;
	//Finding volumer of soup which is 95% of the volume of cylinder
	float volume_soup = 0.95*volume_cylinder;
	//return the volume of soup
	return volume_soup;
}

int main()
{
	//User input
	float diameter,height;
	printf("Enter diameter of the cylinder: ");
	scanf("%f",&diameter);
	printf("Enter height of the cylinder: ");
	scanf("%f",&height);
	//Function calling and storing the result
	float soup_vol=soup_volume(diameter,height);
	//Printing result upto 2 decimals
	printf("Volume of soup in can is: %.2f",soup_vol);
	return 0;
}