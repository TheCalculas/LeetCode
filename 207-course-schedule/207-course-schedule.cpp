class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(n); // graph
        vector<int> degree(n, 0), bfs; // degree
        for (auto& e : prerequisites)
            G[e[1]].push_back(e[0]), degree[e[0]]++;
        for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i); /// if it is parent 
        for (int i = 0; i < bfs.size(); ++i)
            for (int j: G[bfs[i]])
                if (--degree[j] == 0) bfs.push_back(j);
        return bfs.size() == n; // if all of em gets visited then it is the case
    }
};