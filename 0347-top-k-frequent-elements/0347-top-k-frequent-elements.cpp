class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto x: nums) mp[x]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto x: mp)
        {
            int cnt = x.second;
            int n = x.first;
            pq.push({cnt, n});
            if(pq.size()>k) pq.pop();
        }
        vector<int> v;
        for(; pq.size();pq.pop())
        {
            v.push_back(pq.top().second);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};