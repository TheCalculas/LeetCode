class Solution
{
    public:
        int minOperations(string s)
        {
            int n = s.length();
            int c1 = 0, c2 = 0;
            for (int i = 0; i < n; i++)
            {
               	// for 0101 sequence
                if (s[i] - '0' != i % 2)
                {
                    c1++;
                }
               	// for 1010 sequence, count violating
                if (s[i] - '0' == i % 2)
                {
                    c2++;
                }
            }
            return min(c1, c2);
        }
};