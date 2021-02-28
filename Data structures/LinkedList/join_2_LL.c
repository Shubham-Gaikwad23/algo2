#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode
{
	int key;
	struct LinkedListNode *next;
}Node;

Node* merge(Node*, Node*);

Node* append(Node *head, int key)
{
	Node *tmp = malloc(sizeof(Node));
	tmp->key = key;
	tmp->next = NULL;

	if (head)
	{
		for(; head->next ; head=head->next);
		head->next = tmp;
	}
	return tmp;
}

void join(Node *l1, Node *l2)
{
	for(; l1->next ; l1=l1->next);
	l1->next = l2;
}

void merge_sort_aux(Node *list[], int low, int high)
{
    int i;
	if (low==high)
		return;
	else
	{
		int mid = (low+high)/2;
		merge_sort_aux(list, low, mid);
		for(i=low; i<=mid; i++)
		    printf("%d %d ",list[i]->key, i);
	    printf("\n");
		    
		merge_sort_aux(list, mid+1, high);
		for(i=mid+1; i<=high; i++)
		    printf("%d %d ",list[i]->key, i);
		printf("\n");
		    
		list[low] = merge(list[low], list[mid+1]);
		for(i=low; i<=high; i++)
		    printf("%d %d ",list[i]->key, i);
		printf("\n");
	}
}

void merge_sort(Node *head)
{
	int len, i;
	Node *cursor;
	Node **list;

	for(len=0, cursor=head; cursor; cursor=cursor->next, len++);
	list = malloc(sizeof(Node*) * len);

	for(i=0, cursor=head; cursor; cursor=cursor->next, list[i]->next=NULL, i++)
	{
		list[i] = cursor;
	}

	merge_sort_aux(list, 0, len-1);
}

Node* merge(Node *l1, Node *l2)
{
	Node *new = malloc(sizeof(Node));
	Node *head, *dummy;
	head=dummy=new;
	new->next = NULL;

	while (l1 && l2)
	{
		if (l1->key < l2->key)
		{
			new->next = l1;
			l1 = l1->next;
		}
		else
		{
			new->next = l2;
			l2 = l2->next;
		}
		new = new->next;
	}
	if(l1)
		new->next = l1;
	if(l2)
		new->next = l2;

	head = head->next;
	free(dummy);
	return head;
}

int main()
{
	Node *l1, *l2, *x, *y;

	l1 = append(NULL, 60);
	append(l1, 51);
	append(l1, 29);
	
	l2 = append(NULL, 5);
	append(l2, 49);
	append(l2, 50);
	join(l1, l2);
	append(l1, 12);
	append(l1, 56);
	append(l1, 24);
	append(l1, 29);
	
	for(x=l1; x; x=x->next)
		printf("%d ", x->key);
	printf("\n\n\n");
	
	merge_sort(l1);

	/*for(x=l1; x; x=x->next)
		printf("%d ", x->key);*/

	return 0;
}