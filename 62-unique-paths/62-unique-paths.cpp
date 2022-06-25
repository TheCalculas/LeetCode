class Solution {
public:
    int uniquePaths(int m, int n) {
        int t[m][n];
        memset(t, 0, sizeof(t));
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) t[i][j] = 1;
                
                if (i+1 < m) t[i][j] += t[i+1][j];
                if (j+1 < n) t[i][j] += t[i][j+1];
            }
        }
        
        return t[0][0];
    }
};