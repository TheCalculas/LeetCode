class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>v(n, vector<int>(m, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        while(q.size())
        {
            vector<int> t = q.front();
            q.pop();
            if(t[0]<0||t[0]>=n||t[1]<0||t[1]>=m)
            {
                continue;
            }
            if(t[0]==n-1&&t[1]==m-1)
            {
                return t[2];
            }
            
            // agar merepaas obstacle aata hai toh 
            if(grid[t[0]][t[1]]==1)
            {
                if(t[3])
                    t[3]--;
                else continue;
            }
            int x= t[0];
            int y = t[1];
            int c = t[2];
            int r = t[3];
            // if(v[x][y]!=-1&&)
            if(v[x][y]!=-1 && v[x][y]>=t[3])
                continue;
            v[x][y]=t[3];
            q.push({x+1, y, c+1, r});
            q.push({x, y+1, c+1, r});
            q.push({x, y-1, c+1, r});
            q.push({x-1, y, c+1, r});
        }
        return -1;
    }
};