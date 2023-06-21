class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // create a frequency array
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxVal + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }
        
        // use dynamic programming to find the maximum points
        int take = 0, skip = 0;
        for (int i = 1; i <= maxVal; i++) {
            int takei = skip + i * freq[i]; // take the current value
            int skipi = max(take, skip); // skip the current value
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};