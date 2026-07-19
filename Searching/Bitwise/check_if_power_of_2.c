// https://practice.geeksforgeeks.org/problems/power-of-2/0
// Time Complexity: O(1)

#include <stdio.h>
#include <math.h>

int main() {
	int t;
	unsigned long n;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%lu",&n);
	    if(n==0)
	        printf("NO");
	    else
	    {
	        unsigned long bit;
	        int i, size = sizeof(long) * 8, count;
	        for(i=0, bit=1, count=0 ;i<size; i++, bit=bit*2LU)
	        {
	            unsigned long is_on;
	            is_on = n & bit;
	            if(is_on)
	                count++;
	        }
	        if(count==1)
	            printf("YES\n");
	        else
	            printf("NO\n");
	    }
	}
	return 0;
}
