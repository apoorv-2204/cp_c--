#include<stdio.h>
void main()
{
 int a[20],n,i;

 printf(" how many numbers u want to enter ");
 scanf("%d",&n);
 printf("\n Now enter items \n");

 for(i=0;i<n;i++)
  scanf("%d",&a[i]);

 mergepass(a,0,n-1);

 printf("\n sorted array is \n");

 for(i=0;i<n;i++)
  printf("%d\n",a[i]);

}

mergepass(int list[],int low,int high)
{
  int mid;

  if (low != high)
  {
   mid=(low+high)/2;
   mergepass(list,low,mid);
   mergepass(list,mid+1,high);
   mergesort(list,low,mid,high);
  }
return;
}


mergesort(int list[],int top,int size,int bot)
{
 int f1,t1,s1,u;
 int final[50];
   f1=top;
   t1=top;
   s1=size+1;

   while (f1<= size && s1<= bot)
   {
    if (list[f1] <= list[s1])
     {
      final[t1] = list[f1];
      f1=f1+1;
     }
    else
     {
       final[t1] = list[s1];
       s1=s1+1;
     }
     t1=t1+1;
   }

   if (f1<=size)
    for (f1=f1;f1<=size;f1++)
    {
      final[t1] = list[f1];
      t1=t1+1;
    }
   else
     for (s1=s1;s1<=bot;s1++)
    {
      final[t1] = list[s1];
      t1=t1+1;
    }

   for(u=top;u<=bot;u++)
     list[u]=final[u];
  return;
 }


