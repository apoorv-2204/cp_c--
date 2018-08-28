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
int isfull_1(queue * z)
{
    if(z->rear==MAXSIZE)
        return 1;
        return 0;
}
int isfull_2(queue * z)
{
    if(z->front==0)
        return 1;
        return 0;
}
void insert_r(queue * z)
{
     if(isfull_1(z))
     {
      printf("\nQueue is full from rear end \n");
     }
     else
     {
      printf("\nEntre your item =\n");
      scanf("%d",&z->data[z->rear]);
      z->rear++;
     }
}
void insert_f(queue * z)
{
     if(isfull_2(z))
     {
      printf("\nQueue is full from front end \n");
     }
     else
     {
      z->front--;
      printf("\nEntre your item =\n");
      scanf("%d",&z->data[z->front]);
      z->rear++;
     }
}
void delete_r(queue * z)
{
     if(isempty(z))
     {
      printf("\n\nQueue is empty\n\n");
     }
     else
     {
      z->rear--;
      printf("%d your item is deleted \n",z->data[z->rear]);
     }
}

void delete_f(queue * z)
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
        printf("\n1 FOR INSERT FROM REAR\n");
        printf("\n2 FOR DELETE FROM REAR\n");
        printf("\n3 FOR INSERT FROM FRONT\n");
        printf("\n4 FOR DELETE FROM FRONT\n");
        printf("\n5 FOR DISPLAY\n");
        printf("\n6 for exit\n");
        scanf("%d",&input);
    switch(input)
    {
      case 1:insert_r(&q1);
             break;
      case 2:delete_r(&q1);
             break;
      case 3:insert_f(&q1);
             break;
      case 4:delete_f(&q1);
             break;
      case 5:display(&q1);
             break;
      default: printf("\nentre correct choice\n");
            break;
    }
  }while(input!=6);
}
