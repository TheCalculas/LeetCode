//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool f(vector<vector<int>>&v, int n, int x, int y,
        string s, vector<string> &res)
    {
        if(x<0||y<0||x>=n||y>=n) return false;
        if(x==n-1&&y==n-1)
        {
            if(v[x][y]==0) return false;
            res.push_back(s);
            return true;
        }
        
        
        // sare paths dekhlo bhenchod
        if(v[x][y]==0) return false;
        
        // vector<vector<int>> a = {{0
        v[x][y] = 0;
        // for(int i = 0; i<4; i++)
        // {
            
        // }
        bool ff = false;
        s.push_back('D');
        ff = ff|f(v, n, x+1, y, s, res);
        s.pop_back();
        
        s.push_back('U');
        ff = ff|f(v, n, x-1, y, s, res);
        s.pop_back();
        
        s.push_back('L');
        ff = ff|f(v, n, x, y-1, s, res);
        s.pop_back();
        
        s.push_back('R');
        ff = ff|f(v, n, x, y+1, s, res);
        s.pop_back();
        
        v[x][y] = 1;
        return ff;
    }
    vector<string> findPath(vector<vector<int>> &v, int n) {
        // Your code goes here
        vector<string> res;
        string s ="";
        if(f(v, n, 0, 0, s, res))
        return res;
        else return {"-1"};
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends