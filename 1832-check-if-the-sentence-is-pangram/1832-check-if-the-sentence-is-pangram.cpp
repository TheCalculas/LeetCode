class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> v(26, 0);
        for(auto x: s)
        {
            v[x-'a'] = 1;
        }
        int f = accumulate(v.begin(), v.end(), 0);
        return (f==26)?true:false;
    }
};