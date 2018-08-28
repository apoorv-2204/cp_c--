#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};

struct node *newnode, *head, *temp;
void insert();
void del();
void ltraverse();
void rtraverse();

void main()
{
	int choice;
	head=NULL;
	do
	{
		printf("Menu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. LTraverse\n");
		printf("4. RTraverse\n");
		printf("5. Exit\n");
		printf("Enter your choice ");
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
				ltraverse();
				break;	
			case 4:
				rtraverse();
				break;	
			case 5:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}while(1);
}

void insert()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter any element ");
	scanf("%d",&newnode->info);
	newnode->llink=NULL;
	newnode->rlink=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		temp = head;
		while(temp->rlink!=NULL)
		{
			temp = temp->rlink;
		}
		temp->rlink=newnode;
		newnode->llink=temp;
	}
}
void del()
{
	int item;
	if(head==NULL)
	{
		printf("List is empty cannot deleted\n");
	}
	else
	{
		temp = head;
		printf("Enter item do u want delete ");
		scanf("%d",&item);
		while(temp->info!=item && temp!=NULL)
		{
			temp = temp->rlink;
		}
		if(temp==NULL)
		{
			printf("Item not found\n");
		}
		else
		{
			if(head==temp)
			{
				head=temp->rlink;
				head->llink=NULL;
				temp->rlink=NULL;
				free(temp);
			}	
			else
			{
				(temp->llink)->rlink=temp->rlink;
				(temp->rlink)->llink=temp->llink;
			temp->llink=temp->rlink=NULL;
			free(temp);
			}
		}
	}
}
void ltraverse()
{
	if(head==NULL)
	{
		printf("List is empty cannot traverse\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d\n",temp->info);
			temp = temp->rlink;
		}
	}
}
void rtraverse()
{
	if(head==NULL)
	{
		printf("List is empty cannot traverse \n");
	}
	else
	{
		temp = newnode;
		while(temp!=NULL)
		{
			printf("%d\n",temp->info);
			temp = temp->llink;
		}
	}
}
