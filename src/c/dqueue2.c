#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

void ins_front();
void ins_rear();
void del_front();
void del_rear();
void traverse();
	
int q[MAXSIZE],front=-1,rear=-1;

void main()
{
	int choice;
	do
	{
		printf("\nMenu");
		printf("\n1.Insert in front");
		printf("\n2.Insert in rear");
		printf("\n3.Delete in front");
		printf("\n4.Delete in rear");
		printf("\n5.Traverse");
		printf("\n6.Exit");
		printf("\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				ins_front();
				break;
			case 2:
				ins_rear();
				break;		
			case 3:
				del_front();
				break;	
			case 4:
				del_rear();
				break;	
			case 5:
				traverse();
				break;	
			case 6:
				exit(0);
			default:
				printf("Invalid Choice");
		}
	}while(1);
}

void ins_front()
{
	if(front<=0)
	{
		printf("Element cannot insert in front position \n");
	}
	else
	{
		front = front-1;
		printf("Enter any element ");
		scanf("%d",&q[front]);
	}
}
void ins_rear()
{
	if(rear==MAXSIZE-1)
	{
		printf("Element cannot insert in rear position \n");
	}
	else
	{
		if(front==-1)
			front=0;
		rear = rear+1;
		printf("Enter any element ");
		scanf("%d",&q[rear]);
	}
}
void del_front()
{
	if(front==-1)
	{
		printf("Queue is empty cannot deleted in front position \n");
	}
	else
	{
		printf("Delete element %d\n",q[front]);
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=front+1;	
		}
	}
}
void del_rear()
{
	if(rear==-1)
	{
		printf("Queue is empty cannot deleted in rear position \n");
	}
	else
	{
		printf("Deleted element %d\n",q[rear]);
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			rear = rear-1;
		}
	}
}
void traverse()
{
	int i;
	if(front==-1)
	{
		printf("Queue is empty cannot traverse \n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",q[i]);
		}
	}
}
