//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string s) {
    int a = 0;
    int b  = 0;
    for(int i =0;i<s.size(); i++)
    {
        if(i==0)
        {
            // init
            if(s[i]=='a') a++;
            else b++;
            continue;
        }
        if(s[i]==s[i-1]) continue;
        if(s[i]=='a') a++;
        else b++;
    }
    return min(a, b)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends