#include<stdio.h>
int binary_sear(int *arr,int l,int h,int x)
{
	int m;
	if(l>h)
	{
		return -1;
	}
	m=(l+h)/2;
	if(arr[m]==x)
	{
		return m;
	}
	else if(arr[m]>x)
	{
		h=m-1;
	}
	else if(arr[m]<x)
	{
		l=m+1;
	}
	return binary_sear(arr,l,h,x);
}
int main()
{
	int n,x,i,arr[100],r;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&x);
	r=binary_sear(arr,0,n-1,x);
	printf("%d",r);
}
