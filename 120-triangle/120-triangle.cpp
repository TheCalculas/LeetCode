class Solution
{
    public:
        int minimumTotal(vector<vector < int>> &triangle)
        {
            int n = triangle.size();
            vector<int> minlen(triangle.back());
            for (int row = n - 2; row >= 0; row--)
            {
                for (int i = 0; i <= row; i++)
                {
                    minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[row][i];
                }
            }
            return minlen[0];
        }
};