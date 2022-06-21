class Solution {
public:
    // it is the lcs problem onllyyy
    // code of lcs
    int dp[101][10001];
    int lcs(string s, string t, int n, int m){
        if(n==0||m==0) return dp[n][m] = 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==t[m-1]) return dp[n][m] = 1+ lcs(s, t, n-1, m-1);
        else{
            return dp[n][m] = (lcs(s,t,n, m-1));
        }
    }
    bool isSubsequence(string s, string t) {
        
        memset(dp, -1,sizeof(dp));
        // now the code begins hehe
        int n = s.length();
        int m = t.length();
        int len = lcs(s, t, n, m);
        if(len==n) return true;
        else return false;
    }
};