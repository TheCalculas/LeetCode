class Solution
{
public:
    int specialArray(vector<int> &nums)
    {

        int special = -1;
        int freq[1002] = {0};

        // used to count the frequency of all elements in nums array
        for (int num : nums)
        {
            ++freq[num];
        }

        // I am using prefix sum to find count of all the numbers greater than or equal to x
        // So for a particular number , if there are numbers greater than or equal to x present
        // in the array, and if that count == the number itself, its a special array.

        int pref[1001] = {0};
        pref[1000] = freq[1000];
        for (int i = 999; i >= 0; --i)
        {
            pref[i] = pref[i + 1] + freq[i];
        }

        // If special exists, then finding that special number
        for (int i = 0; i < 1001; ++i)
        {
            if (i != 0 && pref[i] == i)
            {
                special = i;
                break;
            }
        }
        return special;
    }
};