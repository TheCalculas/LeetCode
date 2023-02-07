//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int v[],
                                             long long int n, long long int k) {
                   
    list<long long> l;
    vector<long long> ans;
    // when any negative element appears push it in the list
    int i = 0, j = 0;
    while(j<n)
    {
        // calculation
        if(v[j]<0)
        {
            // push it 
            l.push_back(v[j]);
        }
        
        // if not in size 
        if(j-i+1<k)
        {
            // increase window size
            j++;
        }
        
        // in size
        else if(j-i+1==k)
        {
            // compute 
            auto x = l.front();
            // l.pop_front();
            ans.push_back(x);
            // now compute and move the window
            if(v[i]==l.front()) l.pop_front();
            i++;
            j++;
        }
    }
    return ans;
 }