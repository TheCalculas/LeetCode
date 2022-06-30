class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> a = nums;
        sort(a.begin(), a.end());
        if(a==nums) return true;
        reverse(a.begin(), a.end());
        if(a==nums) return true;
        return false;
    }
};