class Solution {
public:
    int trap(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> pref(n) , suff(n);
        int current = INT_MIN;
        for (int i = 0 ; i < n ; i += 1) {
            current = max(current , arr[i]);
            pref[i] = current;
        }
        
        current = INT_MIN;
        for (int i = n - 1 ; i >= 0 ; i -= 1) {
            current = max(current , arr[i]);
            suff[i] = current;
        }
        
        int ans = 0;
        for ( int i = 0 ; i < n ; i += 1 ) {
            int mn = min(pref[i] , suff[i]);
            ans += (abs(mn - arr[i]));
        }
        
        return ans;
        
    }
};