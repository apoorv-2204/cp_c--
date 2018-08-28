#include<stdio.h>

void qsort(int[], int,int );
void main()
{
	int a[20],n,i;
	printf("How many element do u want enter ");
	scanf("%d",&n);
	printf("Now enter element \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,0,n-1);
	printf("Sorted element \n");
	for(i=0;i<n;i++)	
	{
		printf("%d\n",a[i]);
	}
}

void qsort(int b[], int s, int e)
{
	int temp;
	if(s<e)
	{
		int l,r,key;
		l=s;
		r=e+1;
		key = b[s];
		do
		{
			do
			{
				l++;
			}while(b[l]<key);
			
			do
			{
				r--;
			}while(b[r]>key);
			if(l<r)
			{
				temp = b[l];
				b[l] = b[r];
				b[r] = temp;
			}
		}while(l<r);

		temp = b[s];
		b[s] = b[r];
		b[r] = temp;

	qsort(b,s,r-1);
	qsort(b,r+1,e);
	}
}
