class Solution {
public:
    // recursion 
    int f(vector<int> &prices, int idx, bool buy, vector<vector<int>> &v)
    {
        if(idx == prices.size()) return 0;
        // if you are not bought any stock
        if(v[idx][buy]!=-1) return v[idx][buy];
        if(buy == false)
        {
            return v[idx][buy] = max(f(prices, idx+1, 1,v)-prices[idx], f(prices, idx+1, 0,v));   
        }
        else{
            return v[idx][buy] = max(prices[idx], f(prices, idx+1, 1, v));
        }
    }
    // dp 
    
    int maxProfit(vector<int>& prices) {
        
        // changing are idx and buy
        vector<vector<int>> v(prices.size()+1, {-1, -1});
        
        
        bool buy = false;
        int idx = 0;
        return f(prices, idx, buy, v);
    }
};