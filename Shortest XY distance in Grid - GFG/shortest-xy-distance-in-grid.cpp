//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        // code here
        vector<pair<int,int>> x,y;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(grid[i][j]=='X') x.push_back({i,j});
               else if(grid[i][j]=='Y')y.push_back({i,j});
            }
        }
        
        // sort(x.begin(),x.end());
        // sort(y.begin(),y.end());
        int ans=1e9;
        for(auto it:x)
        {
            for(in:y)
            {
               int dis=abs(it.first-in.first) + abs(it.second-in.second);
               if(dis==1)return dis;
               
               ans=min(ans,dis);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends