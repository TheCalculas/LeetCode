long mod = pow(10, 9) + 7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long > dp; // ye store karega stuff 
        sort(arr.begin(), arr.end());
        long kitneTree = 0;
        for(int i=0; i<arr.size(); i++)
        {
            int first = arr[i];
            dp[first] = 1; // as har banda is it'self a tree :3
            for(int j=0; j<i; j++)
            {
                int second = arr[j];
                if(first%second==0) // agar voh dono div hai ek doosre se toh
                {
                    dp[first] = (dp[first] + (dp[second]*dp[first/second]))%mod;
                }
                
            }
            
            kitneTree =(kitneTree + dp[first])%mod;
            
        }
        return kitneTree;
    }
};