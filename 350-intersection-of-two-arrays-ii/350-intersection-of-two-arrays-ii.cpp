class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for(auto x: nums1) m[x]++;
        unordered_map<int, int> n;
        for(auto x: nums2) n[x]++;
        vector<int> v;
        for(auto x:m)
        {
            if(n.find(x.first)!=n.end())
            {
                int a = min(x.second, n[x.first]);
                while(a--)
                v.push_back(x.first);
            }
        }
        return v;
    }
};