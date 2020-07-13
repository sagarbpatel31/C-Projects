// Complete resolution of Adding the element in the Linked List
// Made by Sagar B Patell

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
		return;	
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
	insert_end(&root,4);
	insert_end(&root,2);
	insert_end(&root,-5);
	insert_after(root,7);
	insert_after(root->next->next->next,88);
	
	for(Node *curr=root; curr!=NULL; curr=curr->next)
	{
		printf("Number: %d\n",curr->x);
	}
	printf("Successfully created a linked list....\n");
	deallocate(&root);
	return 0;
}
