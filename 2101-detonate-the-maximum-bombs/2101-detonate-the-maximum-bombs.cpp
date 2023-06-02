class Solution {
public:
    double f(int x1, int y1, int x2, int y2)
    {
        double len = (double)(x1-x2)*(x1-x2) + (double)(y1-y2)*(y1-y2);
        len = sqrt(len);
        return len;
    }
    
    int dfs(vector<int>&vis, int x, int y, int idx, int r, vector<vector<int>> &v)
    {
        if(idx==v.size()) return 0;
        if(vis[idx]==1) return 0;
        vis[idx] = 1;
        for(int idx = 0; idx<v.size(); idx++)
        {
            if(!vis[idx]&&f(x, y, v[idx][0], v[idx][1])<=(double)r)
            {
                dfs(vis, v[idx][0], v[idx][1], idx, v[idx][2], v);
            }
        }
        return 0;
    }
    int maximumDetonation(vector<vector<int>>& v) {
        int n = v.size();
        int mx = 0;
        // for(int i = 0; i<n; i++)
        // {
        //     int cnt = 0;
        //     cout<<"-------------"<<endl;
        //     for(int j = 0; j<n; j++)
        //     {
        //         if(j==i) continue;
        //         cout<<(f(v[i][0], v[i][1], v[j][0], v[j][1]))<<" "<<v[i][2]<<endl;
        //         if(f(v[i][0], v[i][1], v[j][0], v[j][1])<=(double)v[i][2]) cnt++;
        //     }
        //     mx = max(cnt, mx);
        // }
        
        for(int i =0; i<n; i++)
        {
            vector<int> vis(n+1, 0);
            dfs(vis, v[i][0], v[i][1], i, v[i][2], v);
            int cnt = 0;
            for(auto x: vis) if(x) cnt++;
            mx = max(mx, cnt);
        }
        
        return mx;
    }
};