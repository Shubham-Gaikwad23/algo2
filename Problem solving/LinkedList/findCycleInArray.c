#include <stdio.h>
#include <stdlib.h>

/*	Input: n+1 numbers from the range [1,n]. By pigenhole principle, there must be repeatation. Only one number is repeated any number of times. Eg n=5 [1 2 3 2 4 5]  [2 2 2 2 2 2]; Invalid input is [ 1 1 2 2 3 3]                        
 *	Output: First occuring duplicate number from index 0;
 *	Constraints: Space complexity- O(1) Time complexity O(n), Cannot modify input array.
*/	


void floydCycleDetect(int a[])
{
	int i, j, x;
	i=j=0;
	do
	{
		i = a[i];
		j = a[a[j]];
	}
	while(i!=j);
	
	i=0;
	while(i!=j)
	{
		x=i;
		i=a[i];
		j=a[j];
	}
	printf("First duplicate found at index %d\n",x);
}

int main()
{
	int n, *a, i;
	printf("Enter value of n : ");
	scanf("%d",&n);
	a = (int *) malloc( sizeof(int) * (n+1) );
	for(i=0;i<=n;i++)
		scanf("%d",a+i);
	floydCycleDetect(a);
	return 0;
}
