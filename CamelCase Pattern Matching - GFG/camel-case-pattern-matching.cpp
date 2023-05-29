//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int n, vector<string> d, string p) {
        // code here
        vector<string> res;
        unordered_map<string, vector<int>> mp;
        for(int i =0; i<n; i++)
        {
            string s = d[i];
            string r = "";
            for(auto x: s)
            {
                if(x>='A'&&x<='Z') r.push_back(x);
            }
            if(r.substr(0, p.size())==p) res.push_back(s);
        }
        if(res.size()==0) return {"-1"};
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends