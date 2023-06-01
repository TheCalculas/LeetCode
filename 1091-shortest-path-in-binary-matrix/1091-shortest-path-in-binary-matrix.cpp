class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0]!=0||grid[n-1][m-1]!=0) return -1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int count = 0;
        while(q.size())
        {
            int a = q.size();
            count++;
            while(a--)
            {
                auto p = q.front();
                if(p.first==n-1&&p.second==m-1) {
                    return count;
                    // break;
                }
                q.pop();
                vector<pair<int, int>> v = {{-1, 0}, {-1, -1}, {0, -1}, {1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}};
                for(auto x: v)
                {
                    if(p.first+x.first>=0&&p.first+x.first<n&&p.second+x.second>=0&&p.second+x.second<m&&grid[p.first+x.first][p.second+x.second]==0)
                    {
                        q.push({p.first+x.first, p.second+x.second});
                        grid[p.first+x.first][p.second+x.second] = 1;
                    }
                }
                
            }
            
        }
        return -1;
    }
};