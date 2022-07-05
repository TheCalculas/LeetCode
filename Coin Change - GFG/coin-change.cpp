// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  long long int dp[1001][1001];
  
  long long int helper(int s[], int i, int sum)
  {
      if(sum==0) return dp[i][sum] = 1;
      if(i<=0) return dp[i][sum] =  0;
      if(dp[i][sum]!=-1) return dp[i][sum];
      if(s[i-1]<=sum) return dp[i][sum] = helper(s, i, sum-s[i-1])+helper(s, i-1, sum);
      else
        return dp[i][sum] = helper(s, i-1, sum);
    return dp[i][sum];
  }
    long long int count(int S[], int m, int n) {
        // m is the size of the array 
        memset(dp, -1, sizeof(dp));
        // code here.
        return helper(S, m, n);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends