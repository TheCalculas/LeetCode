class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto x: arr)
        {
            mp[x]++;
        }
        vector<pair<int, int>> vp;
        for(auto x: mp)
        {
            vp.push_back({x.second, x.first});
        }
        
        sort(rbegin(vp), rend(vp));
        for(auto x: vp)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
        int n = arr.size();
        int total = 0;
        int no  = 0;
        int idx = 0;
        while(total<n/2)
        {
            total += vp[idx].first;
            idx++;
            no++;
        }
        return no;
    }
};