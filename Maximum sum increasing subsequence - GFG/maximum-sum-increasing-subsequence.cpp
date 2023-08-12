//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
    int f(int v[], int idx, int prev, vector<vector<int>> &dp, int n)
    {
        if(idx==n) return 0;
        // take and not take
        if(dp[prev+1][idx]!=-1) return dp[prev+1][idx];
        int take = 0, notTake = 0;
        if(prev==-1||v[idx]>v[prev])
        {
            // increasing 
            take  = f(v, idx+1, idx, dp, n) + v[idx];
        }
        
        notTake = f(v, idx+1, prev, dp, n) + 0;
        return dp[prev+1][idx] = max(take, notTake);
        
    }
 
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(arr, 0, -1, dp, n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends