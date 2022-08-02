class Solution
{
    public:
        bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector< int>> &dp)
        {
            if (target == 0)
                return true;

            if (ind == 0)
                return arr[0] == target;

            if (dp[ind][target] != -1)
                return dp[ind][target];

            bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

            bool taken = false;
            if (arr[ind] <= target)
                taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

            return dp[ind][target] = notTaken || taken;
        }
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int n = nums.size();
        int k = sum / 2;
        vector<vector < int>> dp(n, vector<int> (k + 1, -1));

        return subsetSumUtil(n - 1, k, nums, dp);
    }
};