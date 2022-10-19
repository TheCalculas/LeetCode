class Solution {
public:
    int f(int n, vector<int> &dp)
    {
        if(n==1) return dp[n] = 1;
        if(n==2) return dp[n] = 2;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = (f(n-1, dp)+f(n-2, dp));
    }
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};