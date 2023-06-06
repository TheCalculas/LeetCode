class Solution {
public:
    int firstOcc(vector<int>& v, int target)
    {
        int lo = 0;
        int hi = v.size()-1;
        int idx = -1;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if(v[mid]==target)
            {
                idx = mid;
                hi = mid-1;
            }
            else if(v[mid]<target)
            {
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        return idx;
    }
    int lastOcc(vector<int>& v, int target)
    {
        int lo = 0;
        int hi = v.size()-1;
        int idx = -1;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if(v[mid]==target)
            {
                idx = mid;
                lo = mid+1;
            }
            else if(v[mid]<target)
            {
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = firstOcc(nums, target);
        int b = lastOcc(nums, target);
        return {a, b};
    }
};