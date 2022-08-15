class Solution {
public:
    int f(vector<int> &v, int idx, bool buy, vector<vector<vector<int>>> &dp, int limit)
    {        
        if(limit==0) return 0;
        if(idx>=v.size()) return 0;
        if(dp[idx][buy][limit]!=-1) return dp[idx][buy][limit];
        else {
            // khareedna hai 
            int bstock = INT_MIN;
            int sstock = INT_MIN;
            if(buy==false)
            {
                bstock = max(-v[idx] + f(v, idx+1, true, dp, limit),
                            0 + f(v, idx+1, false, dp, limit));
            }
            else {
                
                // sell karna hai mereko 
                sstock = max(+v[idx]+f(v, idx+1, false, dp, limit-1)
                            ,0 + f(v, idx+1, buy, dp, limit));
            }
            return dp[idx][buy][limit] = max(bstock, sstock);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(prices, 0, false, dp, k);
    }
};