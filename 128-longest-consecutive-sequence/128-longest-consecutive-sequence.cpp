class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // making a hash set
        unordered_set<int> s;
        for(auto x:nums)
        {
            s.insert(x);
        }
        
        int n = nums.size();
        int curr;
        int num =0;
        int countt = 0;
        for(int i=0; i<n;i++)
        {
            
            
            if(!s.count(nums[i]-1))
            {
                curr = nums[i];
                num = 0;
            }
            while(s.count(curr))
            {
                curr++;
                
                num++;
            }
            countt = max(countt, num);
        }
        return countt;
    }
};