class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        vector<vector<int>> v;
        for(int i=0; i<n; i++)
        {
            vector<int> vv;
            for(int j = 0; j<m-1; j++)
            {
                vv.push_back(words[i][j+1]-words[i][j]);
            }
            v.push_back(vv);
        }
        
        map<vector<int>,int> mp;
        for(auto x: v)
            mp[x]++;
        vector<int> re;
        for(auto x: mp)
            if(x.second==1) re = x.first;
        int idx = -1;
        
        for(auto x: v)
        {
            idx++;
            if(x==re) break;
        }
        return words[idx];

    }
};