class Solution {
public:
    void dfs(string &s, int idx, int n, bool &flag)
    {
        if(idx>=n-1) return;
        if(s[idx]=='0'&&s[idx+1]=='1')
        {
            s[idx] = '1';
            s[idx+1] = '0';
            flag = true;
            dfs(s, idx+2, n, flag);
        }
        else{
            dfs(s, idx+1, n, flag);
        }
        
    }
    int secondsToRemoveOccurrences(string s) {
        if(s.size()<2) return 0;
        bool flag = false;
        int cnt = 0;
        int n = s.size();
        while(1)
        {
            
            flag = false;
            dfs(s, 0, n, flag);
            cnt++;
            if(flag ==false) break;
        }
        return cnt-1;
    }
};