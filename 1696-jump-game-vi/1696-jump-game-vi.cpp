class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        // we are using deque as it has the time complexity of o1
        vector<int> dp(size(nums));
        // we can insert the first indexx or the last index depends upon your choice
        dp[0] = nums[0];
        deque<int> q{ 0 };
        for(int i = 1; i < size(nums); i++) {
            // agar ye unreachable hai toh
            if(q.front() < i - k) q.pop_front(); 
            // agar reachable hai toh ye hoga
            dp[i] = nums[i] + dp[q.front()]; 
            // agar values chhoti hai toh unhe discard kardo queue mei se
            while(!q.empty() && dp[q.back()] <= dp[i])   
                q.pop_back();
            // last me pushback kardo index of the greatest dp 
            q.push_back(i);                              
        }
        return dp.back();
    }
};