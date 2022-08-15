class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        int count = 0;
        vector<int> ans;
        for(auto x: nums)
        {
            if(mp[x]>1) continue;
            else {
                count++;
                mp[x]++;
                ans.push_back(x);
            }
        }
        nums = ans;
        return count;
    }
};