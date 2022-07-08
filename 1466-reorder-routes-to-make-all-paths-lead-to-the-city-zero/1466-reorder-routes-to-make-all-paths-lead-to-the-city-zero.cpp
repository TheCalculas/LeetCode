class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        // it is a kind of bfs
        vector<int> out[n];
        vector<int> in[n];
        // set<pair<int, int>> s;
        for (auto x : connections)
        {
            out[x[0]].push_back(x[1]);
            in[x[1]].push_back(x[0]);
            // s.insert({x[0], x[1]});
        }
        queue<int> q;
        int count = 0;
        q.push(0);
        vector<bool> vis(n, false);
        while (q.size())
        {
            int node = q.front();
            vis[node] = true;
            q.pop();
            for (auto x : out[node])
            {
                if (!vis[x])
                {
                    count++;
                    q.push(x);
                }
            }
            for (auto x : in[node])
            {
                if (!vis[x])
                    q.push(x);
            }
        }
        return count;
    }
};