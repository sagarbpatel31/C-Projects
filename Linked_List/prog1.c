// Creating a first Linked List named Node
// Made by Sagar B Patel


#include <stdio.h>

typedef struct Node{
	int x;
	struct Node *next;
}Node;

int main(int argc,char *argv[])
{
	Node root,elem2;
	root.x=15;
	root.next=&elem2;
	elem2.x= -2;
	elem2.next=NULL;
	printf("First: %d\n",root.x);
	printf("Second: %d\n",elem2.x);

	printf("Successfully created a linked list....\n");
	return 0;
}
