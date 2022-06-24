class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3){
            return 0;
        }
        for(int i = 1; i < nums.size(); i++){
            nums[i - 1] = nums[i - 1] - nums[i];
        }
        nums[nums.size() - 1] = INT_MIN;
        int target = nums[0];
        int count = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target){
                count++;
                continue;
            }
            if(count > 1){
                sum += (count - 1) * count / 2;
            }
            count = 1;
            target = nums[i];
            
        }
        return sum;
    }
};