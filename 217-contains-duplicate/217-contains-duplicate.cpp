class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto x: nums)
            s.insert(x);
        int n = s.size();
        int m = nums.size();
        return !(n==m);
    }
};