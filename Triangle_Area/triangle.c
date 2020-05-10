#include<stdio.h>
#include<cmath>
int main()
{
	float angle1, angle2, angle3;
	printf("Enter angles of traingle: ");
	scanf("%f%f%f",&angle1,&angle2,&angle3);
	if(angle1>0 && angle2>0 && angle3>0 && (angle1+angle2+angle3)==180)
	{
		float a, b, c;
		printf("Enter sides of traingle: ");
		scanf("%f%f%f",&a,&b,&c);
		float s = (a+b+c)/2;
		float area = sqrt(s*(s-a)*(s-b)*(s-c));
		printf("Area: %0.3f",area);
	}
	else
	{
		printf("Not valid angles\n");
	}
	return 0;
}