class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> m;
        // flag 1 if the input is not changed
        vector<int> v;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }
        
        for(int i=0; i<nums.size(); i++){
        
          if(m.find(target-nums[i])!=m.end()&&(m.find(target-nums[i])->second>=2||m.find(target-nums[i])->first!=nums[i])){
                v.push_back(i);              
            }
        }
        return v;
    }
};