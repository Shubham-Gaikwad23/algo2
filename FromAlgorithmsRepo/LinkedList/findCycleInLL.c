#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
}Node;
Node *head, *tail;
int n;

void createLL()
{
	int i;
	Node *cur, *prev;
	printf("Total nodes : ");
	scanf("%d",&n);
	printf("Enter %d nodes : ",n);
	for(i=0, prev=NULL; i<n; i++)
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
	tail=cur;
}

void createCycle()
{
	int x;
	Node *i;
	printf("Enter the cycle starting node : ");
	scanf("%d",&x);
	for(i=head; i->data!=x; i=i->next);
	tail->next = i;
}

void findCycle()
{
	Node *slow, *fast;
	slow=fast=head;
	do
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	while(slow!=fast);
	slow=head;
	while(slow!=fast)
	{
		slow=slow->next;
		fast=fast->next;
	}
	printf("Start of cycle is at node %d",slow->data);
}

int main()
{
	createLL();
	createCycle();
	findCycle();
	return 0;
}
