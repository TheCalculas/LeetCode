class Solution {
public:
    int firstBadVersion(int n) {
        long long int high=n,low=1,mid;
        while(high-low>1)
        {
            mid = (low+high)/2;
            if(isBadVersion(mid)) high=mid;
            else low = mid+1;
        }
        if(isBadVersion(low)) return low;
        else return high;
    }
};