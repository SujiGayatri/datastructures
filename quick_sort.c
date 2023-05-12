#include<stdio.h>
void swap(int *a,int i,int j)
{
	int t;
	t=a[i];
	a[i]=a[j];
	a[j]=t;
}
int partition(int *a,int l,int h)
{
	int p=h,i,j;
	for(i=l,j=l;i<p;i++)
	{
		if(a[i]<a[p])
		{
			swap(a,i,j);
			j++;
		}
	}
	swap(a,j,p);
	return j;
}
void quick_sort(int *a,int l,int h)
{
	if(l<h)
	{
		int p;
		p=partition(a,l,h);
		quick_sort(a,l,p-1);
		quick_sort(a,p+1,h);
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
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
