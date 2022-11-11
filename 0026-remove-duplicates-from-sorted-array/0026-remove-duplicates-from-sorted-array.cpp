class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=1;
        int prev = nums[0];
        int j = 1;
        while(i<n)
        {
            if((prev == nums[i])&&(i<n)){
                i++;
                continue;
            }
            if(i==n) break;
            nums[j] = nums[i];
            prev = nums[j];
            j++;
            i++;
            
                
        }
        return j;
        
    }
};