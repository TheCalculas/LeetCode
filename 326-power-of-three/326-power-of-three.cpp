class Solution
{
    // ye yaad rakhna ki 1162261467 is the biggest num which is a power of 3 
    public:
        bool isPowerOfThree(int n)
        {
            return n > 0 && 1162261467 % n == 0;
        }
};