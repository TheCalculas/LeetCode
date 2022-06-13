class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string c;
        string a;
        while(ss>>c)
        {
            a = c;
        }
        return a.size();
            
    }
};