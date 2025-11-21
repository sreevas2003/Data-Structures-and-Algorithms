#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* next;
}*head=NULL;
typedef struct node Node;
void display(Node* head)
{
	Node* temp=head;
	while(temp!=NULL)
	{
		printf(" %d ->",temp->info);
		temp=temp->next;
	}
	printf("NULL\n");
}
Node* insert_begin(Node* head,int data)
{
	Node *p;
	p=malloc(sizeof(Node));
	p->info=data;
	p->next=head;
	head=p;
	return head;
}
Node* insert_end(Node* head,int data)
{
	Node *p,*temp;
	p=malloc(sizeof(Node));
	p->info=data;
	p->next=NULL;
	temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=p;
	return head;
}
Node* insert_pos(Node* head,int data,int pos)
{
	Node *p,*temp;
	if(pos==1)
	{
		head=insert_begin(head,data);
		return head;
	}
	p=malloc(sizeof(Node));
	p->info=data;
	p->next=NULL;
	temp=head;
	int i;
	for(i=1;i<pos-1;i++)
		temp=temp->next;
	if(temp==NULL)
	{
		printf("Position exceeds than list length\n");
		return head;
	}
	p->next=temp->next;
	temp->next=p;
	return head;
}
Node* delete_begin(Node* head)
{
	Node* temp=head;
	head=temp->next;
	free(temp);
	return head;
}
Node* delete_end(Node* head)
{
	Node* temp=head;
	while(temp->next->next!=NULL)
		temp=temp->next;
	Node* p=temp->next->next;
	temp->next=NULL;
	free(p);	
	return head;
}
Node* delete_pos(Node* head,int pos)
{
	if(pos==1)
	{
		head=delete_begin(head);
		return head;
	}
	Node* temp=head;
	int i=1;
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	Node* p=temp->next;
	temp->next=p->next;
	free(p);
	return head;
}
Node* reverse(Node* head)
{
	Node *prev,*forw,*temp;
	temp=head;
	prev=NULL;
	while(temp!=NULL)
	{
		forw=temp->next;
		temp->next=prev;
		prev=temp;
		temp=forw;
	}
	head=prev;
	return head;
}
void main()
{
	int data,n,i;
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter data : ");
		scanf("%d",&data);
		if(i==1)
		{
			head=insert_begin(head,data);
		}
		else
		{
			head=insert_end(head,data);
		}
	}
	//head=insert_begin(head,100);
//	head=insert_end(head,200);
	//head=insert_pos(head,500,3);
//	head=delete_begin(head);
	//head=delete_end(head);
	//head=delete_pos(head,3);
	head=reverse(head);
	display(head);
}
