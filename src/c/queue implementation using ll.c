#include<stdio.h>
#include<stdlib.h>

typedef struct qlinkedlist
{
  int data;
  struct qlinkedlist* next;
}node;

node * rptr, * fptr;
int count=0,size;

int isempty()
{
   return (count==0?1:0);
}
int isfull()
{
   return ((count==size)?1:0);
}
 void init()
 {
     printf("\nentre  size of Queue = ");
     scanf("%d",&size);
}
void push()
{
    if(isfull())
    {
      printf("\nQueue IS FULL\n");
    }
    else if(count==0)
    {
          node * n1;
          n1=(node * )malloc(sizeof(node));
          fptr=rptr=n1;
          printf("\nEntre  %d Element of queue = ",count);
          scanf("%d",&n1->data);
          n1->next= NULL;
          count++;
    }
    else
    {
           node * n2;
           n2=(node * )malloc(sizeof(node));
           rptr->next=n2;
           printf("\nEntre  %d Element of Stacks = ",count);
           scanf("%d",&n2->data);
           n2->next= NULL;
           rptr=n2;
           count++;
     }
}


void pop()
{
    if(isempty())
    {
      printf("\nQueue Is Empty\n");
    }
    else
    {
          node * temp;
          printf("\n%d data deleted",fptr->data);
          temp=fptr;
          fptr=temp->next;
          temp->data=0;
          temp->next=NULL;
          free(temp);
          count--;
    }
}
void peep()
{
    if(isempty())
    {
      printf("\nQueue is empty\n");
    }
    else
    {

          node * chk;
          chk=fptr;
          int i=0;
          for(;i<count;i++)
          {
            printf("\t%d\n",chk->data);
            chk=chk->next;
          }
    }
}
int main()
{
  int input;
  do{
        printf("\nENTRE YOUR CHOICE\n");
        printf("\n0 to initialize Queue ");
        printf("\n1 to entre data in Queue");
        printf("\n2 to delete data from Queue");
        printf("\n3 to display data");
        printf("\n4 for exit\n\n = ");
        scanf("%d",&input);
    switch(input)
    {
      case 0:init();
             break;
      case 1:push();
             break;
      case 2:pop();
             break;
      case 3:peep();
             break;
      default: printf("\nentre correct choice\n");
            break;
    }
  }while(input!=4);

  return 0;

}


