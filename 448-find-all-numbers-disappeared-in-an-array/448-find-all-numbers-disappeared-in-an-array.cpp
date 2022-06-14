class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0 ; i<n ; i++)
        {
            while(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        vector<int> v;
        for(int i=0 ; i<n ; i++) if(nums[i] != i+1) v.push_back(i+1);
        return v;
    }
};