#include<stdio.h>
void selectionsort(int *a,int n)
{
	int i,j,max,m,t;
	for(i=0;i<n;i++)
	{
		max=a[0];
		m=0;
		for(j=0;j<n-i;j++)
		{
			if(a[j]>max)
			{
				max=a[j];
				m=j;
			}
		}
		t=a[m]; 
		a[m]=a[j-1];
		a[j-1]=t;
  	} 
}
int main()
{
	int n,i,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selectionsort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
