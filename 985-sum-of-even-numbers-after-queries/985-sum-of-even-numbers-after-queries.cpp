class Solution
{
    public:
        vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector< int>> &queries)
        {
            vector<int> res;
           	// init sum
            int sum = 0;
            for (auto x: nums)
            {
                if (x % 2 == 0) sum += x;
            }
            
            for (int i = 0; i < queries.size(); i++)
            {
                int idx = queries[i][1];
                int val = queries[i][0];
                int prev = nums[idx];
                if(prev%2==0)
                sum = sum - prev;
                nums[idx] += val;
                if(nums[idx]%2==0)
                sum = sum + nums[idx];
                res.push_back(sum);
            }
            return res;
        }
};