#include<stdio.h>
int binary_sear(int *arr,int n,int x,int l,int h)
{
	int m;
	m=(l+h)/2;
	if(arr[m]==x)
	{
		return 1;
	}
	if(arr[m]>x)
	{
		h=m-1;
	}
	if(arr[m]<x)
	{
		l=m+1;
	}
}
int main()
{
	int n,l,h,x,i,arr[100];
	scanf("%d%d%d",&n,&l,&h);
	for(i=l;i<h;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&x);
	binary_sear(arr,n,x,l,h);
}
