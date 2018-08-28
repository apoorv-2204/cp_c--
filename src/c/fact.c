#include<stdio.h>

int fact(int);
void main()
{
	int n,f;
	printf("Enter any number do u want factorial ");
	scanf("%d",&n);
	f = fact(n);
	printf("Factorial is %d\n",f);
}

int fact(int n)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		n = n*fact(n-1);
		return n;
	}
}
