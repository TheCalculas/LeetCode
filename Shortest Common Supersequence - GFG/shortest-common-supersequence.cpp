//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int f(int x, int y, string a, string b, vector<vector<int>>& dp)
    {
        if(x==0||y==0) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        if(a[x-1]==b[y-1]) return dp[x][y] =  1 + f(x-1, y-1, a, b, dp);
        else{
            return dp[x][y] = max(f(x, y-1, a, b, dp),f(x-1, y, a, b, dp));
        }
    }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code 
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int a = f(m, n, X, Y,  dp);
        int total = m + n - a;
        return total;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends