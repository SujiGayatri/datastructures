#include<stdio.h>
void bubble_sort(int *a,int n)
{
	int i,t,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
		   if(a[j]>a[j+1])
		   {
		   t=a[j];
		   a[j]=a[j+1];
		   a[j+1]=t;	
		   }
	    }
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubble_sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
