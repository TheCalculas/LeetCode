class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto x: nums){
            m[x]++;
        }
        vector<pair<int, int>> v;
        for(auto x:m)
        {
            v.push_back({x.second, x.first});
        }
        sort(v.rbegin(), v.rend());
        vector<int> ans;
        for(int i=0; i<k; i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};