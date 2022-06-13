class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        unordered_map<char,int> n;
        for(auto x:s)m[x]++;
        for(auto x:t)n[x]++;
        if(m==n)return true;
        return false;
    }
};