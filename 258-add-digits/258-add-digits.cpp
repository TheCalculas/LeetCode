class Solution
{
    public:
        int addDigits(int num)
        {
            int tmp = 0;
            while (true)
            {
                tmp += num % 10;
                num /= 10;
                if (num == 0)
                {
                    if (tmp < 10)
                    {
                        return tmp;
                    }
                    num = tmp;
                    tmp = 0;
                }
            }
            return -1;
        }
};