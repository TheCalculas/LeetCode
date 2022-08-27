class Solution {
public:
    int dp[100];
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int sum = 0, ans = -1000000000;
        for (int i=0; i<n; ++i) {
            for (int l=0; l<m; ++l) dp[l] = 0;
            for (int j=i; j<n; ++j){
                for (int l=0; l<m; ++l) {
                    dp[l] += matrix[j][l];
                }
                
                for (int a=0; a<m; ++a) {
                    sum = 0;
                    for (int b=a; b<m; ++b) {
                        sum += dp[b]; 
                        if(sum > ans && sum <= k) ans = sum;
                    }
                }
            }
        }
        
        return ans;
    }
};