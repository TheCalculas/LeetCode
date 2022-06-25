class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        if(mat[0].size()*mat.size()!=r*c)
            return mat;
        
        int x=0, y=0;
        
        vector<vector<int>> res;
        for(int i=0;i<r;i++)
        {
            vector<int> v;
            for(int j=0;j<c;j++)
            {
               v.push_back(mat[x][y++]);
                if(y==mat[0].size())
                {x++;y=0;}
            }
            res.push_back(v);
        }
        
        return res;
    }
};