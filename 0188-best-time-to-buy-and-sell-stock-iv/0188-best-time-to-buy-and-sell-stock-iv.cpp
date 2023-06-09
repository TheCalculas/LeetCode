class Solution {
public:
    int f(vector<int>&p, int idx, int buy, int tran, vector<vector<vector<int>>>&dp)
    {
        if(idx==p.size()){
            return 0;
        }
        if(tran==0)
        {
            return 0;
        }
        if(dp[idx][buy][tran]!=-1) return dp[idx][buy][tran];
        if(buy)
        {
            // sell it
            int sell = max(p[idx]+f(p, idx+1, 0, tran-1, dp), f(p, idx+1, 1, tran, dp));
            return dp[idx][buy][tran] = sell;
        }
        
        int bb = max(-p[idx]+f(p, idx+1, 1, tran, dp), f(p, idx+1, 0, tran, dp));
        return dp[idx][buy][tran] = bb;
        
        
        
    }
    
    int maxProfit(int k , vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, 
                vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(prices, 0, 0, k, dp);
    }
};