#include<stdio.h>
#include<stdlib.h>

/* Using Arrays:
#define Max 5
int stack[Max];
int top=-1;
void display()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
		return;
	}
	int i;
	for(i=top;i>=0;i--)
		printf("%d -> ",stack[i]);
	printf("\n");
}
void push(int x)
{
	if(top==Max-1)
	{
		printf("Stack is full\n");
		return;
	}
	stack[++top]=x;
}
int pop()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
		return -1;
	}
	return stack[top--];
}
int peek()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
		return -1;
	}
	return stack[top];
} */
struct node 
{
	int info;
	struct node* next;
}*top=NULL;
typedef struct node Node;
void display()
{
	if(top==NULL)
	{
		printf("Stack is Empty\n");
		return;
	}
	Node* temp=top;
	while(temp)
	{
		printf("%d -> ",temp->info);
		temp=temp->next;
	}
	printf("\b\b\b\b\n");
}
void push(int data)
{
	Node* new=malloc(sizeof(Node));
	new->info=data;
	new->next=top;
	top=new;
}
int pop()
{
	if(top==NULL)
	{
		printf("Stack is Empty\n");
		return -1;
	}
	Node* temp=top;
	top=top->next;
	int val=temp->info;
	free(temp);
	return val;
}
int peek()
{
	if(top==NULL)
	{
		printf("Stack is Empty\n");
		return -1;
	}
	return top->info;
}
void main()
{
	while(1)
	{
		printf("1 for push\n2 for pop\n3 for peek\n4 for exit\n");
		int choice;
		printf("Enter choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter data : ");
				int data;
				scanf("%d",&data);
				push(data);
				display();
				break;
			case 2: printf("Popped element is %d\n",pop());
				display();
				break;
			case 3: printf("Peek is %d\n",peek());
				break;
			case 4 :
				exit(0);
			default: printf("Invalid\n");
		}
	}
}
