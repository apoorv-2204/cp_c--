#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node *link;
};
struct node *head, *newnode, *temp;
void insert();
void del();
void traverse();


void main()
{
int choice;
	head = NULL;
	do
	{
		printf("\nMenu");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. Travese");
		printf("\n4. Exit");
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
			printf("Invalid choice \n");
		}
	}while(1);
}

void insert()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter any element ");
	scanf("%d",&newnode->info);
	newnode->link=NULL;
	if(head==NULL)
	{
		head = newnode;
	}
	else
	{	
		temp = head;
		while(temp->link!=NULL)
		{
			temp = temp->link;	
		}
		temp->link=newnode;
	}
}
void del()
{
	int item;
	struct node *prev;
	if(head==NULL)
	{
		printf("List is empty cannot deleted \n");
	}
	else
	{
		temp =head;
		printf("Enter item do u want delete ");
		scanf("%d",&item);
		while(temp->info!=item && temp!=NULL)
		{
			prev=temp;
			temp = temp->link;
		}
		if(temp==NULL)
		{
			printf("Item not found \n");
		}
		else
		{
			if(temp==head)
			{
				head=temp->link;
				temp->link=NULL;
				free(temp);
			}
			else
			{
				prev->link=temp->link;
				temp->link=NULL;
				free(temp);
			}
		}
	}
}
void traverse()
{
	if(head==NULL)
	{
		printf("List is empty cannot traverse ");
	}
	else
	{
		temp = head;
		while(temp!=NULL)
		{
			printf("%d\n",temp->info);
			temp = temp->link;
		}
	}
}

