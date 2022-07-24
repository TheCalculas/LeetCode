class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing(arr.size());
        missing[0] = arr[0]-1;
        for(int i=1;i<arr.size();++i)
            missing[i] = missing[i-1] + arr[i] - arr[i-1] - 1;
        int pos = lower_bound(missing.begin(),missing.end(),k)-missing.begin();
        return pos==0 ? k : arr[pos-1] + k-missing[pos-1]; 
    }
    
};