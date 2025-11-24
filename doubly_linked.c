#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *prev;
	struct node *next;
}*head=NULL;
typedef struct node Node;
Node* create(int data)
{
	Node* new=malloc(sizeof(Node));
	new->info=data;
	new->prev=NULL;
	new->next=NULL;
	return new;
}
void display(Node* head)
{
	Node* temp=head;
	printf("NULL -> ");
	while(temp!=NULL)
	{
		printf("%d -> ",temp->info);
		temp=temp->next;
	}
	printf("NULL\n");
}
Node* insert_begin(Node* head,int data)
{
	Node* new=create(data);
	if(head==NULL)
	{
		head=new;
		return head;
	}
	head->prev=new;
	new->next=head;
	head=new;
	return head;
}
Node* insert_end(Node* head,int data)
{
	Node* new=create(data);
	Node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new;
	new->prev=temp;
	return head;
}
Node* delete_begin(Node* head)
{
	Node* temp=head;
	head=temp->next;
	head->prev=NULL;
	free(temp);
	return head;
}
Node* delete_end(Node* head)
{
	Node* temp=head;
	while(temp->next->next!=NULL)
		temp=temp->next;
	temp->next=NULL;
	return head;
}
Node* insert_pos(Node* head,int data,int pos)
{
	if(pos==1)
	{
		head=insert_begin(head,data);
		return head;
	}
	int i;
	Node* temp=head;
	Node* new=create(data);
	for(i=1;i<pos-1;i++)
		temp=temp->next;
	new->next=temp->next;
	temp->next->prev=new;
	new->prev=temp;
	temp->next=new;
	return head;
}
Node* delete_pos(Node* head,int pos)
{
	Node* temp=head;
	if(pos==1)
	{
		head=delete_begin(head);
		return head;
	}
	int i;
	for(i=1;i<pos-1;i++)
		temp=temp->next;
	Node* p=temp->next;
	p->next->prev=temp;
	temp->next=p->next;
	free(p);
	return head;
}
void rev(Node* head)
{
	Node* temp=head;
	while(head->next!=NULL)
		head=head->next;
	printf("NULL -> ");
	while(head!=NULL)
	{
		printf("%d -> ",head->info);
		head=head->prev;
	}
	printf("NULL\n");
}
void main()
{
	head=insert_begin(head,10);
	head=insert_end(head,20);
	head=insert_end(head,30);
	head=insert_begin(head,5);
	display(head);
	head=insert_pos(head,100,3);
	display(head);
	rev(head);
	//head=delete_begin(head);
	//display(head);
//	head=delete_end(head);
//	display(head);
	head=delete_pos(head,3);
	display(head);
	rev(head);
}



