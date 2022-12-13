class Solution
{
    public:
        int t[101][101];
    int solve(vector<vector < int>> &matrix, int i, int j, int row, int col)
    {
       	// if(i==row-1 && (j>=0 || j < col))
       	//    return 0;
       	// if(i < 0 || j < 0)
       	//     return 10000;
       	// if(i>=row || j>=col)
       	//     return 10000;

        if (i >= row) return 0;
        if (j < 0 || j >= col) return 1000000;
        if (t[i][j] != -1)
            return t[i][j];

        int ans = INT_MAX;

        int down = matrix[i][j] + solve(matrix, i + 1, j - 1, row, col);
        int dl = matrix[i][j] + solve(matrix, i + 1, j, row, col);
        int dr = matrix[i][j] + solve(matrix, i + 1, j + 1, row, col);
        int temp = min(down, min(dl, dr));

        ans = min(temp, ans);

        return t[i][j] = ans;
    }
    int minFallingPathSum(vector<vector < int>> &matrix)
    {
        memset(t, -1, sizeof(t));
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = INT_MAX;
        for (int j = 0; j < col; j++)
        {

            int temp = solve(matrix, 0, j, row, col);
            ans = min(ans, temp);
            cout << ans << endl;
        }
        return ans;
    }
};