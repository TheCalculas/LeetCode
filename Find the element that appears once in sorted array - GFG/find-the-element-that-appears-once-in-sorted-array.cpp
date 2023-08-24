//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int v[], int n)
    {
        //code here.
        int l = 0;
        int h = n-1;
        int ans = -1;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            
            if(mid%2==0)
            {
                // check if the left and itself are equal
                if(v[mid]==v[mid+1])
                {
                    // it is in the right
                    l = mid+1;
                }
                else{
                    // it is in the left lawl 
                    h = mid-1;
                    // ans = v[h];
                }
            }
            else if(mid%2==1)
            {
                if(v[mid]==v[mid-1])
                {
                    l = mid+1;
                }
                else {
                    h = mid-1;
                    // ans = v[h];
                }
            }
        }
        return v[l];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends