class Solution
{
    public:

        int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector< int > &worker)
        {
            vector<int> diff_pro(100001, 0);
            int res = 0;
            for (int i = 0; i < difficulty.size(); i++)
            {
                diff_pro[difficulty[i]] = max(diff_pro[difficulty[i]], profit[i]);
            }
            for (int i = 1; i < 100001; i++)
            {
                diff_pro[i] = max(diff_pro[i], diff_pro[i - 1]);
            }
            for (int i = 0; i < worker.size(); i++)
            {
                res += diff_pro[worker[i]];
            }
            return res;
        }
};