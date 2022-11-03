class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> mp, freq;
        for(auto x: nums)
        {
            mp[x]++;
        }
        unordered_map<int, vector<int>> vv;
        for(auto x: mp)
        {
            int n = x.first;
            int f = x.second;
            while(f--)
            vv[n%space].push_back(n);
        }
        int mx = 0;
        for(auto x: vv)
        {
            int a = x.second.size();
            mx = max(a, mx);
        }
        vector<int> ans;
        for(auto x: vv)
        {
            cout<<x.first<<" "<<x.second.size()<<endl;
            if(x.second.size()==mx)
            {
                sort(x.second.begin(), x.second.end());
                ans.push_back(x.second[0]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans[0];
        // return -1;
        
    }
};