class Solution
{
    public:
        int minFallingPathSum(vector<vector < int>> &matrix)
        {
            int n = matrix.size();
            int m = matrix[0].size();

            int dp[n][m];

            int mn = INT_MAX;
            for (int i = 0; i < m; i++)
            {
                dp[0][i] = matrix[0][i];

                if (mn > dp[0][i])
                {
                    mn = dp[0][i];
                }
            }

            for (int i = 1; i < n; i++)
            {
                mn = INT_MAX;

                for (int j = 0; j < m; j++)
                {
                    if (j == 0)
                    {
                        dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
                    }
                    else if (j == m - 1)
                    {
                        dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
                    }
                    else
                    {
                        dp[i][j] = matrix[i][j] + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1]));
                    }

                    if (mn > dp[i][j])
                    {
                        mn = dp[i][j];
                    }
                }
            }

            return mn;
        }
};