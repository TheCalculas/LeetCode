//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int
//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    ll f(int arr[], int n, int i, int j, vector<vector<int>>& dp)
    {
        if(j<i) return 0;
        if(i==j) return arr[i];
        if(dp[i][j]!=-1) return dp[i][j];
        ll l = arr[i] + min(f(arr, n, i+2, j, dp), f(arr, n, i+1, j-1, dp));
        ll r = arr[j] + min(f(arr, n, i, j-2, dp), f(arr, n, i+1, j-1, dp));
        
        return dp[i][j] = max(l, r);
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(arr, n, 0, n-1, dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends