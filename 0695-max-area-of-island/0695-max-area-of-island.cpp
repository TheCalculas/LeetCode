class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int steps = 0;
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> direc = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int area = 0;
        int mx = 0;
        for(int x = 0; x<n; x++)
        {
            for(int y = 0; y<m; y++)
            {
                // if i found that gird has === '1'
                if(v[x][y]==1){
                    area = 0;
                    v[x][y]  = 0;
                    // steps++;
                    area ++;
                    queue<pair<int, int>> q;
                    q.push({x, y});
                    while(q.size())
                    {
                        // auto a = q.front();
                            auto a = q.front();
                            q.pop();

                            int i = a.first, j = a.second;
                            

                            // vector<int> v
                            for(int k = 0; k<4; k++)
                            {
                                int dx = direc[k][0];
                                int dy = direc[k][1];
                                if(i+dx>=0 && i+dx<n && j+dy>=0 && j+dy<m && v[i+dx][j+dy]==1)
                                {
                                    q.push({ i+dx, j+dy });
                                    area++;
                                    v[i+dx][j+dy] = 0; // this was the most imp thing dude!
                                }
                            }
                    }
                        mx = max(mx, area);
                    
                }
            }
        }
        return mx;
    }
};