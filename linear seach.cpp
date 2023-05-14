#include<stdio.h>
int linearsearch(int n,int *arr,int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int n,x,arr[100],i,r;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&x);
	r=linearsearch(n,arr,x);
	printf("%d",r);
}
