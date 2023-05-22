class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),INT_MAX);
        for(int i = cost.size()-1; i>=0; i--)
        {
            dp[i] = cost[i];
            if(i<cost.size()-2) dp[i] += min(dp[i+1], dp[i+2]);
            
        }
        return min(dp[0], dp[1]);
    }
};