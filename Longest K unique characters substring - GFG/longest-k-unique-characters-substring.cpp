//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int mx  = -1;
        int i  = 0, j = 0;
        unordered_map<char, int> mp;
        while(j<s.size())
        {
            // add in the map calculations
            mp[s[j]]++;
            // checking
            if(mp.size()<k)
            {
                j++;
            }
            else if(mp.size()==k)
            {
                // agar condition fullfill hoti hai tohh
                mx = max(mx, j-i+1);
                // abh remove karo i ko aur j++ kardo
                // mp[s[i]]--;
                // if(mp[s[i]]==0)
                // {
                //     mp.erase(s[i]);
                // }
                // i++;
                j++;
            }
            else{
                // if the mp.size is more than k then
                while(mp.size()>k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends