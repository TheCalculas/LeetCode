class Solution {
public:

    int fib(int n) {
        int dp[n+1];
        if(n==0) return 0;
        if(n==1) return 1;
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        cout<<dp[0]<<" "<<dp[1]<<endl;
        for(int i=2; i<n+1; i++)
        {
            
            dp[i] = dp[i-1]+dp[i-2];
            cout<<"i is : "<<i<<" and dp is "<<dp[i]<<endl;
        }
        return dp[n];
    }
};