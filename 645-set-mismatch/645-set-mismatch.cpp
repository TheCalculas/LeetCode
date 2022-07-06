class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // sort the corresponding array using cyclic sort
        int i=0; 
        int n = nums.size();
        while(i<n)
        {
            int correct = nums[i]-1; // that should be the correct index and now we'll do stuff hehe 
            if(nums[i]!=nums[correct])
            {
                swap(nums[i], nums[correct]);
            }
            else i++;
        }
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            if(nums[i]!=i+1)
            {
                v.push_back(nums[i]);
                v.push_back(i+1)
;            }
        }
        return v;
    }
};