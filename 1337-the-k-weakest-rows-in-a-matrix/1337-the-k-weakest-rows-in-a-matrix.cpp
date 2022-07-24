class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        /*
        Steps ->
        
        1. We'll store no of soldies and rowIndex in a pair
        2. Sort the pair 
        3. then, we'll push first k elements (the second 
        of the pair) into the ans vector
        
        */
        vector<int> ans;
        vector<pair<int, int>> vect;
        
        int m = mat.size(), n = mat[0].size();
        for(int i=0; i<m; i++)
        {
            int j=0, cntSol = 0;
            while(j<n && mat[i][j++] == 1)
                cntSol++;
            
            vect.push_back({cntSol, i});
        }
        
        sort(vect.begin(), vect.end());
        
        for(int i=0; i<k; i++)
        {
            int ele = vect[i].second;
            ans.push_back(ele);
        }
        return ans;
    }
};
