class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
         vector<vector<int>> ans;
        vector<int> temp;
        int tc = 0;
        int n = mat.size();
        int m = mat[0].size();
        
       if(r*c != n*m){
           return mat;
       }
        for(int i=0; i<n;i++){
            for(int j=0; j<m ;j++){
                temp.push_back(mat[i][j]);
                tc++;
                if(tc == c){
                    tc = 0;
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
   
};