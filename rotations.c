#include<stdio.h>
void left(int arr[],int n,int k)
{
	int i;
	while(k)
	{
		int temp=arr[0];
		for(i=0;i<n;i++)
			arr[i]=arr[i+1];
		arr[n-1]=temp;
		k--;
	}
}
void right(int arr[],int n,int k)
{
	int i;
	while(k)
	{
		int temp=arr[n-1];
		for(i=n-1;i>=0;i--)
			arr[i]=arr[i-1];
		arr[0]=temp;
		k--;
	}
}
void main()
{
	int n,k;
	printf("Enter elements : ");
	scanf("%d",&n);
	int i,arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter rotations : ");
	scanf("%d",&k);
	k=k%n;
	printf("left rotation :\n");
	left(arr,n,k);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	printf("right rotation :\n");
	right(arr,n,k);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
