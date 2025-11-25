#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *left;
	struct node* right;
};
typedef struct node Node;
Node* create(int data)
{
	Node* new=malloc(sizeof(Node));
	new->info=data;
	new->left=new->right=NULL;
	return new;
}


Node* insert(Node* root,int data)
{
	if(root==NULL)
		return create(data);
	if(data<root->info)
		root->left=insert(root->left,data);
	else if(data>root->info)
		root->right=insert(root->right,data);
	return root;
}

Node* minimum(Node* root)
{
	while(root && root->left)
		root=root->left;
	return root;
}
Node* Maximum(Node* root)
{
	while(root && root->right)
		root=root->right;
	return root;
}
Node* delete(Node* root,int data)
{
	if(root==NULL)
		return NULL;
	if(data<root->info)
		root->left=delete(root->left,data);
	else if(data>root->info)
		root->right=delete(root->right,data);
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->left==NULL)
		{
			Node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			Node* temp=root->left;
			free(root);
			return temp;
		}
		else
		{
			Node* succ=minimum(root->right);
			root->info=succ->info;
			root->right=delete(root->right,succ->info);
		}
	}
	return root;
}

Node* search(Node* root,int key)
{
	if(root==NULL ||root->info==key)
		return root;
	if(key<root->info)
		return search(root->left,key);
	return search(root->right,key);
}


void inorder(Node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->info);
	inorder(root->right);
}
void preorder(Node* root)
{
	if(root==NULL)
		return;
	printf("%d ",root->info);
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->info);
}
void main()
{
	Node* root=NULL;
	int i,n,arr[]={100,20,90,10,80,30,60,40,450};
	n=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<n;i++)
	{
		root=insert(root,arr[i]);
	}
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	Node* min = minimum(root);
	printf("%d",min->info);
	printf("\n");
	Node* Max=Maximum(root);
	printf("%d",Max->info);
	printf("\n");
	Node* found=search(root,80);
	printf("%d",found->info);
	printf("\n");
	root=insert(root,200);
	inorder(root);
	printf("\n");
	root=delete(root,40);
	inorder(root);
	printf("\n");

}
