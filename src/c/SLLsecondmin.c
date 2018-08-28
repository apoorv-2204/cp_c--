#include <stdio.h>
#include<stdlib.h>
typedef struct singlylinkedlist
{
  int data;
  struct singlylinkedlist * next;
}node;

node * fptr;
node * rptr;
int count=0;

void init()
{
  node * b1;
  int item;
  b1=(node *)malloc(sizeof(node));
  printf("\nEntre data = \n");
  scanf("%d",&item);
  b1->next=NULL;
  b1->data=item;
  rptr=b1;
  fptr=b1;
  count++;
}
int isempty()
{
   if(count==0)
    return 1;
    return 0;
}
void insert_r()
{

 		if(count==0)
 		{
 		 					init();
 		}
 		else
 		{
       node * b2;
       int item;
       b2=(node *)malloc(sizeof(node));
       printf("\nEntre data = \n");
       scanf("%d",&item);
       b2->next=NULL;
       b2->data=item;
       rptr->next=b2;
       rptr=b2;
       count++;
   }
}
void insert_f()
{
			if(count==0)
 		{
 		 					init();
 		}
 		else
 		{
       node * b1;
       int item;
       b1=(node *)malloc(sizeof(node));
       printf("\nEntre data = \n");
       scanf("%d",&item);
       b1->data=item;
       b1->next=fptr;
       fptr=b1;
       count++;
			}
}
void delete_f()
{
     if(isempty())
     {
      printf("\n\nList is empty\n\n");
     }
     else
     {
       node * temp;
       temp=fptr;
       fptr=temp->next;
       temp->data=0;
       temp->next=NULL;
       free(temp);
       count--;
     }
}
void delete_r()
{
     if(isempty())
     {
      printf("\n\nList is Empty\n\n");
     }
     else
     {
       node * temp, * sla;
       temp=fptr;
       while(temp->next!=NULL)
       {
          sla=temp;
          temp=temp->next;
       }
       rptr=sla;
       sla->next=NULL;
       temp->next=NULL;
       temp->data=0;
       free(temp);
       count--;
     }
}
void display()
{
      if(isempty())
        {
       printf("\nList is empty\n");
        }
      else
  {
       node * ls;
       ls=fptr;
        do
        {
         printf("\n%d",ls->data);
         ls=ls->next;
        }while(ls!=NULL);
  }
}
void insertatsecondminimum()
{
  if(count==0)
  {
  		    printf("\nFirst element: no second minimum element ");
									init();
  }
  else if(count==1)
  {
                insert_r();
  }
  else
  {
        node * temp, * sla;
        temp=fptr;
        int min=0,smin=0
        min=temp->data;
        while(temp!=NULL)
        {
           if(temp->data<min)
           {
              min=temp->data;
           }
           temp=temp->next;
        }
        temp=fptr;
        smin=temp->data;
          while(temp!=NULL)
        {
           if(temp->data==min)
           {
               temp=temp->next;
              continue;
           }
           else
           {
             if(temp->data<smin)
             {
                if(smin%2==0)
                 {
                     smin=temp->data;
                 }5+3
             }
           }
          temp=temp->next;
        }
        temp=fptr;
        while(temp->data!=smax)
        {
          temp=temp->next;
        }
        if(temp->next==NULL)
        {
            insert_r();
        }
        else
        {
           node * b3;
           int item;
           b3=(node*)malloc(sizeof(node));
           printf("\nEntre data = \n");
           scanf("%d",&item);
           b3->data=item;
           b3->next=temp->next;
           temp->next=b3;
           count++;
        }
  }
}
int main()
{
  int input;
  do{
        printf("\nENTRE YOUR CHOICE\n");
        printf("\n1 FOR insert at second largest\n");
        printf("\n2 FOR DELETE FROM REAR\n");
        printf("\n3 FOR DELETE FROM FRONT\n");
        printf("\n4 FOR DISPLAY\n");
        printf("\n5 for exit\n");
        scanf("%d",&input);
    switch(input)
    {
        case 1: insertatsecondminimum();
                break;
        case 2: delete_r();
             break;
        case 3: delete_f();
             break;
        case 4:display();
             break;
        default: printf("\nentre correct choice\n");
            break;
    }insertatsecondminimum()
}while(input!=5);
   return 0;
}
