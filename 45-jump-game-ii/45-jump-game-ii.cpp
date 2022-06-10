class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int count = 0;
        while(end<nums.size()-1)
        {
            int mx = start;
            for(int i=start; i<=end; i++)
            {
                mx = max(mx, nums[i]+i);
            }
            start = end+1;
            end = mx;
            count++;
        }
        return count;
    }
};