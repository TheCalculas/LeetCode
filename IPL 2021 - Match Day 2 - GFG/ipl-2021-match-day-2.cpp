//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> v, int n, int k) {
        // your code here
        int i = 0, j = 0;
        list<int> li;
        vector<int> ans;
        while(j<n)
        {
            // do calculations
            if(li.size()==0) li.push_back(v[j]);
            else{
                while(li.size()&&li.back()<v[j]) li.pop_back();
                li.push_back(v[j]);
            }
            // 
            if(j-i+1<k)
            {
                j++;
                
            }
            else{
                // window size is hit
                // calculation
                ans.push_back(li.front());
                if(li.front()==v[i])
                {
                    li.pop_front();
                }
                i++;
                j++;
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

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends