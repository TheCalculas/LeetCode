class Solution
{
    public:
        string convertToTitle(int colNum)
        {
            string ans = "";
            while (colNum)
            {
                colNum--;
                int r = colNum % 26;
                char c = 'A' + r;
                ans = c + ans;
                colNum /= 26;
            }
            return ans;
        }
};