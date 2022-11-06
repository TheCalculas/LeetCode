class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1)
        {
            sort(s.begin(), s.end());
            return s;
        }
        string res = s;
        int n = s.length();
        s+=s;
        for(int i=0; i<n; i++)
        {
            if(res>s.substr(i,n)) res = s.substr(i, n);
        }
        return res;
        
    }
};