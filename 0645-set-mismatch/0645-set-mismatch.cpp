class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 0);
        for(int i=0; i<n; i++){
            v[nums[i]-1]++;
        }
        // vector<int> vt;
        for(auto x: v)
        {
            cout<<x<<" ";
        }
        int repeat;
        int no_exist;
        for(int i=0; i<n; i++)
        {
            if(v[i]==2) repeat = i;
            if(v[i]==0) no_exist = i;
        }
        return {repeat+1, no_exist+1};
    }
};