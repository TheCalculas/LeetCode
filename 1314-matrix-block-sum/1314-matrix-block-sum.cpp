class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> prefix(mat);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                // is i-1 is over 0 then add i-1, if j-1 over 0 add j-1
                if(i-1>=0){
                    prefix[i][j] += prefix[i-1][j];
                }
                if(j-1>=0){
                    prefix[i][j] += prefix[i][j-1];
                }
                if(j-1>=0 & i-1>= 0){
                    prefix[i][j] -= prefix[i-1][j-1];
                }
            }
        }
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(mat);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                // is i-1 is over 0 then add i-1, if j-1 over 0 add j-1
                res[i][j] = prefix[min(m-1,i+k)][min(n-1,j+k)];
                if(i-k-1>=0){
                    res[i][j] -= prefix[i-k-1][min(n-1,j+k)];
                }
                if(j-k-1>=0){
                    res[i][j] -= prefix[min(m-1,i+k)][j-k-1];
                }
                if(i-k-1>=0&&j-k-1>=0){
                    res[i][j] += prefix[i-k-1][j-k-1];
                }
            }
        }
        return res;
    }
};