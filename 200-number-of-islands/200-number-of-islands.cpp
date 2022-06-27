class Solution
{
    public:
        void dfs(vector<vector < char>> &grid, int i, int j)
        {
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
                return;
            if (grid[i][j] == '1')
            {
               	// cout<<i<<j<<endl;
                grid[i][j] = 0;
                dfs(grid, i + 1, j);
                dfs(grid, i - 1, j);
                dfs(grid, i, j - 1);
                dfs(grid, i, j + 1);
                return;
            }
        }
    int numIslands(vector<vector < char>> &grid)
    {
        int i = 0;
        int j = 0;
        int island = 0;
        for (i = 0; i < grid.size(); i++)
        {
            for (j = 0; j < grid[0].size(); j++)
            {
                cout << i << j << endl;
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    island++;
                }
            }
        }
        return island;
    }
};