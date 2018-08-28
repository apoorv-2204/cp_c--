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
  b1->next=b1;
  b1->data=item;
  rptr=fptr=b1;
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
       node * b2;
       int item;
       b2=(node *)malloc(sizeof(node));
       printf("\nEntre data = \n");
       scanf("%d",&item);
       b2->next=NULL;
       b2->data=item;
       rptr->next=b2;
       rptr=b2;
       b2->next=fptr;
       count++;
}
void insert_f()
{
       node * b1;
       int item;
       b1=(node *)malloc(sizeof(node));
       printf("\nEntre data = \n");
       scanf("%d",&item);
       b1->data=item;
       b1->next=fptr;
       fptr=b1;
       rptr->next=b1;
       count++;
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
       temp->data=NULL;
       temp->next=NULL;
       rptr->next=fptr;
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
       temp->next=NULL;
       temp->data=0;
       rptr->next=fptr;
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
       int i;
       for(i=0;i<15;i++)
       {
         printf("\t%d",ls->data);
         ls=ls->next;

        }
  }
}


int main()
{
  init();
  int input;
  do{
        printf("\nENTRE YOUR CHOICE\n");
        printf("\n1 FOR INSERT FROM REAR\n");
        printf("\n2 FOR DELETE FROM REAR\n");
        printf("\n3 FOR INSERT FROM FRONT\n");
        printf("\n4 FOR DELETE FROM FRONT\n");
        printf("\n5 FOR DISPLAY\n");
        printf("\n6 for exit\n");
        scanf("%d",&input);
    switch(input)
    {
      case 1:insert_r();
             break;
      case 2:delete_r();
             break;
      case 3:insert_f();
             break;
      case 4:delete_f();
             break;
      case 5:display();
             break;
      default: printf("\nentre correct choice\n");
            break;
    }
  }while(input!=6);
  return 0;
}
