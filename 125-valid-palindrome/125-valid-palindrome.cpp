class Solution
{
    public:
        bool isPalindrome(string s)
        {
            // Bruhh this code is good :)
            // isalmum checks if the character is alpha numeric or not hmm useful too
            // and even faster 
            int left = 0, right = s.size() - 1;

            while (left < right)
            {
                if (!isalnum(s[left]))
                {
                    left++;
                    continue;
                }
                if (!isalnum(s[right]))
                {
                    right--;
                    continue;
                }
                if (tolower(s[left]) != tolower(s[right]))
                {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }
};