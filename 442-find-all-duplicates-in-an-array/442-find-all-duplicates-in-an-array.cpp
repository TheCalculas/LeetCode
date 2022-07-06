class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // cycle sort if i do 
        int i=0;
        set<int> s;
        vector<int> v;
        int n = nums.size();
        while(i<n)
        {
            if(nums[i]!=i+1)
            {
                if(nums[i]==nums[nums[i]-1]){
                    s.insert(nums[i]);
                    i++;
                    continue;
                }
                swap(nums[i], nums[nums[i]-1]);
            }
            
            else i++;
        }
        for(auto x:s)
            v.push_back(x);
        return v;
    }
};