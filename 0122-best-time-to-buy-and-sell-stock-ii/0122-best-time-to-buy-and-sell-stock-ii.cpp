class Solution {
public:
    int f(int idx, int buy, vector<int>& v, vector<vector<int>> &dp)
    {
        if(idx==v.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        
        // take and not take
        if(buy)
        {
            // if it was already bought
            return dp[idx][buy]= max(v[idx] + f(idx+1, 0,  v, dp), 0 + f(idx+1, 1,  v, dp));
        }
        else{
            // if it wasn't bought 
            return dp[idx][buy] = max(-v[idx] + f(idx+1, 1,  v, dp), 0 + f(idx+1, 0,  v, dp));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(0, 0, prices, dp);
    }
};