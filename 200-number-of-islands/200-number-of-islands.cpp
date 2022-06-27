class Solution
{
    public:
    int dp[301][301];
        void dfs(vector<vector < char>> &grid, int i, int j)
        {
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
                return;
            if (grid[i][j] == '1'&&dp[i][j]!=1)
            {
               	// cout<<i<<j<<endl;

                
                grid[i][j] = 0;
                dfs(grid, i + 1, j);
                dfs(grid, i - 1, j);
                dfs(grid, i, j - 1);
                dfs(grid, i, j + 1);
                dp[i][j] = 1;
                return;
            }
            dp[i][j] = 1;
        }
    int numIslands(vector<vector < char>> &grid)
    {
        memset(dp, -1, sizeof(dp));
        int i = 0;
        int j = 0;
        int island = 0;
        for (i = 0; i < grid.size(); i++)
        {
            for (j = 0; j < grid[0].size(); j++)
            {
                if(dp[i][j]==1) continue;
                cout << i << j << endl;
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    island++;
                }
                dp[i][j] = 1;
            }
        }
        return island;
    }
};