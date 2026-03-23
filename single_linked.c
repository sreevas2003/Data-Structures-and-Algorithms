#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*head=NULL;
typedef struct node Node;
Node* create(int data)
{
    Node* temp=malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void display(Node* head)
{
    Node* temp=head;
    while(temp)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
Node* insert_begin(Node* head, int data)
{
    Node* temp=create(data);
    temp->next=head;
    head=temp;
    return head;
}
Node* insert_pos(Node* head,int data,int pos)
{
    if(pos==1)
    {
        head=insert_begin(head,data);
        return head;
    }
    Node* temp=create(data);
    Node* p=head;
    while(pos-2 && p)
    {
        p=p->next;
        pos--;
    }
    temp->next=p->next;
    p->next=temp;
    return head;
}
Node* insert_end(Node* head,int data)
{
    Node* temp=create(data);
    Node* p=head;
    while(p->next)
        p=p->next;
    p->next=temp;
    return head;
}
Node* delete_begin(Node* head)
{
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}
Node* delete_end(Node* head)
{
    Node* temp=head;
    while(temp->next->next)
        temp=temp->next;
    free(temp->next);
    temp->next=NULL;
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
    while(pos-2 && temp)
    {
        temp=temp->next;
        pos--;
    }
    Node* p=temp->next;
    temp->next=p->next;
    free(p);
    return head;
}
void search(Node* head, int tar)
{
    Node* temp=head;
    int c=0;
    while(temp)
    {
        c++;
        if(temp->data==tar)
        {
            printf("Element found at position %d\n",c);
            return;
        }
        temp=temp->next;
    }
    printf("Element Not found\n");
}
Node* reverse(Node* head)
{
    Node* temp=head;
    Node* prev=NULL;
    Node* next=head;
    while(temp)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}
int middle(Node* head)
{
    Node *slow=head,*fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
void loop(Node* head)
{
    Node *slow=head,*fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            printf("Loop is detected\n");
            return;
        }
    }
    printf("Loop is Not detected\n");
}
void loop_remove(Node* head)
{
    Node *slow=head,*fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            printf("Loop is detected\n");
            slow=head;
            if(slow==fast)
            {
                while(slow != fast->next)
                    fast=fast->next;
            }
            else
            {
                while(slow->next != fast->next)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
            }
            fast->next=NULL;
            return;
        }
    }
    printf("Loop is Not detected\n");
}
void main()
{
    head=create(10);
    head->next=create(20);
    head=insert_begin(head,30);
    head=insert_end(head,40);
    head=insert_pos(head,50,3);
    // head=delete_begin(head);
    // head=delete_end(head);
    // head=delete_pos(head,3);
    search(head,60);
    display(head);
    printf("middele element is %d\n",middle(head));
    loop(head);
    // head=reverse(head);
    // display(head);
}
