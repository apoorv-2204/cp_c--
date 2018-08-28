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

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("Sorted element \n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
