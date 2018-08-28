#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

void insert();
void del();
void traverse();
int q[MAXSIZE],front=-1,rear=-1;

void main()
{
	int choice;	
	do
	{
		printf("\nMenu");
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Traverse");
		printf("\n4.Exit");
		printf("\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				traverse();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice ");
		}
	}while(1);
}
void insert()
{
	if(rear==MAXSIZE-1)
	{
		printf("Queue is full cannot inserted \n");
	}
	else
	{
		if(front==-1)
		{
			front=0;			
		}
		rear=rear+1;
		printf("Enter any element ");
		scanf("%d",&q[rear]);
	}
}
void del()
{
	if(front==-1)
	{
		printf("Queue is empty cannot deleted \n");
	}
	else
	{
		printf("Deleted element %d\n",q[front]);
	if(front==rear)	
	{
		front=rear=-1;
	}
	else
	{
		front = front+1;
	}
	}
}
void traverse()
{
	int i;
	if(front==-1)
	{
		printf("Queue is empty cannot traverse\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",q[i]);
		}
	}
}

