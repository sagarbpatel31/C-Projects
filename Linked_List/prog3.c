// Creating a Linked List which has 3 elements using malloc and freeing the memory
// Made by Sagar B Patel

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int x;
	struct Node *next;
}Node;

int main(int argc,char *argv[])
{
	Node root;
	root.x=15;
	root.next=malloc(sizeof(Node));
	root.next->x=-2;
	root.next->next=malloc(sizeof(Node));
	root.next->next->x = 22;
	root.next->next->next=NULL;

	for(Node *curr=&root; curr!=NULL; curr=curr->next)
	{
		printf("Number: %d\n",curr->x);
	}
	printf("Successfully created a linked list....\n");
	free(root.next->next);
	free(root.next);
	return 0;
}
