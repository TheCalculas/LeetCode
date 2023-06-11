class Solution {
public:

    int f(int idx, int amt, vector<int> &v, vector<vector<int>>& dp)
    {
        if(amt==0) return 1;
        if(idx==v.size()) {
            return 0;
        }
        
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        
        
        // not take
        int notTake = f(idx+1, amt, v, dp);
        
        int take = 0;
        
        if(amt>=v[idx])
        {
            take = f(idx, amt-v[idx], v, dp);
        }
        
        return dp[idx][amt] = take+notTake;
        
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return f(0, amount, coins, dp);
    }
};