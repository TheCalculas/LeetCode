class Solution {
public:
    bool isPalindrome(string str) {
        string s = "";
        for(auto x:str)
        {   cout<<"first : "<<x<<" ";
            if(x>='A'&&x<='Z') s.push_back(x+'a'-'A');
            else if(x>='a'&&x<='z') s.push_back(x);
            else if(x>='0'&&x<='9') s.push_back(x);
            else continue;
            cout<<"baadmei: "<<s[s.size()-1]<<endl;
        }
        cout<<s<<endl;
        string r = s;
        reverse(r.begin(), r.end());
        // if(r.size()==1) return 0;
        return r==s;
    }
};