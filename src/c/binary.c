#include<stdio.h>

void main()
{
   int a[20],n,i,top,bottom,mid,item,flag=0;
   printf("How many element do u want enter ");
   scanf("%d",&n);
   printf("Now enter element \n");
   for(i=0;i<n;i++)
   {
	scanf("%d",&a[i]);
   }
   printf("Enter item do u want search ");
   scanf("%d",&item);
   top = 0;
   bottom = n-1;
   mid = (top+bottom)/2;
   while(top<=bottom)
   {
	if(a[mid]==item)      
        {
	   flag=1;
           break;
        }
	if(a[mid]>item)	
	{
	    bottom=mid-1;
	}
	else
	{
	    top=mid+1;
	}
	mid=(top+bottom)/2;
   }
   if(flag==0)
   {
	printf("item not found \n");
   }
   else
   {
	printf("Item %d found at %d position \n",a[mid],mid+1);
   }
}
