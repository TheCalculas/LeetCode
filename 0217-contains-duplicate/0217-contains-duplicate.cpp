class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto x: nums)
        {
            st.insert(x);
        }
        if(st.size()==nums.size()) return false;
        return true;
    }
};