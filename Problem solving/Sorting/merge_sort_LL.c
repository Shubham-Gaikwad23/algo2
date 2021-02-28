#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode
{
	int key;
	struct LinkedListNode *next;
}Node;

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

void merge(int a[], int low, int mid, int high)
{
	int *left, *right, len1, len2, i, j, k;
	len1 = mid-low+1;
	len2 = high-mid;
	left = malloc(sizeof(int) * (len1+1));
	right = malloc(sizeof(int) * (len2+1));
	left[len1] = -pow(2, sizeof(int)*8 - 1); // INT_MIN
	right[len2] = -pow(2, sizeof(int)*8 - 1);

	for(i=0, j=low; j<=mid; i++, j++)
		left[i] = a[low];
	for(i=0, j=mid+1; j<=high; i++, j++)
		right[i] = a[j];

	i=j=0;
	for(k=low; i<len1+1 && j<len2+1; k++)
	{
		if(left[i] < right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;	
		}
	}
	while(i<len1)
	{
		a[k] = left[i];
		i++;
		k++;
	}
	while(j<len2)
	{
		a[k] = right[j];
		j++;
		k++;
	}
}

void merge_sort(int a[], int low, int high)
{
	if low==high:
		return;
	else
	{
		int mid = (low+high)/2;
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}

int main()
{
	Node *head, *cursor;
	int a[] = {60, 51, 29,5,49,50,12,56,24,29}, i;

	head = append(NULL, 60);
	append(head, 51);
	append(head, 29);
	append(head, 5);
	append(head, 49);
	append(head, 50);
	append(head, 12);
	append(head, 56);
	append(head, 24);
	append(head, 29);
	
	/*for(cursor=head; cursor; cursor=cursor->next)
		printf("%d ", cursor->key);
	printf("\n\n\n");*/
	
	merge_sort(a, 0, 9);
	for(i=0;i<10;i++)
		printf("%d ", a[i]);



	/*for(cursor=head; cursor; cursor=cursor->next)
		printf("%d ", cursor->key);
	printf("\n\n\n");*/

	return 0;
}