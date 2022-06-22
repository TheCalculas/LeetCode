class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(rbegin(nums), rend(nums));
        for(auto x: nums)cout<<x<<" ";
        return nums[k-1];
    }
};