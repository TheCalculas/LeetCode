//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// find the maximum palindromic substring

int f(string s, string r, int i, int j, vector<vector<int>> &dp)
{
    if(i==s.size()||j==r.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==r[j]) return dp[i][j] = 1 + f(s, r, i+1, j+1, dp);
    
    else{
        return dp[i][j] = 0 + max(f(s, r, i+1, j, dp), f(s, r, i, j+1, dp));
    }
}

class Solution{
  public:
    int countMin(string s){
        string r = s;
        reverse(r.begin(), r.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int a = f(s, r, 0, 0, dp);
        
        return s.size() - a;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends