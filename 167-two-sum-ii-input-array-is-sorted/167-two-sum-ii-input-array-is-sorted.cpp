class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int hi = numbers.size()-1;
        int lo = 0;
        vector<int> v;
        while(lo<=hi)
        {
            int a = numbers[lo];
            int b = numbers[hi];
            if(a+b==target)
                return {lo+1, hi+1};
            else if(a+b<target)
            {
                lo++;
            }
            else hi--;
        }
        return {hi+1, lo+1};
    }
};