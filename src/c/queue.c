#include <stdio.h>
#define MAXSIZE 9
typedef struct queue
{
  int data[MAXSIZE];
  int front,rear;
}queue;
void init(queue * z)
{
  z->front=0;
  z->rear=0;
}
int isempty(queue * z)
{
    if(z->front==z->rear)
        return 1;
        return 0;
}
int isfull(queue * z)
{
    if(z->rear==MAXSIZE)
        return 1;
        return 0;
}
void push(queue * z)
{
     if(isfull(z))
     {
      printf("\nQueue is full\n");
     }
     else
     {
      printf("\nEntre your item =\n");
      scanf("%d",&z->data[z->rear]);
      z->rear++;
     }
}
void pop(queue * z)
{
     if(isempty(z))
     {
      printf("\n\nQueue is empty\n\n");
     }
     else
     {
      printf("%d your item is deleted \n",z->data[z->front]);
      z->front++;
     }
}
     void display(queue * z)
     {
      if(isempty(z))
      {
       printf("queue is empty");
      }
      else
      {
      int i=0;
      for(i=z->front;i<z->rear;i++)
      {
          printf("%d\t",z->data[i]);
      }
      }
     }

void main()
{
  queue q1;
  init(&q1);
  int input;
  do{
        printf("\nENTRE YOUR CHOICE\n");
        printf("\n1 FOR INSERT\n");
        printf("\n2 FOR DELETE\n");
        printf("\n3 FOR DISPLAY\n");
        printf("\n4 for exit\n");
        scanf("%d",&input);
    switch(input)
    {
      case 1:push(&q1);
             break;
      case 2:pop(&q1);
             break;
      case 3:display(&q1);
             break;
      default: printf("\nentre correct choice\n");
        break;
    }
  }while(input!=4);
}
