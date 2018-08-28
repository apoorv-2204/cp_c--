#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

void push();
void pop();
void traverse();

int s[MAXSIZE], top=-1;

void main()
{
	int choice;
	do
	{
		printf("\nMenu");
		printf("\n1. PUSH");
		printf("\n2. POP");
		printf("\n3. TRAVERSE");
		printf("\n4. Exit");
		printf("Enter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;		
			case 3:
				traverse();
				break;	
			case 4:
				exit(0);
			default:
				printf("\nInvalid Choice");
		}
	}while(1);
}

void push()
{
	if(top==MAXSIZE-1)
	{
		printf("Stack is full\n");
	}
	else
	{
		top = top+1;
		printf("Enter any element ");
		scanf("%d",&s[top]);
	}
}
void pop()
{
	if(top==-1)
	{
		printf("Stack is empty cannot delete\n");
	}
	else
	{
		printf("Deleted element %d\n",s[top]);
		top = top-1;
	}
}
void traverse()
{
	int i;
	if(top==-1)
	{
		printf("Stack is empty cannot traverse \n");
	}
	else
	{
		for(i=0;i<=top;i++)
		{
			printf("%d\n",s[i]);
		}
	}
}

