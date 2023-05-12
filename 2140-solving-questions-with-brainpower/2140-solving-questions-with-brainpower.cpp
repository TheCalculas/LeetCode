#define ll long long 

class Solution {
public:
    ll f(vector<vector<int>>& q, int idx, vector<ll>& dp)
    {
        if(idx>=q.size()) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        // take and not take
        // take 
        ll a = q[idx][0] + f(q, idx+q[idx][1]+1, dp);
        ll b = f(q, idx+1, dp);
        return dp[idx] = max(a, b);
    }
    long long mostPoints(vector<vector<int>>& q) {
        int idx = 0;
        vector<ll> dp(q.size()+1, -1);
        return f(q, idx, dp);
    }
};