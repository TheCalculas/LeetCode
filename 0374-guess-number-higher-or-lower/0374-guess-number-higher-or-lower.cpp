/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int hi = n;
        int lo = 1;
        while (1)
        {
            int mid = (hi - lo) / 2 + lo;
            int hehe = guess(mid);
            if (hehe == -1)
            {
                hi = mid - 1;
            }
            else if (hehe == 1)
            {
                lo = mid + 1;
            }
            else
                return mid;
        }
    }
};