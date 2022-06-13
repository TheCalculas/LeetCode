class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int currbest = values[0] + 0;
        int ans = 0;
        int n = values.size();
        
        for(int i=1;i<n;i++)
        {
            ans = max(ans, currbest + values[i] - i);
            currbest = max(currbest, values[i] + i);
        }
        
        return ans;
    }
};