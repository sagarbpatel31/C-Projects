// Creating a Linked List using only one Node named root
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
	root.next->next=NULL;

	printf("First: %d\n",root.x);
	printf("Second: %d\n",root.next->x);

	printf("Successfully created a linked list....\n");
	return 0;
	free(root.next);
}
