class Solution {
public:
    int f(vector<int>&p, int fee, int idx, int buy, vector<vector<int>>&dp)
    {
        if(idx>=p.size())
        {
            return 0;
        }
        
        // take 
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int b = 0, s = 0;
        int notSell = f(p, fee, idx+1, buy, dp);
        b = notSell;
        s = notSell;
        if(buy==1)
        {
            // if already bought 
            int sell = f(p, fee, idx+1, 0, dp) + p[idx]- fee;
            
            b = max(sell, b);
        }
        else{
            int bu = f(p, fee, idx+1, 1, dp) - p[idx];
            
            s = max(bu, s);
        }
        
        return dp[idx][buy] = max(b, s);
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(prices, fee, 0, 0, dp);
    }
};