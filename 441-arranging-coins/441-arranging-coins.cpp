class Solution
{
public:
    int arrangeCoins(int n)
    {
        // so it is a tricky problem hehe
        long hi = n;
        long lo = 1;
        while (lo <= hi)
        {
            long mid = (hi - lo) / 2 + lo;
            long sum = mid * (mid + 1) / 2;
            if (sum < n)
            {
                lo = mid + 1;
            }
            else if (sum == n)
                return mid;
            else
                hi = mid - 1;
        }
        return hi;
    }
};