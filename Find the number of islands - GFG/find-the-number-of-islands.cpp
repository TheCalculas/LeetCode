//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& g, int x, int y)
    {
        if(x<0||y<0||x>=g.size()||y>=g[0].size()) return;
        if(g[x][y]=='0') return;
        g[x][y] = '0';
        
        dfs(g, x+1, y);
        dfs(g, x-1, y);
        dfs(g, x, y+1);
        dfs(g, x, y-1);
        dfs(g, x+1, y+1);
        dfs(g, x-1, y-1);
        dfs(g, x-1, y+1);
        dfs(g, x+1, y-1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int cnt = 0;
        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j<grid[0].size(); j++)
            {
                if(grid[i][j]=='1') {dfs(grid, i, j); cnt++;}
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends