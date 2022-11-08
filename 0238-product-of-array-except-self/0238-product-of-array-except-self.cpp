class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1);
        vector<int> surf(n, 1);
        for(int i=1; i<n; i++)
        {
            pref[i] = pref[i-1]*nums[i-1];
        }
        for(int i = n-2; i>=0; i--)
        {
            surf[i] = surf[i+1]*nums[i+1];
        }
        vector<int> v;
        v.push_back(surf[0]);
        for(int i=1; i<n-1; i++)
        {
            v.push_back(pref[i]*surf[i]);
        }
        v.push_back(pref[n-1]);
        return v;
    }
    
};