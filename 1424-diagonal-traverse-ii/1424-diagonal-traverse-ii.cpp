class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> v;
        int n = nums.size();
        int m = nums[0].size();
        map<int, vector<int>> mp;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        for(auto x: mp)
        {
            for(auto it: x.second)
            {
                v.push_back(it);
            }
        }
        return v;
        
    }
};