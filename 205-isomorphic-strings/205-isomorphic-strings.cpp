class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char, char> m;
        unordered_map<char, char> n;
        for(int i=0; i<s.length(); i++)
        {
            if(m.find(s[i])!=m.end()||n.find(t[i])!=n.end())
            {
                if(m[s[i]]!=t[i]) return false;
                if(n[t[i]]!=s[i]) return false;
                
            }
            else{
                cout<<s[i]<<" "<<t[i]<<endl;
                m[s[i]] = t[i];
                n[t[i]] = s[i];
            }
        }
        return true;
    }
};