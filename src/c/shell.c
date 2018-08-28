#include<stdio.h>

void main()
{
 int a[20],n,i,inte,temp,j;
 printf(" how many numbers u want to enter ");
 scanf("%d",&n);
 printf("\n enter items \n");

 for(i=0;i<n;i++)
  scanf("%d",&a[i]);

 inte=4;

 while(inte >= 1)
 {
  for(j=0;j<inte;j++)
   {
   for(i=j;i<n-inte;i=i+inte)
	{
	    if( a[i] > a[i+inte])
    	{
		      temp = a[i];
		      a[i]=a[i+inte];
		      a[i+inte]=temp;
	    }
	 }
    }
   inte=inte-1;
 }

 printf("\n sorted array is \n");

 for(i=0;i<n;i++)
  printf("%d\n",a[i]);

}

