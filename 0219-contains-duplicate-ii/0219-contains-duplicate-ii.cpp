class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            int a = nums[i];
            if(mp.find(a)!=mp.end())
            {
                int dif = i - mp[a];
                if(dif<=k) return true;
                else mp[a] = i;
            }
            else {
                mp[a] = i;
            }
        }
        return false;
    }
};