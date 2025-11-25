#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* next;
}*front=NULL,*rear=NULL;
typedef struct node Node;
void display()
{
	Node* temp=front;
	while(temp)
	{
		printf("%d ",temp->info);
		temp=temp->next;
	}
	printf("\n");
}
void enqueue(int data)
{
	Node* new=malloc(sizeof(Node));
	new->info=data;
	new->next=NULL;
	if(rear==NULL)
	{
		front=rear=new;
		return;
	}
	rear->next=new;
	rear=new;
}
int dequeue()
{
	if(front==NULL)
	{
		printf("Queue is underflow\n");
		return -1;
	}
	Node* temp=front;
	int val=temp->info;
	front=front->next;
	if(front==NULL)
		rear=NULL;
	free(temp);
	return val;
}
void main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	display();
	printf("%d\n",dequeue());
	display();
}


