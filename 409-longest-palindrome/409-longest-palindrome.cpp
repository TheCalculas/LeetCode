class Solution {
public:
    int longestPalindrome(string s) {
        int count[128];
        memset(count, 0, sizeof(count));
        for(auto x: s)
        {
            count[x]++;
        }
        int res = 0;
        for(auto x:count)
        {
            res += x/2 *2;
            if(res%2==0&&x%2==1)res++;
            
        }
        return res;
    }
};