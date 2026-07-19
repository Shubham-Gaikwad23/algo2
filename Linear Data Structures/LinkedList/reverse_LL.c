#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
}Node;
Node *head;

int main()
{
	int n, i;
	Node *cur, *prev=NULL, *next;
	printf("Total nodes : ");
	scanf("%d",&n);
	printf("Enter %d nodes : ",n);
	for(i=0; i<n; i++)
	{
		cur = (Node*)malloc(sizeof(Node));
		scanf("%d",&cur->data);
		if(prev!=NULL)
			prev->next = cur;
		else
			head = cur;
		prev = cur;
	}
	cur->next=NULL;

	prev = NULL;
	cur = head;
	next = cur->next;
	
	while(cur!=NULL)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		if(next!=NULL)
			next = next->next;
	}
	head = prev;
	for(cur=head;cur!=NULL;cur=cur->next)
		printf("%d ", cur->data);
	return 0;
}
