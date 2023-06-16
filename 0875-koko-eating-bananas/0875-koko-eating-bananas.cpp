class Solution {
public:
    int minEatingSpeed(vector<int>& v, int h) {
        int lo = 1;
        int hi = *max_element(v.begin(), v.end());
        int ans = 0;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            // if(mid==0) break;
            long long cal = 0;
            for(auto x: v)
            {
                cal += x/mid;
                if(x%mid) cal++;
            }
            if(cal<=h)
            {
                if(ans == mid) break;
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};