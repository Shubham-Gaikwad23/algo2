// https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1

#include <bits/stdc++.h>
using namespace std;


//User function template for C++
class Solution{
public:

	vector<int> valueEqualToIndex(int arr[], int n) {
	    // code here
	    vector<int> vec{};
	    for(int i=0;i<n; i++)
	    {
	        if(arr[i]==i+1)
	            vec.push_back(i+1);
	    }
	    return vec;
	}
};
