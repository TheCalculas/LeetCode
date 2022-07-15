class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int &area, int n, int m)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return;
        if (grid[i][j] == 0)
            return;
        else
        {
            grid[i][j] = 0;
            area++;
            dfs(grid, i + 1, j, area, n, m);
            dfs(grid, i - 1, j, area, n, m);
            dfs(grid, i, j + 1, area, n, m);
            dfs(grid, i, j - 1, area, n, m);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int maxAreaOfIsland = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = 0;
                    dfs(grid, i, j, area, n, m);
                    maxAreaOfIsland = max(maxAreaOfIsland, area);
                }
            }
        }
        return maxAreaOfIsland;
    }
};