class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // curr best will store the best values rn present 
        int currbest = values[0] + 0;
        // ans will store the result
        int ans = 0;
        // n is the size of the array
        int n = values.size();
        
        for(int i=1;i<n;i++)
        {
            // as we have to find the best ans we'll maximize it
            ans = max(ans, currbest + values[i] - i);
            // in this curr best == values[j] + j
            // so when you perform currbest + values[i] - i
            // it gets evaluated as => values[I] +  values[j] + j - i where ( i > j)
            // store the current best in the current best
            currbest = max(currbest, values[i] + i);
        }
        
        return ans;
    }
};