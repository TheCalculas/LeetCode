class Solution {
public:
    int findMin(vector<int>& v) {
        // toh ye basic binary search ka implementation hai :p
        int n = v.size();
        int high = n-1;
        int low = 0;
        while(high>low)
        {
            int mid = low + (high-low)/2;
            // ans waali condition 
            if (v[mid] < v[high])
                high = mid;
            else if (v[mid] > v[high])
                low = mid + 1;
            
        }
        return v[low];
    }
};