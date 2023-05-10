//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int k,vector<int> &v){
        // Code here
        vector<int> pref(N+1, 0), surf(N+1, 0);
        for(int i=0; i<N; i++)
        {
            pref[i+1] = max(pref[i], v[i]);
        }
        for(int i = N-1; i>=0; i--)
        {
            if(i!=N-1)
            surf[i] = min(surf[i+1], v[i]);
            else surf[i] = v[i];
        }
        
        int cuts = 0;
        for(int i = 1; i<N; i++)
        {
            // cout<<"pref: "<<pref[i]<<" surf[i] "<<surf[i]<<endl;
            int a = (pref[i]);
            int b= surf[i];
            if(a+b>=k) cuts++;
        }
        return cuts;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends