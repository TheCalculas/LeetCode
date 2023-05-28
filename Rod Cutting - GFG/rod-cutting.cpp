//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int f(int idx, int price[], int length, vector<vector<int>>&dp)
    {
        if(idx==0)
        {
            return length * price[0];
        }
        if( dp[idx][length] != -1) return  dp[idx][length];
        
        int notTake = 0 + f(idx-1, price, length, dp);
        int take = INT_MIN;
        int len = idx+1;
        if(len<=length)
        {
            take = price[idx] + f(idx, price, length - len, dp);
        }
        return dp[idx][length] = max(take, notTake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return f(n-1, price, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends