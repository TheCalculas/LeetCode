class Solution {
public:
    #define ll long long
    vector<int> findErrorNums(vector<int>& nums) {
        // m-r 
        ll s=0,ss=0,n=nums.size();
        for(auto &it:nums){
            s+=it;
            ss+=(it*it);
        }
        
        ll rs=(n*(n+1))/2,rss=((n)*(n+1)*(2*n+1))/6;
        ll mpr=(ss-rss)/(s-rs);
        return {(int)(mpr+(s-rs))/2,(int)(mpr-(s-rs))/2};
    }
};