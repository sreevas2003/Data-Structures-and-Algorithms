#include<stdio.h>
void bubble(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;i<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void selection(int arr[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]>arr[min])
				min=j;
		}
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
}
void insertion(int arr[],int n)
{
	int i,j,cu;
	for(i=0;i<n;i++)
	{
		cu=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>cu)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=cu;
	}
}
void merge(int arr[],int l,int m,int r)
{
	int b[50],i,j,k=0;
	i=l;
	j=m+1;
	int n=r-l+1;
	while(i<=m && j<=r)
	{
		if(arr[i]<=arr[j])
			b[k]=arr[i++];
		else
			b[k]=arr[j++];
		k++;
	}
	while(j<=r)
		b[k++]=arr[j++];
	while(i<=m)
		b[k++]=arr[i++];
	for(k=0;k<n;k++)
		arr[k+l]=b[k];
}


void mergesort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int temp,j,i=low-1;
	for(j=low;j<high;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return i+1;
}

void quicksort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}
void main()
{
	int n,i;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	int arr[n];
	printf("enter elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
	printf("Sorted Elements : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
