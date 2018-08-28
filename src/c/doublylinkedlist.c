#include <stdio.h>
#include<stdlib.h>
typedef struct doublylinkedlist
{
  struct doublylinkedlist * prev;
  int data;
  struct  doublylinkedlist * next;
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
  b1->prev=NULL;
  b1->data=item;
  b1->next=NULL;
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
       node * b2;
       int item;
       b2=(node *)malloc(sizeof(node));
       printf("\nEntre data = \n");
       scanf("%d",&item);
       b2->data=item;
       b2->next=NULL;
       rptr->next=b2;
       b2->prev=rptr;
       rptr=b2;
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
       b1->prev=NULL;
       fptr->prev=b1;
       fptr=b1;
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
       temp->data=0;
       temp->next=NULL;
       temp->prev=NULL;
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
       node * temp;
       temp=rptr;
       rptr=temp->prev;
       temp->next=NULL;
       temp->prev=NULL;
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
       int z;
       for(z=0;z<count;z++)
       {
         printf("\n %u \t (%d) \t %u \t ",ls->prev,ls->data,ls->next);
         ls=ls->next;
        }
  }
}
void insert_bw()
{
       node * b2,* temp,* sla;
       temp=fptr;
       int item,position;
       printf("\nEntre postion AT which you want to entre data= \n");
       scanf("%d",&position);
       if(position<1||position>count+1)
       {
         printf("\nIncorrect position\n");
       }
       else
       {
           if(position==0)
           {
             insert_f();
           }
           else
            {
               if(position==count+1)
               {
                insert_r();
               }
               else
               {
                 b2=(node *)malloc(sizeof(node));
                 printf("\nEntre data = \n");
                 scanf("%d",&item);
                 b2->data=item;
                 int i;
                 for(i=0;i<position-1;i++)
                 {
                  sla=temp;
                  temp=temp->next;
                 }
                b2->prev=sla;
                b2->next=temp;
                sla->next=b2;
                temp->prev=b2;
               }
            }
       }

         printf("\n %u \t (%d) \t %u \t ",b2->prev,b2->data,b2->next);
       count++;
}

void delete_bw()
{
       node * temp,* sla;
       temp=fptr;
       int position;
       printf("\nEntre postion at which you want to delete data= \n");
       scanf("%d",&position);
       if(position<1||position>count)
       {
         printf("\nIncorrect position\n");
       }
       else
       {
           if(position==1)
           {
             delete_f();
           }
           else
            {
               if(position==count)
               {
                delete_r();
               }
               else
               {
                 int i;
                 for(i=0;i<position-1;i++)
                 {
                  sla=temp;
                  temp=temp->next;
                 }
                temp->next->prev=sla;
                sla->next=temp->next;
                temp->prev=NULL;
                temp->data=0;
                temp->next=NULL;
               }
            }
       }
}
int main()
{
  init();
  int input;
  do{
        printf("\nENTRE YOUR CHOICE\n");
        printf("\n1 FOR INSERT FROM REAR");
        printf("\n2 FOR DELETE FROM REAR");
        printf("\n3 FOR INSERT FROM FRONT");
        printf("\n4 FOR DELETE FROM FRONT");
        printf("\n5 FOR DISPLAY");
        printf("\n6 FOR INSERT FROM BETWEEN");
        printf("\n7 FOR DELETE FROM BETWEEN");
        printf("\n8 for exit");
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
      case 6:insert_bw();
             break;
      case 7:delete_bw();
             break;
      default: printf("\nentre correct choice\n");
            break;
    }
  }while(input!=8);
  return 0;
}
