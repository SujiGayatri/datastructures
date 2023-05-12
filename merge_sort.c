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
void merge_sort(int *a,int n)
{
	int i,l,h,m,p;
	for(p=2;p<=n;p=p*2)
	{
		for(i=0;i+p<=n;i=i+p)
		{
			l=i;
			h=p+i-1;
			m=(l+h)/2;
			merge(a,l,h,m);
		}
	}
	if(p/2<n && n%2==0)
	{
	    m=p/2-1;
		l=0;
		h=n-1;
		merge(a,l,h,m);	
	}	
	else
	{
		m=n-2;
		l=p/2;
		h=n-1;
		merge(a,l,h,m);
		merge(a,0,n-1,p/2-1);
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
	merge_sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
