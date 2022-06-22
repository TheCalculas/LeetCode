class Solution
{
    public:
        int minInsertions(string A)
        {
            int n = A.length();
            int dp[n + 1][n + 1];
            string a = A;
            string b = A;
            reverse(b.begin(), b.end());
            memset(dp, -1, sizeof(dp));
            for (int i = 0; i < n + 1; i++)
                for (int j = 0; j < n + 1; j++)
                {
                    if (i == 0 || j == 0) dp[i][j] = 0;
                }
           	// now we write some code
            for (int i = 1; i <= n; i++)
                for (int j = 1; j < n + 1; j++)
                {
                    if (dp[i][j] != -1) continue;
                    if (a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }

            return n - dp[n][n];
        }
};