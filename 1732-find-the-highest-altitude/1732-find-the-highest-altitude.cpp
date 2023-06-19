class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> v(gain.size()+1, 0);
        for(int i = 0; i<gain.size(); i++)
        {
            v[i+1] = v[i] + gain[i];
        }
        return *max_element(v.begin(), v.end());
    }
};