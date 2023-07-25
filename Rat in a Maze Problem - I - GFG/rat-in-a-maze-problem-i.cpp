//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // create a funciton for depth first search in the following matrix
    void f(vector<vector<int>>& v, int x, int y, string &s, vector<string> &vs)
    {
        // check if it is out of bounds
        if(x<0||y<0||x>=v.size()||y>=v[0].size()) return;
        if(v[x][y]!=1) return;
        if(x==v.size()-1&&y==v[0].size()-1) vs.push_back(s);
        // marked as visited
        v[x][y]= 0;
        vector<int> a = {0, 1, 0, -1};
        vector<int> b = {1, 0, -1, 0};
        for(int i = 0; i<4; i++)
        {
            if(a[i]==0&&b[i]==1) s.push_back('R');
            if(a[i]==0&&b[i]==-1) s.push_back('L');
            if(a[i]==-1&&b[i]==0) s.push_back('U');
            if(a[i]==1&&b[i]==0) s.push_back('D');
            f(v, x+a[i], y + b[i], s, vs);
            s.pop_back();
        }
        v[x][y] = 1;
        
    }
    vector<string> findPath(vector<vector<int>> &v, int n) {
        // Your code goes here
        vector<string> vs;
        int x = 0, y =0;
        string s = "";
        f(v, x, y, s, vs);
        return vs;
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