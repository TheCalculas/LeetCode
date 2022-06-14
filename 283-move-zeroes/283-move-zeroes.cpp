class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> a; 
        for(auto x: nums) if(x)a.push_back(x);
        int n = a.size();
        n=nums.size()-n;
        for(auto i =0; i<n; i++) a.push_back(0);
        nums = a;
    }
};