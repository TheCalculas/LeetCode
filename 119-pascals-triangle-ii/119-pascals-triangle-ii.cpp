class Solution {
public:
    int dp[100][100];
    vector<int> getRow(int rowIndex) {
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        dp[2][1] = 1;
        dp[2][2] = 1;
        for(int i=3; i<=rowIndex+1; i++)
        {
            for(int j=1; j<=i; j++)
            {
                
                if(j==1) dp[i][j] = dp[i-1][j];
                else if(j==i) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
        vector<int> v;
        for(int i=1; i<=rowIndex+1; i++)
            v.push_back(dp[rowIndex+1][i]);
        return v;
    }
};