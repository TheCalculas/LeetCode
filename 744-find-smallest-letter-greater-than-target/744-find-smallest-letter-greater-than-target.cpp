class Solution
{
public:
    char nextGreatestLetter(vector<char> &v, char t)
    {
        int n = v.size();
        int lo = 0;
        int hi = v.size() - 1;
        while (lo <= hi)
        {
            int mid = (hi - lo) / 2 + lo;
            if (v[mid] == t)
            {
                lo = mid + 1;
            }
            else if (v[mid] < t)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        if (lo == n)
            return v[0];
        else
            return v[lo];
    }
};