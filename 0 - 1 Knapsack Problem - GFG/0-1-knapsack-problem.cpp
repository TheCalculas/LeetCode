//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int idx, int w, int wt[], int v[], int n, vector<vector<int>>& dp)
    {
        // now we hve to do the stuffs heh
        if(idx==n)
            return 0; // as nothing to occupy
        
        int take = 0, notTake = 0;
        if(dp[idx][w]!=-1) return dp[idx][w];
        if(w>=wt[idx])
        {
            // we can take it :)
            take = v[idx] + f(idx+1, w-wt[idx], wt, v, n, dp);
        }
        
        notTake = 0 + f(idx+1, w,wt,  v, n, dp);
        
        return dp[idx][w] = max(take, notTake);
        
    }
    
    int knapSack(int w, int wt[], int v[], int n) 
    { 
       vector<vector<int>> dp(n, vector<int>(w+1, -1));
       return f(0, w, wt, v, n, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends