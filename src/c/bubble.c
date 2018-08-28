#include<stdio.h>

void main()
{
	int a[20],i,j,n,temp;
	printf("How many element do u want enter ");
	scanf("%d",&n);
	printf("Now enter element \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	printf("Sorted Element\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
