#include<stdio.h>

void main()
{
int a[20],i,n,item;
system("clear");
printf("How many element do u want enter ");
scanf("%d",&n);
printf("Now enter element \n");
for(i=0;i<n;i++)
{
   scanf("%d",&a[i]);
}
printf("Enter item do u want search ");
scanf("%d",&item);
for(i=0;i<n;i++)
{
   if(a[i]==item)	
   {
	break;
   }
}
if(i==n)
{
   printf("Item not found \n");
}
else
{
   printf("Item %d found at %d position\n",a[i],i+1);
}
}
