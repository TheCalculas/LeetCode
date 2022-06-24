class Solution {
public:
    int helper(string &s,string &t,vector<vector<int>> &dp,int i,int j){
        if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<j) return dp[i][j] = 0;
        dp[i][j] = 0;
        if(s[i-1]==t[j-1]) dp[i][j] = helper(s,t,dp,i-1,j-1);
        return dp[i][j] += helper(s,t,dp,i-1,j);

    }
    
    int numDistinct(string s, string t) {
        int n = s.size(),m = t.size();   
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(s,t,dp,n,m);
    }
};