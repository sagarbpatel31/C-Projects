// Check if there is a cycle in the Linked List
// Made by Sagar B Patel
	
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int x;
	struct Node *next;
}Node;

void insert_end(Node **root,int value)
{
	Node *new = malloc(sizeof(Node));
	if(new ==NULL)
	{
		exit(1);
	}
	new->next=NULL;
	new->x=value;	
	if(*root==NULL)
	{
		*root=new;
		exit(2);	
	}
	Node *curr=*root;
	for(curr=*root;curr->next!=NULL;curr=curr->next);
	curr->next=new;
}
void insert_beginning(Node **root,int value)
{
	Node *new=malloc(sizeof(Node));
	if(new==NULL)
	{
		exit(3);
	}
	new->x=value;
	new->next=*root;

	*root=new;
}

void insert_after(Node *node,int value)
{
	Node *new = malloc(sizeof(Node));	
	if(new==NULL)
	{
		exit(4);
	}
	new->x = value;
	new->next=node->next;
	node->next=new;		
}

void insert_sorted(Node **root,int value)
{
	if (*root==NULL || (*root)->x >= value)
	{
		insert_beginning(root,value);
		return;
	}
	Node *curr = *root;
	while(curr->next!=NULL)
	{
		if(curr->next->x >= value)
		{
			break;
		}
		curr=curr->next;
	}
	insert_after(curr,value);
}

void remove_element(Node **root,int value)
{
	if(*root==NULL)
	{
		return;
	}
	if((*root)->x ==value)
	{
		Node *to_remove = *root;
		*root=(*root)->next;
		free(to_remove);
		return;
	}
	for(Node *curr=*root; curr->next!=NULL;curr=curr->next)
	{
		if(curr->next->x==value)
		{
			Node *to_remove = curr->next;
			curr->next=curr->next->next;
			free(to_remove);
			return;
		}	
	}
}

void reverse(Node **root)
{
	Node *prev = NULL;
	Node *curr = *root;
	
	while(curr!=NULL)
	{	
		Node *next = curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}	
	*root=prev;
}	

int has_loops(Node *root)
{
	Node *slow = root;
	Node *fast = root;
	while(slow!=NULL && fast !=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			return 1;
		}
	}
	return 0;
}

void deallocate(Node **root)
{
	Node *curr=*root;
	while(curr!=NULL)
	{
		Node *aux = curr;
		curr=curr->next;
		free(aux);
	}	
	*root=NULL;
}

int main(int argc,char *argv[])
{
	Node *root=NULL;

	insert_sorted(&root,1);
	insert_sorted(&root,1);
	insert_sorted(&root,3);
	insert_sorted(&root,6);		
	insert_sorted(&root,7);		
	
	root->next->next->next->next->next=root->next;

	if (has_loops(root)==1)
	{
		printf("Linked list has a loop....\n");
		return 1;
	}
	for(Node *curr=root; curr!=NULL; curr=curr->next)
	{
		printf("Number: %d\n",curr->x);
	}
	printf("Successfully created a linked list....\n");
	deallocate(&root);
	return 0;
}
