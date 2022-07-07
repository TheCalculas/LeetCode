class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<vector<pair<int, int>>> mp(n+1);
        vector<int> dist(n+1, INT_MAX);
        
        for(auto &i: times){
            mp[i[0]].push_back({i[1], i[2]});
        }
        
        pq.push({0, k});
        dist[k] = 0;
        
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            
            for(auto& [i, j] : mp[t.second]){
                int c = j + t.first;
                if(c < dist[i]){
                    dist[i] = c;
                    pq.push({c, i});
                }
            }
        }
        
        int ans = *max_element(dist.begin()+1, dist.end());
        
        return ans == INT_MAX ? -1 : ans;
    }
};