class Solution {
public:
    static bool cmp(vector<int> &a , vector <int> &b){
        if(a[0]!=b[0]) return a[0] < b[0];
        else return a[1] < b[1];
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//         vector <vector<int>> v;
//         for(int i = 0 ; i < mat.size() ; i++){
//             int sum = 0;
//             for(int j = 0; j < mat[0].size() ; j++){
//                 sum += mat[i][j];
//             }
//             v.push_back(vector <int> {sum,i}); //soldiers,row
//         }
        
//         sort(v.begin() , v.end() , cmp);
//         vector <int> soln;
//         for(int i = 0 ; i < k ; i++) soln.push_back(v[i][1]);
//         return soln;
        
        
        
        // Find first and last occurence in descending sorted array of 0 & 1
        
        // if first element is 1, then first occurence is 0
        // else there is no 1 in the array
        
        int n = mat[0].size();
        vector <vector <int>> v;
        for(int i = 0 ; i < mat.size() ; i++){
            
            if(mat[i][0]==0) v.push_back(vector <int> {0,i}); //soldiers,row
            else{
                // find last occurence of 1
                int last = -1;
                int l = 0;
                int h = n-1;
                while(l <= h){
                    int m = l + (h-l)/2;
                    if(mat[i][m]==1){
                        last = m;
                        l = m+1;
                    }
                    else{
                        h = m-1;
                    }
                }
                cout<<last<<endl;
            v.push_back(vector <int> {last+1 , i});
            }
            
        }
        sort(v.begin() , v.end() , cmp);
                vector <int> soln;
                for(int i = 0 ; i < k ; i++) soln.push_back(v[i][1]);
                return soln;
        
        
        
    }
};