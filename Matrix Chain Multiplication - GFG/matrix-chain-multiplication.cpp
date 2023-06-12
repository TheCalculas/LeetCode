//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int arr[], int i, int j, vector<vector<int>> &dp)
    {
        if(i==j) return 0;// as we have nothing to partition and multiply
        if(dp[i][j]!=-1) return dp[i][j];
        int mn = INT_MAX;
        for(int k = i; k<=j-1; k++)
        {
            int sum = arr[i-1] * arr[k] * arr[j] + 
            f(arr, i, k, dp) + f(arr, k+1, j, dp);
            if(sum<mn) mn = sum;
        }
        return dp[i][j] = mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        // return f(arr, 1, N-1, dp);
        
        // tabulation 
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for(int i = N-1; i>=1; i--)
        {
            for(int j = i+1; j<N; j++)
            {
                int mn = INT_MAX;
                for(int k = i; k<=j-1; k++)
                {
                    int sum = arr[i-1] * arr[k] * arr[j] + 
                    dp[i][k] + dp[k+1][j];
                    if(sum<mn) mn = sum;
                }
                dp[i][j] = mn;
            }
        }
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends