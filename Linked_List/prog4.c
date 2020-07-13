// Inserting the element at the end of the Linked List 
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
	Node *curr;
	for(curr=*root;curr->next!=NULL;curr=curr->next);
	curr->next=new;
}
int main(int argc,char *argv[])
{
	Node *root = malloc(sizeof(Node));
	if(root==NULL)
	{
		exit(2);
	}
	root->x=15;
	root->next=NULL;
		
	insert_end(&root,10);
	insert_end(&root,-12);		
	for(Node *curr=root; curr!=NULL; curr=curr->next)
	{
		printf("Number: %d\n",curr->x);
	}
	printf("Successfully created a linked list....\n");
	return 0;
}
