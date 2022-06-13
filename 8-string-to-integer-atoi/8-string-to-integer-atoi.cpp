class Solution
{
    public:
        int myAtoi(string s)
        {
            while (s[0] == ' ')
                s.erase(s.begin());

            long sum = 0, sign = 1;
            if (s[0] == '-')
            {
                sign = -1;
                s.erase(s.begin());
            }
            else if (s[0] == '+')
            {
                sign = 1;
                s.erase(s.begin());
            }

            for (int i = 0; i < s.length(); i++)
            {
                if (!isdigit(s[i]))
                    return sign * sum;
                else
                    sum = sum *10 + s[i] - '0';

                if (sum > INT_MAX)
                    return (sign == -1) ? INT_MIN : INT_MAX;
            }

            return sum * sign;
        }
};