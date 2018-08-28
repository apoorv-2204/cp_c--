#include <stdio.h>

void main()
{
   int  a[20];
   int n,i,temp,j,k; 

   printf(" enter number of elements in array ");
   scanf("%d",&n);
   printf( " enter array elements ");

   for (i=0; i<n;i++)
     scanf("%d",&a[i]);

       for (i=1;i<=n-1;i++)
       {
				  j=0;                 
				  while(j<i && a[i]>a[j])
				    j++;			    


					  temp= a[i];

					  k=i;                              
					  while(k >j)
					  {
					    a[k]=a[k-1];
					    k=k-1;
					  }		
				  a[j] = temp;
      }

     printf("\n sorted list is :\n ");
     for (i=0; i<=n-1;i++)
     {
     printf("%d\t",a[i]);
     }


}


