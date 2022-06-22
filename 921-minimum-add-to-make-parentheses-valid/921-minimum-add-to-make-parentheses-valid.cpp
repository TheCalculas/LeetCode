class Solution {
public:
    int minAddToMakeValid(string s) {
        int a1=0,a2=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(') a1++;
            else{
                if(a1>0) a1--;
                else a2++;
            }
        }
        return a1+a2;
    }
};