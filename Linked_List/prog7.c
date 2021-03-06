// Adding the element at the beginning of the Linked List
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

	insert_beginning(&root,13);
	insert_beginning(&root,-4);
	insert_beginning(&root,44);
	for(Node *curr=root; curr!=NULL; curr=curr->next)
	{
		printf("Number: %d\n",curr->x);
	}
	printf("Successfully created a linked list....\n");
	deallocate(&root);
	return 0;
}
