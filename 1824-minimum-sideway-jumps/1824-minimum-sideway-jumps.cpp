class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        // ye hoga apna jump array ;_
        int dp[3] = {1,0,1};
        // if obstacle turn that into intmax
        for(auto x:obstacles)
        {
            if(x>0)
            {
                dp[x-1] = 1e6;
            }
            for(int i=0; i<3; i++)
            {
                if(x!=i+1)
                {
                    dp[i] = min(dp[i], min(dp[(i+1)%3],dp[(i+2)%3])+1);
                }
            }
            
        }
        return min(dp[0], min(dp[1], dp[2]));
    }
};