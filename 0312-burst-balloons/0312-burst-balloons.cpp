class Solution {
public:
    int f(int i, int j, vector<int>&v, vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mx = INT_MIN;
        for(int k = i; k<=j; k++)
        {
            int sum = v[i-1]*v[k]*v[j+1] 
                +f(i, k-1, v, dp) + f(k+1, j, v, dp);
            mx = max(mx, sum);
        }
        return dp[i][j] = mx;
    }
    int maxCoins(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+2, vector<int> (n+2, -1));
        v.push_back(1);
        v.insert(v.begin(), 1);
        return f(1, v.size()-2, v, dp);
    }
};