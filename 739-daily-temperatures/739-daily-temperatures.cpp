class Solution
{
    public:
        vector<int> dailyTemperatures(vector<int> &temperature)
        {
            vector<int> answer(temperature.size(), 0);
            stack<int> st;
            for (int i = temperature.size() - 1; i >= 0; i--)
            {
                while (!st.empty() &&
                    temperature[st.top()] <= temperature[i])
                    st.pop();
                if (!st.empty())
                    answer[i] = st.top() - i;
                st.push(i);
            }
            return answer;
        }
};