class Solution
{
    public:
        bool strongPasswordCheckerII(string password)
        {
            if (password.size() < 8)
            {
                return false;
            }
            string str = "!@#$%^&*()-+";
            int up = 0, down = 0, dig = 0, special = 0;
            for (int i = 1; i < password.size(); i++)
            {
                if (password[i] == password[i - 1])
                    return false;
            }
            for (auto it: password)
            {
                if (isupper(it))
                    up++;
                else if (islower(it))
                    down++;
                else if (isdigit(it))
                    dig++;

                for (auto i: str)
                {
                    if (i == it)
                        special++;
                }
            }
            if (up == 0 || down == 0 || dig == 0 || special == 0)
                return false;

            return true;
        }
};