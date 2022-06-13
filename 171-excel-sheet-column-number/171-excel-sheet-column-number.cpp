class Solution
{
    public:
        int titleToNumber(string s)
        {
            int p = 1;
            int n = (int) s.size();
            for (int i = 0; i < n - 1; ++i) p *= 26;
            int res = 0;
            for (int i = 0; i < n; ++i)
            {
                res += p *(s[i] - 'A' + 1);
                p /= 26;
            }
            return res;
        }
};