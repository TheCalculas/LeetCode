class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int a = -1 , b = -1;
        for(int i = nums.size()-2; i>=0; i--)
        {
            if(nums[i+1]>nums[i]) {
                a = i;
                break;
            }
        }
        cout<<a<<endl;
        if(a==-1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = nums.size()-1; i>=0; i--)
        {
            if(nums[i]>nums[a])
            {
                b = i; break;
            }
        }
        swap(nums[a], nums[b]);
        reverse(nums.begin()+1+a, nums.end());
        return ;
    }
};