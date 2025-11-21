#include<stdio.h>
int linear(int arr[],int n,int tar)
{
	int i;
	for(i=0;i<n;i++)
		if(tar==arr[i])
			return i;
	return -1;
}
//binary search only for sorted array..
int binary(int arr[],int n,int tar)
{
	int l,r,mid;
	l=0;
	r=n-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(arr[mid]==tar)
			return mid;
		else if(arr[mid]<tar)
			l=mid+1;
		else
			r=mid-1;
	}
	return -1;
}
void main()
{
	int n,tar;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	int i,arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter tar element : ");
	scanf("%d",&tar);
	int pos=linear(arr,n,tar);
	if(pos!=-1)
		printf("Element found at %d position\n",pos);
	else
		printf("Not found\n");
}
	
