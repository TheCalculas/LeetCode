class Solution {
public:
    string fractionToDecimal(long long n, long long d) {
        string ans="";
        if((n<0&&d>0) || (n>0&&d<0)) ans.push_back('-');
        n=abs(n);
        d=abs(d);
        long long di=n/d;
        ans+=to_string(di);
        n%=d;
        if(n==0) return ans;
        ans.push_back('.');
        unordered_map<int,int> mp;
        while(n){
            if(mp.find(n)!=mp.end()){
                ans.insert(ans.begin()+mp[n],'(');
                ans.push_back(')');
                return ans;
            }
            mp[n]=ans.size();
            n*=10;
            ans.push_back((n/d)+'0');
            n%=d;
        }
        return ans;
    }
};