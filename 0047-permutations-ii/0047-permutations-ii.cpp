class Solution {
public:
    
    void f(vector<int>& v, int idx, set<vector<int>>& st)
    {
        if(idx==v.size()){
            st.insert(v);
        }
        
        for(int i = idx; i<v.size(); i++)
        {
            swap(v[idx], v[i]);
            f(v, idx+1, st);
            swap(v[idx], v[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        f(nums, 0, st);
        
        for(auto x: st)
        {
            v.push_back(x);
        }
        return v;
    }
};