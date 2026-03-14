// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

#include <iostream>
using namespace std;



int main() {
    int t;
    
    scanf("%d",&t);
    while(t--)
    {
        int n, m;
        scanf("%d%d",&n, &m);
        int p[n], w[n], v[n+1][m+1];
        
        for(int i=0;i<n;i++)        // get profit and weights
            scanf("%d", &p[i]);
        for(int i=0;i<n;i++)
            scanf("%d", &w[i]);
            
        for(int i=0;i<m+1;i++)
            v[0][i] = 0;             // init first row to 0
            
        
        for(int i=1;i<n+1; i++)
        {
            for(int j=0; j<m+1; j++)
            {
                if (j-w[i-1] < 0)
                    v[i][j] = v[i-1][j];
                else                        //v[i][j] = max( v[i-1][j], v[i-1][j - w[i-1]] + p[i-1] )
                {
                    int x, y;
                    x = v[i-1][j];
                    y = v[i-1][j - w[i-1]] + p[i-1];
                    if (x<y)
                        v[i][j] = y;
                    else
                        v[i][j] = x;
                }
            }
        }
        printf("%d\n", v[n][m]);
    }
	return 0;
}
