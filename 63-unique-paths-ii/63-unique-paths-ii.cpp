class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        long m = obstacleGrid.size();
        long n = obstacleGrid[0].size();
        long t[m][n];
        memset(t, 0, sizeof(t));
        
        for (long i = m-1; i >= 0; i--) {
            for (long j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) t[i][j] = 1;
                if (i+1 < m) t[i][j] += t[i+1][j];
                if (j+1 < n) t[i][j] += t[i][j+1];
                if(obstacleGrid[i][j]==1) t[i][j] = 0;
            }
        }
        
        return t[0][0];

    }
};