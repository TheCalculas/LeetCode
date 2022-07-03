class Solution {
public:
    void bfs(vector<int> &vis, int &i, vector<vector<int>> &v)
    {
        vis[i] = true;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int no = q.front();
            q.pop();
            for(int j=0; j<v.size(); j++)
            {
                if(v[no][j]&&!vis[j])
                {
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> vis(n,0);
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                count++;
                bfs(vis, i, v);
            }
            
        }
        return count;
    }
};