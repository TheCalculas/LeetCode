class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> vv;
        for(int i=0; i<names.size(); i++)
        {
            vv.push_back({heights[i], names[i]});
        }
        sort(vv.begin(), vv.end());
        vector<string> v;
        for(auto x: vv)
        {
            v.push_back(x.second);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};