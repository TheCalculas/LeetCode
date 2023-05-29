class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<ll, set<pair<int, int>>> mp;
        set<vector<int>> st;
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                ll a =  (nums[j]+nums[i]);
                if(mp.find(target - a)!=mp.end())
                {
                    // agar voh mil gaya hai toh 
                    for(auto x: mp[target-a])
                    {vector<int> v = {x.first, x.second, nums[i] , nums[j]};
                    st.insert(v);}
                    
                }
            }
            for(int j = 0; j<i; j++)
                mp[nums[j]+nums[i]].insert({nums[j], nums[i]});
        }
        for(auto x: st) res.push_back(x);
        return res;
    }
};