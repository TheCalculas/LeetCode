class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        int row = rows - 1, col = 0;
        int count = 0;

        while (row >= 0 and col < cols)
        {
            if (grid[row][col] < 0)
            {
                count += cols - col;
                row--;
            }
            else
            {
                col++;
            }
        }
        return count;
    }
};