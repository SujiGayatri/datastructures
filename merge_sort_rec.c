#include<stdio.h>
void merge(int *a,int l,int h,int m)
{
	int i=l,j=m+1,r[h-l+1],k=0;
	while(i<=m && j<=h)
	{
		if(a[i]>a[j])
		{
			r[k++]=a[j++];
		}
		else
		{
			r[k++]=a[i++];
		}	
	}
	while(j<=h)
	{
		r[k++]=a[j++];
	}
	while(i<=m)
	{
		r[k++]=a[i++];
	}
	for(k=0,i=l;i<=h;i++,k++)
	{
		a[i]=r[k];
	}
}
void merge_sort(int *a,int l,int h)
{
	if(l<h)
	{
		int m;
		m=(l+h)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,h);
		merge(a,l,h,m);
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
	merge_sort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
