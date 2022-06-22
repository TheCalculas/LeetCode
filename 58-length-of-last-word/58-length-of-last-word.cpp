class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string c;
        string a;
        while(ss  >>   c)
        {
            cout<<c<<" ";
            a = c;
        }
        cout<<endl;
        return a.size();
            
    }
};