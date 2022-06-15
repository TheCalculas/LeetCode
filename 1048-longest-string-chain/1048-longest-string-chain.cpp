class Solution
{

    static bool compare(const string &s1, const string &s2)
    {
        return s1.length() < s2.length();
    }

    public:
        int longestStrChain(vector<string> &words)
        {
            sort(words.begin(), words.end(), compare);

            unordered_map<string, int> dp;

            for (string w: words)
            {
                int maxi = 0;
                for (int i = 0; i < w.length(); i++)
                {
                    string word = w.substr(0, i) + w.substr(i + 1);
                    maxi = max(maxi, dp[word] + 1);
                }

                dp[w] = maxi;
            }

            int result = 0;
            for (auto m: dp)
            {
                result = max(result, m.second);
            }

            return result;
        }
};